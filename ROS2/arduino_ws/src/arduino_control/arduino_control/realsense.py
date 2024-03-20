import pyrealsense2 as rs
import numpy as np
import cv2
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import FruitDepth

class DepthPublisherNode(Node):
    def __init__(self):
        super().__init__('camera_depth_node')
        self.publisher = self.create_publisher(FruitDepth, 'Fruit_Depth', 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.process_frames)
        self.pipe = rs.pipeline()
        self.cfg = rs.config()
        self.cfg.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
        self.cfg.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        self.pipe.start(self.cfg)

    def get_area_depth(self, depth_image):
        depth = 0
        num = 0
        num_coord = 0
        for x, y in self.get_coordinates():
            num_coord += 1
            if depth_image[y, x] >= 10:
                depth += depth_image[y, x]
                num += 1

        if num > num_coord*0.2 and num > 0:
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
        color_image = np.asanyarray(color_frame.get_data()) # Add machine learning

        depth_value = self.get_area_depth(depth_image)

        if depth_value is not None:
            depth_msg = FruitDepth()
            depth_msg.detected = True
            depth_msg.depth = depth_value
            self.get_logger().info(f"{depth_value} mm is detected")
            self.publisher.publish(depth_msg)
        else: 
            depth_msg = FruitDepth()
            depth_msg.detected = False
            depth_msg.depth = float(0)
            self.get_logger().warn("No frame is detected")
            self.publisher.publish(depth_msg)


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
