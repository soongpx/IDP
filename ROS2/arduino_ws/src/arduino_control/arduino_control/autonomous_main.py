import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from my_robot_interfaces.msg import FindObstacle, LaserScan, Joystick, MotorCommand, FruitDepth
from my_robot_interfaces.action import Detection, HarvestFruit


class AutonomousNode(Node):

    def __init__(self):

        super().__init__('AutonomousNode')

        # Declare subscription
        self.obstacle_subscription = self.create_subscription(FindObstacle, 'find_obstacle', self.find_obstacle, 10)
        self.obstacle_subscription
        self.lidar_subscription = self.create_subscription(LaserScan, 'laser_scan', self.laser_scan, 10)
        self.lidar_subscription
        self.joystick_subscription = self.create_subscription(Joystick, 'joystick', self.joystick_control, 10)
        self.joystick_subscription

        # Declare publisher
        self.publisher_ = self.create_publisher(MotorCommand, 'motor_command', 10)
        self.timer = self.create_timer(0.01, self.timer_callback)

        # Declare action client
        self.detection_action_client = ActionClient(self, Detection, 'detection')
        self.harvest_action_client = ActionClient(self, HarvestFruit, 'harvest_fruit')
        self.detection_send_goal_future = None
        self.detection_get_result_future = None
        self.detection_goal_handle = None
        self.harvest_send_goal_future = None
        self.harvest_get_result_future = None
        self.start_detection = False
        self.start_harvest = False

        # Variables for find_obstacle
        self.nearest_distance1 = 0
        self.nearest_angle1 = 0
        self.nearest_distance2 = 0
        self.nearest_angle2 = 0
        self.reach = False

        # Variables for lidar
        self.range = []
        self.angle = []

        # Variables for joystick
        self.buttons = []
        self.axes = []
        self.axes_name = []

        # Variables for fruit depth
        self.fruit_detected = False
        self.fruit_depth = 0.0
        self.fruit_number = 0
        self.target_pitch = 0.0
        self.target_yaw = 0.0

        # Variables for motor command
        self.left_speed = 0
        self.right_speed = 0
        self.rotate_speed = 0
        self.tilt_speed = 0
        self.extend_speed = 0
        self.vibrate_speed = 0
        self.direction = 0
        self.previous_direction = 0

        self.target_left_speed = 50
        self.target_right_speed = 50
        self.target_rotate_minus_speed_offset = 25
        self.target_rotate_plus_speed_offset = 45
        self.set_rotate_speed = 0
        self.set_tilt_speed = 0
        self.set_extend_speed = 0
        self.set_vibrate_speed = 0
        self.set_direction = 0

        # Variables for algorithm
        self.start = False
        self.state = "Reaching tree"
        self.state1 = "Rotate"
        self.front_obstacle_distance = 0.65
        self.near_distance = self.front_obstacle_distance - 0.25
        self.far_distance = self.front_obstacle_distance + 0.25
        self.stop_counter = 0
        self.forward_state = 0
        self.increase_left_speed = 0
        self.increase_right_speed = 0
        self.increase_counter = 0
        self.stop_counter1 = 0
        self.stop_counter2 = 0
        self.stop_counter3 = 0
        self.stop_counter4 = 0
        self.timer_counter = 0
        self.forward_state1 = 0
        self.target_next_angle = 0

        self.first_detect = True
        self.first_harvest = True

    # Function to find the nearest obstacle
    def find_obstacle(self, msg):
        self.nearest_distance1 = msg.nearest_distance1
        self.nearest_angle1 = msg.nearest_angle1
        self.nearest_distance2 = msg.nearest_distance2
        self.nearest_angle2 = msg.nearest_angle2
        self.reach = msg.reach

    def laser_scan(self, msg):
        self.angle = msg.angles
        self.range = msg.ranges

    def joystick_control(self, msg):
        self.buttons = msg.button
        self.axes = msg.axes
        self.axes_name = msg.axes_name

    # Detection Action #

    def send_detection_goal(self, mode):
        self.start_detection = True
        goal_msg = Detection.Goal()
        goal_msg.mode = mode

        self.detection_action_client.wait_for_server()
        self.detection_send_goal_future = self.detection_action_client.send_goal_async(goal_msg,
                                                                                       feedback_callback=self.detection_feedback)
        self.detection_send_goal_future.add_done_callback(self.detection_goal_response_callback)

    def detection_goal_response_callback(self, future):
        self.detection_goal_handle = future.result()
        if not self.detection_goal_handle.accepted:
            self.get_logger().info('Failed to start detection')
            return

        self.get_logger().info('Start Detection')

        self.detection_get_result_future = self.detection_goal_handle.get_result_async()
        self.detection_get_result_future.add_done_callback(self.detection_result)

    def detection_result(self, future):
        result = future.result().result
        self.get_logger().info(
            f'Detected: {result.detected}, Depth: {result.fruit_depth}, Number: {result.fruit_number}, Pitch: {result.target_pitch}, Yaw: {result.target_yaw}')

        self.fruit_detected = result.detected
        self.fruit_depth = result.fruit_depth
        self.fruit_number = result.fruit_number
        self.target_pitch = result.target_pitch
        self.target_yaw = result.target_yaw
        self.start_detection = False

        if self.fruit_detected:
            self.state = "Harvest"
            self.first_detect = True
        else:
            self.state = "Next Obstacle"
            self.first_detect = True

    def detection_feedback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Fruit Detected: {feedback.fruit_detected}')


    def detection_goal_canceled_callback(self, future):
        cancel_response = future.result()
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info('Cancelling of goal complete')
        else:
            self.get_logger().warning('Goal failed to cancel')

    # Detection Action End #

    # Harvest Action Start #

    def send_harvest_goal(self):
        goal_msg = HarvestFruit.Goal()
        goal_msg.detected = self.fruit_detected
        goal_msg.fruit_depth = self.fruit_depth
        goal_msg.target_pitch = self.target_pitch
        goal_msg.target_yaw = self.target_yaw

        self.harvest_action_client.wait_for_server()
        self.harvest_send_goal_future = self.harvest_action_client.send_goal_async(goal_msg,
                                                                                   feedback_callback=self.harvest_feedback)
        self.harvest_send_goal_future.add_done_callback(self.harvest_goal_response_callback)

    def harvest_goal_response_callback(self, future):
        self.harvest_goal_handle = future.result()
        if not self.harvest_goal_handle.accepted:
            self.get_logger().info('Harvest Action Fail')
            return

        self.get_logger().info('Start Harvest')

        self.harvest_get_result_future = self.harvest_goal_handle.get_result_async()
        self.harvest_get_result_future.add_done_callback(self.harvest_result)

    def harvest_result(self, future):
        result = future.result().result
        self.get_logger().info(f'End: {result.end}')

        if result.end:
            self.state = "Check Detection"
            self.first_harvest = True

    def harvest_feedback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(
            f'Rotate: {feedback.rotate_speed}, Tilt: {feedback.tilt_speed}, Extend: {feedback.extend_speed}, Vibrate: {feedback.vibrate_speed}, Dir: {feedback.direction}')
        self.set_rotate_speed = feedback.rotate_speed
        self.set_tilt_speed = feedback.tilt_speed
        self.set_extend_speed = feedback.extend_speed
        self.set_vibrate_speed = feedback.vibrate_speed
        self.set_direction = feedback.direction

    def harvest_goal_canceled_callback(self, future):
        cancel_response = future.result()
        if len(cancel_response.goals_canceling) > 0:
            self.get_logger().info('Cancelling of goal complete')
        else:
            self.get_logger().warning('Goal failed to cancel')

    # Harvest Action End #

    def cap_loco(self, speed):
        if speed > 100:
            return 100
        elif speed < 1:
            return 0
        elif 1 < speed < 30:
            return 30
        else:
            return speed

    def cap255(self, speed):
        if speed > 255:
            return 255
        elif speed < 0:
            return 0
        else:
            return speed

    def timer_callback(self):
        msg = MotorCommand()
        for button in self.buttons:
            if button == "Start":
                self.start = True
            elif button == "Back":
                self.start = False
                self.state = "Reaching tree"
                self.state1 = "Rotate"
                if self.start_detection:
                    future = self.detection_goal_handle.cancel_goal_async()
                    future.add_done_callback(self.detection_goal_canceled_callback)
                    self.get_logger().info("Cancelled detection action")
                    self.start_detection = False
                if self.start_harvest:
                    future = self.harvest_goal_handle.cancel_goal_async()
                    future.add_done_callback(self.harvest_goal_canceled_callback)
                    self.get_logger().info("Cancelled harvest action")
                    self.start_harvest = False
            msg.left_speed = 0
            msg.right_speed = 0
            msg.extend_speed = 0
            msg.rotate_speed = 0
            msg.tilt_speed = 0
            msg.vibrate_speed = 0
            msg.direction = 0
        if self.start:
            self.left_speed = 0
            self.right_speed = 0
            self.rotate_speed = 0
            self.tilt_speed = 0
            self.extend_speed = 0
            self.vibrate_speed = 0
            self.direction = 0
            if self.state == "Reaching tree":
                if self.state1 == "Rotate":
                    self.rotate_to_face()
                elif self.state1 == "Forward":
                    self.move_forward()
            elif self.state == "Rotate 90":
                self.forward_state = 0
                self.forward_state1 = 0
                self.increase_left_speed = 0
                self.increase_right_speed = 0
                self.stop_counter = 0
                self.stop_counter3 = 0
                self.rotate_until_left_90_degrees()
            elif self.state == "Speed Differential":
                self.stop_counter1 = 0
                self.start_speed_differential()
                if self.first_detect:
                    self.send_detection_goal(True)
                    self.first_detect = False
            elif self.state == "Harvest":
                self.get_logger().info("Harvesting")
                if self.first_harvest:
                    self.send_harvest_goal()
                    self.first_harvest = False
                self.rotate_speed = self.set_rotate_speed
                self.tilt_speed = self.set_tilt_speed
                self.extend_speed = self.set_extend_speed
                self.vibrate_speed = self.set_vibrate_speed
                self.direction += self.set_direction
            elif self.state == "Check Detection":
                self.get_logger().info("Check Detection")
                self.start_speed_differential()
                if self.first_detect:
                    self.send_detection_goal(False)
                    self.first_detect = False
            elif self.state == "Next Obstacle":
                self.stop_counter2 = 0
                self.timer_counter = 0
                if self.state1 == "Rotate":
                    self.reach_next_obstacle()
                    self.increase_left_speed = 0
                    self.increase_right_speed = 0
                elif self.state1 == "Forward":
                    self.stop_counter3 = 0
                    self.move_forward_to_next()

            # Ramp Down
            if self.left_speed == 0 and self.right_speed == 0:
                self.direction += self.previous_direction

            # self.get_logger().info(str(self.rotate_speed))
            msg.left_speed = self.cap_loco(self.left_speed)
            msg.right_speed = self.cap_loco(self.right_speed)
            msg.extend_speed = self.cap255(self.extend_speed)
            msg.rotate_speed = self.cap255(self.rotate_speed)
            msg.tilt_speed = self.cap255(self.tilt_speed)
            msg.vibrate_speed = self.cap255(self.vibrate_speed)
            msg.direction = self.cap255(self.direction)
        else:
            msg.left_speed = 0
            msg.right_speed = 0
            msg.extend_speed = 0
            msg.rotate_speed = 0
            msg.tilt_speed = 0
            msg.vibrate_speed = 0
            msg.direction = 0
        self.publisher_.publish(msg)

    # Function to rotate to face the nearest obstacle at front
    def rotate_to_face(self):
        if self.nearest_angle1 >= 2.942 or self.nearest_angle1 <= -2.942:
            if self.forward_state >= 10:
                self.state1 = "Forward"
            else:
                self.forward_state += 1
        elif 0 <= self.nearest_angle1 < 2.942:
            self.left_speed = self.target_left_speed
            self.right_speed = self.target_right_speed
            self.direction += 1
            self.previous_direction = 1
        elif -2.942 < self.nearest_angle1 < 0:
            self.left_speed = self.target_left_speed
            self.right_speed = self.target_right_speed
            self.direction += 2
            self.previous_direction = 2

        self.get_logger().info("Rotate")

    # Function to move forward until 50cm to obstacle
    def move_forward(self):
        if self.stop_counter <= 30:
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter += 1
        else:
            if self.nearest_distance1 > self.front_obstacle_distance:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 3
                self.previous_direction = 3
                if 0 < self.nearest_angle1 < 2.942:
                    if self.increase_counter >= 50:
                        self.increase_counter = 0
                        self.increase_left_speed += 1
                    else:
                        self.increase_counter += 1
                elif -2.942 < self.nearest_angle1 < 0:
                    if self.increase_counter >= 50:
                        self.increase_counter = 0
                        self.increase_right_speed += 1
                    else:
                        self.increase_counter += 1
                else:
                    self.increase_left_speed = 0
                    self.increase_right_speed = 0
                self.right_speed += self.increase_right_speed
                self.left_speed += self.increase_left_speed
            else:
                self.state = "Rotate 90"
                self.state1 = "Rotate"

        self.get_logger().info("Forward")

    # Function to rotate until centre of obstacle is at left 90 degree
    def rotate_until_left_90_degrees(self):
        if self.stop_counter1 <= 30:
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter1 += 1
        else:
            if -1.67 < self.nearest_angle1 < -1.47:
                self.state = "Speed Differential"
            else:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 1
                self.previous_direction = 1
        self.get_logger().info("Rotate 90")

    # Function to start speed differential and maintain 50cm distance with obstacle
    def start_speed_differential(self):
        if self.stop_counter2 <= 30:
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter2 += 1
        else:
            self.left_speed = self.target_left_speed - self.target_rotate_minus_speed_offset
            self.right_speed = self.target_right_speed + self.target_rotate_plus_speed_offset
            self.direction += 3
            self.previous_direction = 3
            if self.nearest_distance1 < self.near_distance:
                if self.increase_counter >= 50:
                    self.increase_counter = 0
                    self.increase_right_speed -= 5
                else:
                    self.increase_counter += 1
            elif self.nearest_distance1 > self.far_distance:
                if self.increase_counter >= 50:
                    self.increase_counter = 0
                    self.increase_right_speed += 5
                else:
                    self.increase_counter += 1
            else:
                self.increase_counter = 0
            self.right_speed = self.right_speed + self.increase_right_speed
            self.timer_counter += 1

        self.get_logger().info("Speed differential")

    def reach_next_obstacle(self):
        if self.stop_counter3 <= 30:
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter3 += 1
        else:
            if self.nearest_angle2 >= 2.942 or self.nearest_angle2 <= -2.942:
                if self.forward_state1 >= 30:
                    self.state1 = "Forward"
                else:
                    self.forward_state1 += 1
            elif 0 <= self.nearest_angle2 < 2.942:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 1
                self.previous_direction = 1
            elif -2.942 < self.nearest_angle1 < 0:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 2
                self.previous_direction = 2
        self.get_logger().info("Next obstacle")

    def move_forward_to_next(self):
        if self.stop_counter4 <= 15:
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter4 += 1
        else:
            filtered_angle = []
            filtered_range = []
            for angle, distance in zip(self.angle, self.range):
                if 3.2 > angle > 0.8 or -3.2 < angle < -0.8:
                    filtered_angle.append(angle)
                    filtered_range.append(distance)

            nearest_distance = min(filter(lambda x: x != 0, filtered_range))
            nearest_angle = filtered_angle[filtered_range.index(nearest_distance)]
            if nearest_distance > self.front_obstacle_distance:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 3
                self.previous_direction = 3
                if 0 <= self.nearest_angle2 < 2.942:
                    if self.increase_counter >= 50:
                        self.increase_counter = 0
                        self.increase_left_speed += 1
                    else:
                        self.increase_counter += 1
                elif -2.942 < self.nearest_angle1 < 0:
                    if self.increase_counter >= 50:
                        self.increase_counter = 0
                        self.increase_right_speed += 1
                    else:
                        self.increase_counter += 1
                else:
                    self.increase_left_speed = 0
                    self.increase_right_speed = 0
                self.right_speed += self.increase_right_speed
                self.left_speed += self.increase_left_speed
            else:
                self.state = "Rotate 90"
                self.state1 = "Rotate"

        self.get_logger().info("Forward")


def main(args=None):
    rclpy.init(args=args)
    autonomous_node = AutonomousNode()  # Corrected variable name
    try:
        rclpy.spin(autonomous_node)  # Corrected variable name
    except KeyboardInterrupt:
        pass

    autonomous_node.destroy_node()  # Corrected variable name
    rclpy.shutdown()


if __name__ == '__main__':
    main()
