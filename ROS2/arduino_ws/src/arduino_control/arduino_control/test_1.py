import cv2
import numpy as np
import pyrealsense2 as rs
from ultralytics import YOLO

# Initialize RealSense pipeline
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)  # Enable depth stream
pipeline.start(config)

model = YOLO(r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/7_jan_palm_oil.pt")
DETECTED_FRAME_PATH = "/home/px/arduino_ws/src/arduino_control/arduino_control/ML/detected_frame.jpg"


def palm_oil_detection():
    while True:
        # Wait for the next set of frames
        frames = pipeline.wait_for_frames()

        # Get color and depth frames from RealSense camera
        color_frame = frames.get_color_frame()
        depth_frame = frames.get_depth_frame()

        if not color_frame or not depth_frame:
            continue

        # Convert RealSense color frame to numpy array
        color_image = np.asanyarray(color_frame.get_data())

        # Process the frames to detect palm oil objects
        process_frame(color_image, depth_frame)


def process_frame(color_frame, depth_frame):
    predictions = model.predict(color_frame, conf=0.75)

    coordinates = predictions[0].boxes.xywh.tolist()
    for pts in coordinates:
        pts[0] = int(pts[0] - pts[2] / 2)
        pts[1] = int(pts[1] - pts[3] / 2)
        cv2.rectangle(color_frame, (int(pts[0]), int(pts[1])), (int(pts[0] + pts[2]), int(pts[1] + pts[3])), (0, 255, 0), 2)
        cv2.putText(color_frame, 'palm oil', (pts[0], pts[1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 3, cv2.LINE_AA)

    # Display color frame with bounding boxes around detected objects
    cv2.imshow('prediction', color_frame)
    cv2.imwrite(DETECTED_FRAME_PATH, color_frame)
    cv2.waitKey(1)

    # Process depth frame and visualize it alongside the color frame
    depth_colormap = cv2.applyColorMap(cv2.convertScaleAbs(np.asanyarray(depth_frame.get_data()), alpha=0.03), cv2.COLORMAP_JET)

    # Print depth at specific coordinates
    depth_data = np.asanyarray(depth_frame.get_data())
    depth_values = depth_data[180:221, 300:341]
    mean_depth = np.mean(depth_values)
    print("Mean depth:", mean_depth)

    cv2.imshow('Depth Frame', depth_colormap)
    cv2.waitKey(1)


if __name__ == "__main__":
    palm_oil_detection()
