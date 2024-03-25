import pyrealsense2 as rs
import numpy as np
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import FruitDepth


class DepthPublisherNode(Node):
    def __init__(self):
        super().__init__('camera_depth_node')
        self.publisher = self.create_publisher(FruitDepth, 'Fruit_Depth', 10)
        timer_period = 0.4  # seconds
        self.timer = self.create_timer(timer_period, self.process_frames)
        self.frame_height = 480
        self.frame_width = 640
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

    def get_area_depth(self, depth_image):
        depth = 0
        num = 0
        num_coord = 0
        for x, y in self.get_coordinates():
            num_coord += 1
            if depth_image[y, x] >= 10:
                depth += depth_image[y, x]
                num += 1

        if num > num_coord * 0.2 and num > 0:
            return depth / num
        else:
            return None

    def get_coordinates(self):
        # Machine learning
        a = [x for x in range(320, 340, 1)]
        b = [y for y in range(230, 250, 1)]
        return ([x, y] for x, y in zip(a, b))

    def process_frames(self):
        frames = self.pipe.wait_for_frames()
        depth_frame = frames.get_depth_frame()
        color_frame = frames.get_color_frame()

        depth_image = np.asanyarray(depth_frame.get_data())
        color_image = np.asanyarray(color_frame.get_data())  # Add machine learning

        msg = FruitDepth()
        # depth_cm = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.5), cv2.COLORMAP_JET)
        # cv2.imshow('Color Image', color_image)
        # cv2.imshow('Depth Image', depth_cm)

    def __del__(self):
        self.pipe.stop()
        self.destroy_node()


def main(args=None):
    rclpy.init(args=args)
    depth_publisher = DepthPublisherNode()
    rclpy.spin(depth_publisher)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
