import cv2
from ultralytics import YOLO
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from my_robot_interfaces.action import Detection
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from rclpy.executors import MultiThreadedExecutor


class Points:
    x = 0
    y = 0
    z = 0


class DepthPublisherNode(Node):
    def __init__(self):
        super().__init__('detection')
        self.detection_action_server = ActionServer(self, Detection, 'detection', self.process_frames)

        # Variables for Camera frame
        self.frame_height = 480
        self.frame_width = 640
        self.frames = None

        # Variables for Machine Learning
        self.crosshair_x_offset = 0.44
        self.crosshair_y_offset = 0.65
        self.confidence = 0.6
        self.FOV_V = 65.5  # RGB
        self.FOV_H = 91.2  # RGB
        self.detected_palm_oil = False
        self.fruit_depth = 0.0
        self.palm_oil_num = 0

        # Variables for frame processing
        self.depth_image = None
        self.color_image = None

        # Variables for harvest status
        self.harvest_counter = 0
        self.harvest_end = True

        # Variables for orientation
        self.target_pitch = 0
        self.target_yaw = 0

        # Variables for sensor fusion
        self.dt = 1 / 200  # Time interval (assuming gyro runs at 200 Hz)
        self.beta = 0.98  # Complementary filter coefficient

        # Machine Learning Model
        model_path = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/7_jan_palm_oil.pt"
        self.model = YOLO(model_path)
        self.count = 0

    def calc_pitch_angle(self, pt1_x, pt1_y, center_x, center_y):
        vertical = (center_y - pt1_y)
        horizontal = (center_x - pt1_x)

        self.target_pitch = (self.FOV_V / self.frame_height) * vertical
        self.target_yaw = (self.FOV_H / self.frame_width) * horizontal

    def process_frames(self, goal_handle):
        self.get_logger().info("Palm Oil Detection Starts...")

        if goal_handle.request.start:
            feedback_msg = Detection.Feedback()

            while True:
                self.detected_palm_oil = False
                self.palm_oil_num = 0
                self.fruit_depth = 0.0
                if self.depth_image is not None and self.color_image is not None:
                    self.process_frame()  # self.palm_oil_num, self.detected_palm_oil, self.pitch_angle, self.yaw_angle

                    # Display color frame with bounding boxes around detected objects
                    # frame_name = "Detection" + str(self.count)
                    # cv2.imshow(frame_name, self.color_image)
                    # cv2.waitKey(1)

                    feedback_msg.fruit_detected = self.detected_palm_oil
                    goal_handle.publish_feedback(feedback_msg)
                    self.get_logger().info(str(feedback_msg.fruit_detected))

                    if self.detected_palm_oil:
                        break

            print(self.fruit_depth)
            result = Detection.Result()
            result.detected = feedback_msg.fruit_detected
            result.fruit_depth = self.fruit_depth
            result.fruit_number = self.palm_oil_num
            result.target_pitch = self.target_pitch
            result.target_yaw = self.target_yaw
            self.get_logger().info(f"{result.detected}, {result.fruit_number}, {result.fruit_depth}, {result.target_pitch}, {result.target_yaw}")

            goal_handle.succeed()

            image_path = r"/home/px/arduino_ws/src/arduino_control/arduino_control/ML/detected_frame" + str(self.count) + ".jpg"
            cv2.imwrite(image_path, self.color_image)
            # cv2.destroyWindow(frame_name)
            self.count += 1
            return result


    def process_frame(self):
        predictions = self.model.predict(self.color_image, conf=self.confidence)
        depth_arr = []
        coordinates = predictions[0].boxes.xywh.tolist()

        height, width, _ = self.color_image.shape

        # Draw horizontal line (crosshair)
        cv2.line(self.color_image, (0, int(height * self.crosshair_y_offset)),
                 (width, int(height * self.crosshair_y_offset)), (0, 255, 0), 1)
        # Draw vertical line (crosshair)
        cv2.line(self.color_image, (int(width * self.crosshair_x_offset), 0),
                 (int(width * self.crosshair_x_offset), height), (0, 255, 0), 1)

        for pts in coordinates:
            # Extract x, y, width, and height
            x, y, width, height = int(pts[0]), int(pts[1]), int(pts[2]), int(pts[3])

            pts[0] = int(pts[0] - pts[2] / 2)
            pts[1] = int(pts[1] - pts[3] / 2)
            cv2.rectangle(self.color_image, (int(pts[0]), int(pts[1])), (int(pts[0] + pts[2]), int(pts[1] + pts[3])),
                          (0, 255, 0), 2)
            cv2.putText(self.color_image, 'palm oil', (pts[0], pts[1]), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 3,
                        cv2.LINE_AA)

            center_x = x
            center_y = y

            # Get depth value at the center point
            depth_value = self.depth_image[center_y, center_x] / 1000

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
            self.calc_pitch_angle(closest_pt.x, closest_pt.y, int(width * self.crosshair_x_offset),
                                  int(height * self.crosshair_y_offset))
            self.detected_palm_oil = True
            self.fruit_depth = closest_depth
            print(f"Closest Depth: {closest_depth}")

    def __del__(self):
        self.destroy_node()


class NodeSubscriber(Node):
    def __init__(self,actionServer):
        super().__init__('minimal_subscriber')
        self.rgb_image_subscriber = self.create_subscription(Image, 'camera/color/image_raw', self.image_callback, 10)
        self.depth_image_subscriber = self.create_subscription(Image, 'camera/depth/image_rect_raw', self.depth_callback, 10)
        self.create_timer(0.01, self.timer_callback)

        self.br = CvBridge()
        
        self.depth_image = None
        self.color_image = None
        self.action_server = actionServer
        self.color_image_show = False

    def image_callback(self, msg):
        self.color_image = self.br.imgmsg_to_cv2(msg)
        self.color_image = cv2.cvtColor(self.color_image, cv2.COLOR_RGB2BGR)

    def depth_callback(self, msg):
        self.depth_image = self.br.imgmsg_to_cv2(msg)

    def timer_callback(self):
        self.action_server.depth_image = self.depth_image
        self.action_server.color_image = self.color_image 



def main(args=None):
    rclpy.init(args=args)
    try:
        depth_publisher = DepthPublisherNode()
        py_sub = NodeSubscriber(actionServer=depth_publisher)
        executor = MultiThreadedExecutor(num_threads=2)
        executor.add_node(depth_publisher)
        executor.add_node(py_sub)

        try:
            executor.spin()
        finally:
            executor.shutdown()
            depth_publisher.destroy_node()

    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
