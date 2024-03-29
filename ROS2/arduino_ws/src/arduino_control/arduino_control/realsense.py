import pyrealsense2 as rs
import numpy as np
import cv2
import math
from ultralytics import YOLO
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import FruitDepth


class Points:
    x = 0
    y = 0
    z = 0


class DepthPublisherNode(Node):
    def __init__(self):
        super().__init__('camera_depth_node')
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
        self.confidence = 0.5
        self.color = (0, 255, 0)  # Green color in BGR
        self.FOV_V = 58  # RGB
        self.FOV_H = 87  # RGB
        self.RES_V = 640
        self.RES_H = 480
        self.thickness = 1
        self.detected_palm_oil = False
        self.palm_oil_num = 0

        # Variables for frame processing
        self.depth_frame = None
        self.color_frame = None
        self.color_image = None
        self.color_intrinsic = None

        # Variables for orientation
        self.pitch_angle = 0
        self.yaw_angle = 0
        self.pitch = 0
        self.yaw = 0
        self.target_pitch = 0
        self.target_yaw = 0
        self.pitch1 = 0
        self.yaw1 = 0
        self.current_pitch = 0
        self.current_yaw = 0
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

    def process_frames(self):
        self.frames = self.pipe.wait_for_frames()
        if not self.detected_palm_oil:
            self.depth_frame = self.frames.get_depth_frame()
            self.color_frame = self.frames.get_color_frame()
            self.color_intrinsic = self.color_frame.profile.as_video_stream_profile().intrinsics
            # depth_image = np.asanyarray(self.depth_frame.get_data())
            self.color_image = np.asanyarray(self.color_frame.get_data())  # Add machine learning
            self.process_frame()  # self.palm_oil_num, self.detected_palm_oil
        else:
            if self.first_detected:
                self.get_target_imu_data()  # self.target_pitch, self.target_yaw
                self.target_yaw += self.yaw_angle
                self.target_pitch += self.pitch_angle
                self.first_detected = False
            elif self.pitch_direction == 0 and self.yaw_direction == 0:
                self.detected_palm_oil = False
                self.first_detected = True
                self.pitch_direction = 0
                self.yaw_direction = 0
            else:
                self.get_imu_data()
            print((self.current_pitch - self.target_pitch))
            print((self.current_yaw - self.target_yaw))
            if (self.current_pitch - self.target_pitch) > 2:
                self.pitch_direction = 1
            elif (self.current_pitch - self.target_pitch) < -2:
                self.pitch_direction = -1
            else:
                self.pitch_direction = 0
            if (self.current_yaw - self.target_yaw) > 2:
                self.yaw_direction = 1
            elif (self.current_yaw - self.target_yaw) < -2:
                self.yaw_direction = -1
            else:
                self.yaw_direction = 0

        # cv2.imshow('RGB Image', self.color_image)
        msg = FruitDepth()
        msg.detected = self.detected_palm_oil
        msg.palm_oil_num = self.palm_oil_num
        msg.yaw_direction = self.yaw_direction
        msg.pitch_direction = self.pitch_direction
        self.get_logger().info(f"{msg.detected}, {msg.palm_oil_num}, {msg.yaw_direction}, {msg.pitch_direction}")
        self.publisher.publish(msg)
        # depth_cm = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.5), cv2.COLORMAP_JET)
        # cv2.imshow('Color Image', color_image)
        # cv2.imshow('Depth Image', depth_cm)

    def calc_yaw_angle(self, pt1_x, pt1_y, center_x, center_y):
        vertical = (center_y - pt1_y)
        horizontal = (pt1_x - center_x)

        self.pitch_angle = (self.FOV_V / self.RES_V) * vertical
        self.yaw_angle = (self.FOV_H / self.RES_H) * horizontal
        print(self.pitch_angle)
        print(self.yaw_angle)

    def process_frame(self):
        self.detected_palm_oil = False
        predictions = self.model.predict(self.color_image, conf=self.confidence)
        depth_arr = []
        coordinates = predictions[0].boxes.xywh.tolist()
        height, width, _ = self.color_image.shape

        # draw crosshair
        # crosshair_center = (int(width * self.crosshair_x_offset), int(height * self.crosshair_y_offset))
        # Draw horizontal line (crosshair)
        # cv2.line(self.color_image, (0, int(height * self.crosshair_y_offset)),
        #          (width, int(height * self.crosshair_y_offset)), self.color,
        #          self.thickness)
        # # Draw vertical line (crosshair)
        # cv2.line(self.color_image, (int(width * self.crosshair_x_offset), 0),
        #          (int(width * self.crosshair_x_offset), height), self.color,
        #          self.thickness)

        for pts in coordinates:
            # Extract x, y, width, and height
            x, y, width, height = int(pts[0]), int(pts[1]), int(pts[2]), int(pts[3])

            # Calculate center
            center_x = x + width // 2
            center_y = y + height // 2

            # # Draw center point
            # cv2.circle(self.color_image, (center_x, center_y), 5, (0, 0, 255), -1)

            # Get depth value at the center point
            depth_value = self.depth_frame.get_distance(center_x, center_y)

            # # Convert depth value to meaningful units (e.g., meters) using depth scale
            # depth_meters = depth_value
            # depth_text = "{:.2f}m".format(depth_meters)
            Points.x = center_x
            Points.y = center_y
            Points.z = depth_value
            # cv2.putText(self.color_image, depth_text, (center_x, center_y), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 1,
            #             cv2.LINE_AA)
            # cv2.circle(self.color_image, (center_x, center_y), 5, (0, 0, 255), -1)
            # cv2.rectangle(self.color_image, (x, y), (x + width, y + height), (0, 255, 0), 2)
            # cv2.putText(self.color_image, 'palm oil', (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 3, cv2.LINE_AA)
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
        # cv2.circle(self.color_image, (closest_pt.x, closest_pt.y), 5, (0, 0, 255), -1)
        if closest_depth < 100:
            height, width, _ = self.color_image.shape
            # Draw rectangle and text on the self.color_image
            print(f"x: {closest_pt.x}, y: {closest_pt.y}, z:{closest_pt.z}")
            self.calc_yaw_angle(closest_pt.x, closest_pt.y, int(width * 0.47), int(height * 0.7))
            # cv2.line(self.color_image, crosshair_center, (closest_pt.x, closest_pt.y), (0, 0, 255), 5)
            self.detected_palm_oil = True
            print(f"Closest Depth: {closest_depth}")

        # Save the frame with detections
        cv2.imwrite(self.DETECTED_FRAME_PATH, self.color_image)

    def get_target_imu_data(self):
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
                    self.yaw += gyro_data.z * self.dt

                    # Compensate for drift using accelerometer data
                    pitch_acc = np.arctan2(accel_data.y, np.sqrt(accel_data.x ** 2 + accel_data.z ** 2))
                    yaw_acc = np.arctan2(accel_data.x, np.sqrt(accel_data.y ** 2 + accel_data.z ** 2))

                    self.pitch = self.beta * (self.pitch + gyro_data.x * self.dt) + (1 - self.beta) * pitch_acc
                    self.yaw = self.beta * (self.yaw + gyro_data.z * self.dt) + (1 - self.beta) * yaw_acc

                    # Convert angles to degrees
                    self.target_pitch = np.degrees(self.pitch)
                    self.target_yaw = np.degrees(self.yaw)
                    #
                    # print("Pitch:", pitch_deg)
                    # print("Yaw:", yaw_deg)

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
                    self.pitch1 += gyro_data.x * self.dt
                    self.yaw1 += gyro_data.z * self.dt

                    # Compensate for drift using accelerometer data
                    pitch_acc = np.arctan2(accel_data.y, np.sqrt(accel_data.x ** 2 + accel_data.z ** 2))
                    yaw_acc = np.arctan2(accel_data.x, np.sqrt(accel_data.y ** 2 + accel_data.z ** 2))

                    self.pitch1 = self.beta * (self.pitch1 + gyro_data.x * self.dt) + (1 - self.beta) * pitch_acc
                    self.yaw1 = self.beta * (self.yaw1 + gyro_data.z * self.dt) + (1 - self.beta) * yaw_acc

                    # Convert angles to degrees
                    self.current_pitch = np.degrees(self.pitch1)
                    self.current_yaw = np.degrees(self.yaw1)
                    #
                    # print("Pitch:", pitch_deg)
                    # print("Yaw:", yaw_deg)

    def __del__(self):
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
