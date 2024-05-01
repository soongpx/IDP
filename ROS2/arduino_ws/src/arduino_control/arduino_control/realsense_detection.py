import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
import pyrealsense2 as rs
from ultralytics import YOLO  # Assuming you have installed the ultralytics library

class RealSenseNode(Node):
    def __init__(self):
        super().__init__('realsense_detection')
        self.bridge = CvBridge()
        self.model = YOLO(r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/7_jan_palm_oil.pt")  # Replace with the path to your detection model

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
                    # Apply color map to depth image
                    depth_colormap = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), cv2.COLORMAP_JET)
                
                    color_image = np.array(color_frame.get_data())

                    # Perform detection on the color image
                    predictions = self.model.predict(color_image, conf=0.75)
                    coordinates = predictions[0].boxes.xywh.tolist()
                    # Draw bounding boxes on the color image
                    

                    for pts in coordinates:
                        # Extract x, y, width, and height
                        x, y, width, height = int(pts[0]), int(pts[1]), int(pts[2]), int(pts[3])

                        pts[0] = int(pts[0] - pts[2] / 2)
                        pts[1] = int(pts[1] - pts[3] / 2)
                        cv2.rectangle(color_image, (int(pts[0]), int(pts[1])), (int(pts[0] + pts[2]), int(pts[1] + pts[3])),
                                    (0, 255, 0), 2)
                        cv2.putText(color_image, 'palm oil', (pts[0], pts[1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 3,
                                    cv2.LINE_AA)
                        
                    # Display color and depth images
                    self.get_logger().info("Detected")
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
