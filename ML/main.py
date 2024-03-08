from ultralytics import YOLO
import cv2
video_path = r"videos/palm oil.mp4"
video1_path = r"videos/Harvesting Palm Oil Using a Machine.mp4"
model = YOLO(r"model/7_jan_palm_oil.pt")
DETECTED_FRAME_PATH = "detection/detected_frame.jpg"


def palm_oil_detection():
    cap = cv2.VideoCapture(video1_path)
    while True:
        # Read a frame from the video
        ret, frame = cap.read()

        if not ret:
            break  # Break the loop if no frame is captured

        # Process the frame to detect objects
        process_frame(frame)

    cap.release()  # Release the video capture object


def process_frame(frame):
    predictions = model.predict(frame, conf=0.5)

    coordinates = predictions[0].boxes.xywh.tolist()
    for pts in coordinates:
        print(pts)
        pts[0] = int(pts[0] - pts[2] / 2)
        pts[1] = int(pts[1] - pts[3] / 2)
        cv2.rectangle(frame, (int(pts[0]), int(pts[1])), (int(pts[0] + pts[2]), int(pts[1] + pts[3])), (0, 255, 0), 2)
        cv2.putText(frame, 'palm oil', (pts[0], pts[1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 3, cv2.LINE_AA)

    cv2.imshow('prediction', frame)
    cv2.imwrite(DETECTED_FRAME_PATH, frame)
    cv2.waitKey(1)


palm_oil_detection()
