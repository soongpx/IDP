import pyrealsense2 as rs
import numpy as np
import cv2
import math
from ultralytics import YOLO


class Points:
    x = 0
    y = 0
    z = 0


crosshair_x_offset = 0.45
crosshair_y_offset = 0.75
confidence = 0.35
color = (0, 255, 0)  # Green color in BGR
FOV_V = 58  # RGB
FOV_H = 87  # RGB
RES_V = 640
RES_H = 480
thickness = 1
detected_palm_oil = False
# Variables for orientation
pitch = 0
yaw = 0
# Variables for sensor fusion
dt = 1 / 200  # Time interval (assuming gyro runs at 200 Hz)
beta = 0.98  # Complementary filter coefficient

# Initialize the RealSense pipeline
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
config.enable_stream(rs.stream.accel, rs.format.motion_xyz32f, 100)  # Accelerometer data
config.enable_stream(rs.stream.gyro, rs.format.motion_xyz32f, 200)  # Gyroscope data

# Start streaming
profile = pipeline.start(config)

# align the depth with the rgb image
# Getting the depth sensor's depth scale
depth_sensor = profile.get_device().first_depth_sensor()
depth_scale = depth_sensor.get_depth_scale()
print("Depth Scale is: ", depth_scale)

clipping_distance_in_meters = 4  # 1 meter
clipping_distance = clipping_distance_in_meters / depth_scale
align_to = rs.stream.color
align = rs.align(align_to)
# model_path = r"C:\Users\ASUS\Documents\GitHub\IDP\ML\model\7_jan_palm_oil.pt"
model_path = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/best.pt"

model = YOLO(model_path)
DETECTED_FRAME_PATH = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/detected_frame.jpg"
CLOSEST_FRAME_PATH = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/detected_frame.jpg"


def calc_yaw_angle(pt1_x, pt1_y, center_x, center_y):
    vertical = (center_y - pt1_y)
    horizontal = (pt1_x - center_x)

    pitch_angle = (FOV_V / RES_V) * vertical
    yaw_angle = (FOV_H / RES_H) * horizontal
    return yaw_angle, pitch_angle


def process_frame(frame, conf_val):
    global color, thickness
    detected = False
    predictions = model.predict(frame, conf=conf_val)
    aligned_frames = align.process(frames)
    depth_frame = aligned_frames.get_depth_frame()  # aligned_depth_frame is a 640x480 depth image
    depth_arr = []
    coordinates = predictions[0].boxes.xywh.tolist()
    height, width, _ = frame.shape
    angles = (0,0)

    # draw crosshair
    crosshair_center = (int(width * crosshair_x_offset), int(height * crosshair_y_offset))
    # Draw horizontal line (crosshair)
    cv2.line(frame, (0, int(height * crosshair_y_offset)), (width, int(height * crosshair_y_offset)), color, thickness)
    # Draw vertical line (crosshair)
    cv2.line(frame, (int(width * crosshair_x_offset), 0), (int(width * crosshair_x_offset), height), color, thickness)

    for pts in coordinates:
        # Extract x, y, width, and height
        x, y, width, height = int(pts[0]), int(pts[1]), int(pts[2]), int(pts[3])

        # Calculate center
        center_x = x + width // 2
        center_y = y + height // 2

        # Draw center point
        cv2.circle(frame, (center_x, center_y), 5, (0, 0, 255), -1)

        # Get depth value at the center point
        depth_value = depth_frame.get_distance(center_x, center_y)

        # Convert depth value to meaningful units (e.g., meters) using depth scale
        depth_meters = depth_value
        depth_text = "{:.2f}m".format(depth_meters)
        Points.x = center_x
        Points.y = center_y
        Points.z = depth_meters
        cv2.putText(frame, depth_text, (center_x, center_y), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 1, cv2.LINE_AA)
        cv2.circle(frame, (center_x, center_y), 5, (0, 0, 255), -1)
        cv2.rectangle(frame, (x, y), (x + width, y + height), (0, 255, 0), 2)
        cv2.putText(frame, 'palm oil', (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 3, cv2.LINE_AA)
        print("Depth at center point:", depth_meters, "meters")
        depth_arr.append(Points)

    palm_oil_num = len(depth_arr)
    closest_pt = Points()
    closest_depth = 100
    for pts in depth_arr:
        if pts.z < closest_depth and pts.z != 0:
            closest_depth = pts.z
            closest_pt.x = pts.x
            closest_pt.y = pts.y
            closest_pt.z = pts.z
    cv2.circle(frame, (closest_pt.x, closest_pt.y), 5, (0, 0, 255), -1)
    if closest_depth < 100:
        height, width, _ = frame.shape
        # Draw rectangle and text on the frame
        print(f"x: {closest_pt.x}, y: {closest_pt.y}, z:{closest_pt.z}")
        angles = (calc_yaw_angle(closest_pt.x, closest_pt.y, int(width * 0.47), int(height * 0.7)))
        cv2.line(frame, crosshair_center, (closest_pt.x, closest_pt.y), (0, 0, 255), 5)
        print(angles)
        detected = True
        print(f"Closest Depth: {closest_depth}")

    # Save the frame with detections
    cv2.imwrite(DETECTED_FRAME_PATH, frame)

    return frame, detected, angles, palm_oil_num


def getIMUdata(frames):
    global pitch, yaw, beta, dt
    pitch_deg = 0
    yaw_deg = 0
    for frame in frames:
        if frame.is_motion_frame():
            if frame.get_profile().stream_type() == rs.stream.accel:
                # Extract accelerometer data
                accel_data = frame.as_motion_frame().get_motion_data()

            elif frame.get_profile().stream_type() == rs.stream.gyro:
                # Extract gyroscope data
                gyro_data = frame.as_motion_frame().get_motion_data()

                # Perform sensor fusion (complementary filter)
                pitch += gyro_data.x * dt
                yaw += gyro_data.z * dt

                # Compensate for drift using accelerometer data
                pitch_acc = np.arctan2(accel_data.y, np.sqrt(accel_data.x ** 2 + accel_data.z ** 2))
                yaw_acc = np.arctan2(accel_data.x, np.sqrt(accel_data.y ** 2 + accel_data.z ** 2))

                pitch = beta * (pitch + gyro_data.x * dt) + (1 - beta) * pitch_acc
                yaw = beta * (yaw + gyro_data.z * dt) + (1 - beta) * yaw_acc

                # Convert angles to degrees
                pitch_deg = np.degrees(pitch)
                yaw_deg = np.degrees(yaw)
                #
                # print("Pitch:", pitch_deg)
                # print("Yaw:", yaw_deg)

    return pitch_deg, yaw_deg


try:
    while True:
        # Wait for the next set of frames
        frames = pipeline.wait_for_frames()
        color_frame = frames.get_color_frame()

        color_intrin = color_frame.profile.as_video_stream_profile().intrinsics
        # Convert frames to numpy arrays
        color_image = np.asanyarray(color_frame.get_data())

        color_image, detected_palm_oil, angles1, palm_oil_num = process_frame(color_image, confidence)
        target_pitch, target_yaw = getIMUdata(frames)
        target_pitch += angles1[1]
        target_yaw += angles1[0]

        print(palm_oil_num)
        # Show RGB image

        cv2.imshow('RGB Image', color_image)

        # Exit when 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

        if detected_palm_oil:
            cv2.imshow('RGB Image', cv2.imread(DETECTED_FRAME_PATH))
            cv2.waitKey(0)
            while True:
                frames = pipeline.wait_for_frames()
                current_pitch, current_yaw = getIMUdata(frames)
                print(current_pitch - target_pitch)
                print(current_yaw - target_yaw)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
finally:
    # Stop streaming
    pipeline.stop()
    cv2.destroyAllWindows()