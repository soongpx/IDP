import pyrealsense2 as rs
import numpy as np
import cv2
from ultralytics import YOLO
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import FruitDepth


class Point:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z


class DepthPublisherNode(Node):
    def __init__(self):
        super().__init__('camera_depth_node')
        self.publisher = self.create_publisher(FruitDepth, 'fruit_depth', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.process_frames)

        # Camera frame variables
        self.frame_height = 480
        self.frame_width = 640

        # Machine Learning variables
        self.crosshair_x_offset = 0.45
        self.crosshair_y_offset = 0.75
        self.confidence = 0.5
        self.color = (0, 255, 0)
        self.FOV_V = 58
        self.FOV_H = 87
        self.RES_V = 640
        self.RES_H = 480
        self.thickness = 1
        self.detected_palm_oil = False
        self.palm_oil_num = 0

        # Orientation variables
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

        # Sensor fusion variables
        self.dt = 1 / 200
        self.beta = 0.98

        # Camera setup
        self.pipe = rs.pipeline()
        self.cfg = rs.config()
        self.cfg.enable_stream(rs.stream.color, self.frame_width, self.frame_height, rs.format.bgr8, 30)
        self.cfg.enable_stream(rs.stream.depth, self.frame_width, self.frame_height, rs.format.z16, 30)
        self.cfg.enable_stream(rs.stream.accel, rs.format.motion_xyz32f, 100)
        self.cfg.enable_stream(rs.stream.gyro, rs.format.motion_xyz32f, 200)
        self.profile = self.pipe.start(self.cfg)
        self.depth_sensor = self.profile.get_device().first_depth_sensor()
        self.depth_scale = self.depth_sensor.get_depth_scale()
        if self.depth_scale > 0:
            self.get_logger().info("Camera opened successfully!")
        self.clipping_distance_in_meters = 4
        self.clipping_distance = self.clipping_distance_in_meters / self.depth_scale
        self.align_to = rs.stream.color
        self.align = rs.align(self.align_to)

        # Machine Learning Model
        model_path = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/7_jan_palm_oil.pt"
        self.model = YOLO(model_path)
        self.DETECTED_FRAME_PATH = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/detected_frame.jpg"

    def process_frames(self):
        frames = self.pipe.wait_for_frames()
        if not self.detected_palm_oil:
            self.process_frame(frames)
        else:
            if self.first_detected:
                self.get_target_imu_data(frames)
                self.target_yaw += self.yaw_angle
                self.target_pitch += self.pitch_angle
                self.first_detected = False
            elif self.pitch_direction == 0 and self.yaw_direction == 0:
                self.detected_palm_oil = False
                self.first_detected = True
                self.pitch_direction = 0
                self.yaw_direction = 0
            else:
                self.get_imu_data(frames)
            self.update_direction()

        msg = FruitDepth()
        msg.detected = self.detected_palm_oil
        msg.palm_oil_num = self.palm_oil_num
        msg.yaw_direction = self.yaw_direction
        msg.pitch_direction = self.pitch_direction
        self.get_logger().info(f"{msg.detected}, {msg.palm_oil_num}, {msg.yaw_direction}, {msg.pitch_direction}")
        self.publisher.publish(msg)

    def calc_yaw_angle(self, pt1_x, pt1_y, center_x, center_y):
        vertical = (center_y - pt1_y)
        horizontal = (pt1_x - center_x)

        self.pitch_angle = (self.FOV_V / self.RES_V) * vertical
        self.yaw_angle = (self.FOV_H / self.RES_H) * horizontal

    def process_frame(self, frames):
        aligned_frames = self.align.process(frames)
        depth_frame = aligned_frames.get_depth_frame()
        color_frame = aligned_frames.get_color_frame()
        color_image = np.asanyarray(color_frame.get_data())

        self.detected_palm_oil = False
        predictions = self.model.predict(color_image, conf=self.confidence)
        depth_arr = []
        coordinates = predictions[0].boxes.xywh.tolist()
        height, width, _ = color_image.shape

        for pts in coordinates:
            x, y, width, height = int(pts[0]), int(pts[1]), int(pts[2]), int(pts[3])
            center_x = x + width // 2
            center_y = y + height // 2
            depth_value = depth_frame.get_distance(center_x, center_y)
            depth_arr.append(Point(center_x, center_y, depth_value))

        self.palm_oil_num = len(depth_arr)
        closest_pt = min(depth_arr, key=lambda p: p.z if p.z != 0 else float('inf'))
        if closest_pt.z < 100:
            self.calc_yaw_angle(closest_pt.x, closest_pt.y, int(width * 0.47), int(height * 0.7))
            self.detected_palm_oil = True
            print(f"Closest Depth: {closest_pt.z}")

        cv2.imwrite(self.DETECTED_FRAME_PATH, color_image)

    def get_target_imu_data(self, frames):
        accel_data = None
        for frame in frames:
            if frame.is_motion_frame():
                if frame.get_profile().stream_type() == rs.stream.accel:
                    accel_data = frame.as_motion_frame().get_motion_data()
                elif frame.get_profile().stream_type() == rs.stream.gyro:
                    gyro_data = frame.as_motion_frame().get_motion_data()
                    self.pitch += gyro_data.x * self.dt
                    self.yaw += gyro_data.z * self.dt
                    if accel_data is not None:
                        pitch_acc = np.arctan2(accel_data.y, np.sqrt(accel_data.x ** 2 + accel_data.z ** 2))
                        yaw_acc = np.arctan2(accel_data.x, np.sqrt(accel_data.y ** 2 + accel_data.z ** 2))
                        self.pitch = self.beta * (self.pitch + gyro_data.x * self.dt) + (1 - self.beta) * pitch_acc
                        self.yaw = self.beta * (self.yaw + gyro_data.z * self.dt) + (1 - self.beta) * yaw_acc
                        self.target_pitch = np.degrees(self.pitch)
                        self.target_yaw = np.degrees(self.yaw)

    def get_imu_data(self, frames):
        accel_data = None
        for frame in frames:
            if frame.is_motion_frame():
                if frame.get_profile().stream_type() == rs.stream.accel:
                    accel_data = frame.as_motion_frame().get_motion_data()
                elif frame.get_profile().stream_type() == rs.stream.gyro:
                    gyro_data = frame.as_motion_frame().get_motion_data()
                    self.pitch1 += gyro_data.x * self.dt
                    self.yaw1 += gyro_data.z * self.dt
                    if accel_data is not None:
                        pitch_acc = np.arctan2(accel_data.y, np.sqrt(accel_data.x ** 2 + accel_data.z ** 2))
                        yaw_acc = np.arctan2(accel_data.x, np.sqrt(accel_data.y ** 2 + accel_data.z ** 2))
                        self.pitch1 = self.beta * (self.pitch1 + gyro_data.x * self.dt) + (1 - self.beta) * pitch_acc
                        self.yaw1 = self.beta * (self.yaw1 + gyro_data.z * self.dt) + (1 - self.beta) * yaw_acc
                        self.current_pitch = np.degrees(self.pitch1)
                        self.current_yaw = np.degrees(self.yaw1)

    def update_direction(self):
        pitch_diff = self.current_pitch - self.target_pitch
        yaw_diff = self.current_yaw - self.target_yaw
        self.pitch_direction = int(np.sign(pitch_diff)) if abs(pitch_diff) > 2 else 0
        self.yaw_direction = int(np.sign(yaw_diff)) if abs(yaw_diff) > 2 else 0

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
