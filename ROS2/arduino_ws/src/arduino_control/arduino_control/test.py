import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from my_robot_interfaces.action import Detection
import time


class FibonacciActionClient(Node):

    def __init__(self):
        super().__init__('fibonacci_action_client')
        self._action_client = ActionClient(self, Detection, 'detection')
        self._timer = self.create_timer(0.01, self.timer_callback)
        self.first_detected = True
        self.end = False
        self.detected = False
        self.hi = True

    def send_goal(self, order):
        goal_msg = Detection.Goal()
        goal_msg.mode = order

        self._action_client.wait_for_server()

        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return

        self.get_logger().info('Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Detected: {result.detected}, Depth: {result.fruit_depth}, Number: {result.fruit_number}, Pitch: {result.target_pitch}, Yaw: {result.target_yaw}')
        self.end = True
        self.detected = result.detected

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        # self.get_logger().info('Received feedback: {0}'.format(feedback.fruit_detected))
        self.detected = feedback.fruit_detected

    def timer_callback(self):
        if self.first_detected:
            self.send_goal(self.hi)
            self.end = False
            self.first_detected = False
        if self.end:
            time.sleep(5)
            self.first_detected = True
            if self.hi:
                self.hi = False
            else:
                self.hi = True
        
        self.get_logger().info(str(self.detected))
        
        


def main(args=None):
    rclpy.init(args=args)

    action_client = FibonacciActionClient()

    rclpy.spin(action_client)
    rclpy.shutdown()


if __name__ == '__main__':
    main()

# import rclpy
# from rclpy.action import ActionClient
# from rclpy.node import Node
# from my_robot_interfaces.action import HarvestFruit
# import time


# class FibonacciActionClient(Node):

#     def __init__(self):
#         super().__init__('fibonacci_action_client')
#         self._action_client = ActionClient(self, HarvestFruit, 'harvest_fruit')
#         self._timer = self.create_timer(0.01, self.timer_callback)
#         self.first_detected = True
#         self.end = False

#     def send_harvest_goal(self):
#         goal_msg = HarvestFruit.Goal()
#         goal_msg.detected = True
#         goal_msg.fruit_depth = 0.69
#         goal_msg.fruit_number = 1
#         goal_msg.target_pitch = -37.5108
#         goal_msg.target_yaw = -30.072


#         self._action_client.wait_for_server()

#         self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.harvest_feedback)

#         self._send_goal_future.add_done_callback(self.harvest_goal_response_callback)

#     def harvest_goal_response_callback(self, future):
#         goal_handle = future.result()
#         if not goal_handle.accepted:
#             self.get_logger().info('Goal rejected :(')
#             return

#         self.get_logger().info('Goal accepted :)')

#         self._get_result_future = goal_handle.get_result_async()
#         self._get_result_future.add_done_callback(self.harvest_result)

#     def harvest_result(self, future):
#         result = future.result().result
#         self.get_logger().info(f'End: {result.end}')
#         self.end = True

#     def harvest_feedback(self, feedback_msg):
#         feedback = feedback_msg.feedback
#         self.get_logger().info(f'Rotate: {feedback.rotate_speed}, Tilt: {feedback.tilt_speed}, Extend: {feedback.extend_speed}, Vibrate: {feedback.vibrate_speed}, Dir: {feedback.direction}')

#     def timer_callback(self):
#         if self.first_detected:
#             self.send_harvest_goal()
#             self.end = False
#             self.first_detected = False
#         if self.end:
#             time.sleep(5)
#             self.first_detected = True
        
        


# def main(args=None):
#     rclpy.init(args=args)

#     action_client = FibonacciActionClient()

#     rclpy.spin(action_client)
#     rclpy.shutdown()


# if __name__ == '__main__':
#     main()