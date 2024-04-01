import pyrealsense2 as rs
import numpy as np
import cv2
import math
from ultralytics import YOLO
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import FruitDepth, Imu
from my_robot_interfaces.srv import HarvestConfirmation


class Points:
    x = 0
    y = 0
    z = 0


class DepthPublisherNode(Node):
    def __init__(self):
        super().__init__('camera_depth_node')
        self.imu_subscriber = self.create_subscription(Imu, 'imu_data', self.imu_data, 10)
        self.imu_subscriber
        self.confirm_action_client = self.create_client(HarvestConfirmation, 'harvest_confirm')  # Create a service client
        self.publisher = self.create_publisher(FruitDepth, 'fruit_depth', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.process_frames)

        # Variables for Camera frame
        self.frame_height = 480
        self.frame_width = 640
        self.frames = None

        # Variables for Machine Learning
        self.crosshair_x_offset = 0.45
        self.crosshair_y_offset = 0.75
        self.confidence = 0.7
        self.color = (0, 255, 0)  # Green color in BGR
        self.FOV_V = 58  # RGB
        self.FOV_H = 87  # RGB
        self.RES_V = 640
        self.RES_H = 480
        self.thickness = 1
        self.detected_palm_oil = False
        self.fruit_depth = 0.0
        self.palm_oil_num = 0

        # Variables for frame processing
        self.depth_frame = None
        self.color_frame = None
        self.color_image = None

        # Variables for IMU
        self.yaw_angle = 0

        # Variables for harvest status
        self.harvest_end_counter = 0
        self.harvest_end = True

        # Variables for orientation
        self.pitch_angle = 0
        self.yaw_angle = 0
        self.pitch = 0
        self.yaw = 0
        self.target_pitch = 0
        self.target_yaw = 0
        self.previous_pitch = 100
        self.previous_yaw = 100
        self.angle_counter = 0
        self.first_detected = True
        self.yaw_direction = 0
        self.pitch_direction = 0

        # Variables for sensor fusion
        self.dt = 1 / 200  # Time interval (assuming gyro runs at 200 Hz)
        self.beta = 0.98  # Complementary filter coefficient

        # Starting camera setup
        self.pipe = rs.pipeline()
        self.cfg = rs.config()
        self.cfg.enable_stream(rs.stream.color, self.frame_width, self.frame_height, rs.format.bgr8, 30)
        self.cfg.enable_stream(rs.stream.depth, self.frame_width, self.frame_height, rs.format.z16, 30)
        self.cfg.enable_stream(rs.stream.accel, rs.format.motion_xyz32f, 100)  # Accelerometer data
        self.cfg.enable_stream(rs.stream.gyro, rs.format.motion_xyz32f, 200)
        self.profile = self.pipe.start(self.cfg)
        self.depth_sensor = self.profile.get_device().first_depth_sensor()
        self.depth_scale = self.depth_sensor.get_depth_scale()
        if self.depth_scale > 0:
            self.get_logger().info("Camera opened successfully!")
        self.clipping_distance_in_meters = 4  # 1 meter
        self.clipping_distance = self.clipping_distance_in_meters / self.depth_scale
        self.align_to = rs.stream.color
        self.align = rs.align(self.align_to)

        # Machine Learning Model
        model_path = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/7_jan_palm_oil.pt"
        self.model = YOLO(model_path)
        self.DETECTED_FRAME_PATH = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/detected_frame.jpg"

    def imu_data(self, msg):
        self.yaw_angle = msg.yaw

    def process_frames(self):
        self.frames = self.pipe.wait_for_frames()
        if not self.detected_palm_oil and self.harvest_end:
            if self.harvest_end:
                self.depth_frame = self.frames.get_depth_frame()
                self.color_frame = self.frames.get_color_frame()
                self.color_image = np.asanyarray(self.color_frame.get_data())
                self.process_frame()  # self.palm_oil_num, self.detected_palm_oil, self.pitch_angle, self.yaw_angle
        else:
            request = HarvestConfirmation.Request()
            future = self.confirm_action_client.call_async(request)
            if future.done() and future.result().success:
                self.harvest_end = True
            else:
                self.harvest_end = False
                self.get_imu_data()  # self.yaw_angle, self.pitch_angle
                if self.first_detected:
                    if abs(self.pitch_angle - self.previous_pitch) < 0.03 and abs(self.yaw_angle - self.previous_yaw) < 0.03:
                        self.angle_counter += 1
                        self.pitch_direction = 2
                        self.yaw_direction = 2
                        if self.angle_counter == 20:
                            self.target_yaw += self.yaw_angle
                            self.target_pitch += self.pitch_angle
                            self.first_detected = False
                            self.angle_counter = 0
                    else:
                        self.previous_pitch = self.pitch_angle
                        self.previous_yaw = self.yaw_angle
                        self.first_detected = True
                        self.pitch_direction = 2
                        self.yaw_direction = 2
                        self.angle_counter = 0
                else:
                    if (self.pitch_angle - self.target_pitch) > 2:
                        self.pitch_direction = 1
                    elif (self.pitch_angle - self.target_pitch) < -2:
                        self.pitch_direction = -1
                    else:
                        self.pitch_direction = 0

                    if (self.yaw_angle - self.target_yaw) > 2:
                        self.yaw_direction = 1
                    elif (self.yaw_angle - self.target_yaw) < -2:
                        self.yaw_direction = -1
                    else:
                        self.yaw_direction = 0

                    if self.pitch_direction == 0 and self.yaw_direction == 0:
                        self.detected_palm_oil = False
                        self.first_detected = True

                    print(str(self.target_yaw) + " , " + str(self.target_pitch))
                    print(str(self.yaw_angle) + " , " + str(self.pitch_angle))

        msg = FruitDepth()
        msg.detected = self.detected_palm_oil
        msg.palm_oil_num = self.palm_oil_num
        msg.fruit_depth = self.fruit_depth
        msg.yaw_direction = self.yaw_direction
        msg.pitch_direction = self.pitch_direction
        msg.pitch = float(self.pitch_angle)
        msg.yaw = float(self.yaw_angle)
        self.get_logger().info(f"{msg.detected}, {msg.palm_oil_num}, {msg.fruit_depth}, {msg.yaw_direction}, {msg.pitch_direction}, {msg.pitch}, {msg.yaw}")
        self.publisher.publish(msg)

    def calc_pitch_angle(self, pt1_x, pt1_y, center_x, center_y):
        vertical = (center_y - pt1_y)
        horizontal = (pt1_x - center_x)

        self.target_pitch = (self.FOV_V / self.RES_V) * vertical
        print(self.target_pitch)
        self.target_yaw = (self.FOV_H / self.RES_H) * horizontal

    def process_frame(self):
        self.detected_palm_oil = False
        predictions = self.model.predict(self.color_image, conf=self.confidence)
        depth_arr = []
        coordinates = predictions[0].boxes.xywh.tolist()
        height, width, _ = self.color_image.shape

        for pts in coordinates:
            # Extract x, y, width, and height
            x, y, width, height = int(pts[0]), int(pts[1]), int(pts[2]), int(pts[3])

            # Calculate center
            center_x = x + width // 2
            center_y = y + height // 2

            # Get depth value at the center point
            depth_value = self.depth_frame.get_distance(center_x, center_y)

            Points.x = center_x
            Points.y = center_y
            Points.z = depth_value
            print("Depth at center point:", depth_value, "meters")
            depth_arr.append(Points)

        self.palm_oil_num = len(depth_arr)
        closest_pt = Points()
        closest_depth = 100
        for pts in depth_arr:
            if pts.z < closest_depth and pts.z != 0:
                closest_depth = pts.z
                closest_pt.x = pts.x
                closest_pt.y = pts.y
                closest_pt.z = pts.z
        if closest_depth < 100:
            height, width, _ = self.color_image.shape
            print(f"x: {closest_pt.x}, y: {closest_pt.y}, z:{closest_pt.z}")
            self.calc_pitch_angle(closest_pt.x, closest_pt.y, int(width * 0.47), int(height * 0.7))
            self.detected_palm_oil = True
            self.fruit_depth = closest_depth
            print(f"Closest Depth: {closest_depth}")

        # Save the frame with detections
        # cv2.imwrite(self.DETECTED_FRAME_PATH, self.color_image)

    def get_imu_data(self):
        accel_data = None
        for frame in self.frames:
            if frame.is_motion_frame():
                if frame.get_profile().stream_type() == rs.stream.accel:
                    # Extract accelerometer data
                    accel_data = frame.as_motion_frame().get_motion_data()

                elif frame.get_profile().stream_type() == rs.stream.gyro:
                    # Extract gyroscope data
                    gyro_data = frame.as_motion_frame().get_motion_data()

                    # Perform sensor fusion (complementary filter)
                    self.pitch += gyro_data.x * self.dt

                    # Compensate for drift using accelerometer data
                    pitch_acc = np.arctan2(accel_data.y, np.sqrt(accel_data.x ** 2 + accel_data.z ** 2))

                    self.pitch = self.beta * (self.pitch + gyro_data.x * self.dt) + (1 - self.beta) * pitch_acc

                    # Convert angles to degrees
                    # self.target_pitch = np.degrees(self.pitch)
                    # self.target_yaw = np.degrees(self.yaw)
                    self.pitch_angle = np.degrees(self.pitch)
                    #
                    # print("Pitch:", pitch_deg)
                    # print("Yaw:", yaw_deg)

    # def get_imu_data(self):
    #     accel_data = None
    #     for frame in self.frames:
    #         if frame.is_motion_frame():
    #             if frame.get_profile().stream_type() == rs.stream.accel:
    #                 # Extract accelerometer data
    #                 accel_data = frame.as_motion_frame().get_motion_data()
    #
    #             elif frame.get_profile().stream_type() == rs.stream.gyro:
    #                 # Extract gyroscope data
    #                 gyro_data = frame.as_motion_frame().get_motion_data()
    #
    #                 # Perform sensor fusion (complementary filter)
    #                 self.pitch1 += gyro_data.x * self.dt
    #                 self.yaw1 += gyro_data.z * self.dt
    #
    #                 # Compensate for drift using accelerometer data
    #                 pitch_acc = np.arctan2(accel_data.y, np.sqrt(accel_data.x ** 2 + accel_data.z ** 2))
    #                 yaw_acc = np.arctan2(accel_data.x, np.sqrt(accel_data.y ** 2 + accel_data.z ** 2))
    #
    #                 self.pitch1 = self.beta * (self.pitch1 + gyro_data.x * self.dt) + (1 - self.beta) * pitch_acc
    #                 self.yaw1 = self.beta * (self.yaw1 + gyro_data.z * self.dt) + (1 - self.beta) * yaw_acc
    #
    #                 # Convert angles to degrees
    #                 self.current_pitch = np.degrees(self.pitch1)
    #                 self.current_yaw = np.degrees(self.yaw1)
    #                 #
    #                 # print("Pitch:", pitch_deg)
    #                 # print("Yaw:", yaw_deg)

    def __del__(self):
        if self.pipe is not None:
            self.pipe.stop()
        self.destroy_node()
        cv2.destroyAllWindows()


def main(args=None):
    rclpy.init(args=args)
    depth_publisher = DepthPublisherNode()
    rclpy.spin(depth_publisher)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
