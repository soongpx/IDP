import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
import pyrealsense2 as rs

class RealSenseNode(Node):
    def __init__(self):
        super().__init__('realsense')
        self.bridge = CvBridge()

        # Create a pipeline
        self.pipeline = rs.pipeline()

        # Configure streams
        config = rs.config()
        config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)

        # Start streaming
        self.pipeline.start(config)

    def capture_frames(self):
        try:
            while True:
                # Wait for a coherent pair of frames: depth and color
                frames = self.pipeline.wait_for_frames()
                depth_frame = frames.get_depth_frame()
                color_frame = frames.get_color_frame()

                # If both frames are available, proceed
                if depth_frame and color_frame:
                    # Convert depth and color frames to numpy arrays
                    depth_image = np.array(depth_frame.get_data())
                    color_image = np.array(color_frame.get_data())
                    
                    # Apply color map to depth image
                    depth_colormap = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), cv2.COLORMAP_JET)

                    # Display color and depth images
                    cv2.imshow('Color Image', color_image)
                    cv2.imshow('Depth Image', depth_colormap)
                    cv2.waitKey(1)

        except KeyboardInterrupt:
            pass

    def __del__(self):
        # Stop streaming
        self.pipeline.stop()
        cv2.destroyAllWindows()

def main(args=None):
    rclpy.init(args=args)

    try:
        node = RealSenseNode()
        node.capture_frames()
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
