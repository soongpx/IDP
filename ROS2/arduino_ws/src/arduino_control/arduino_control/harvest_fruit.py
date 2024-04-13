import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from my_robot_interfaces.action import HarvestFruit
from my_robot_interfaces.msg import ImuData, RealsenseImu
from cv_bridge import CvBridge
from rclpy.executors import MultiThreadedExecutor


class Points:
    x = 0
    y = 0
    z = 0


class HarvestFruitNode(Node):
    def __init__(self):
        super().__init__('harvest_fruit')
        self.detection_action_server = ActionServer(self, HarvestFruit, 'harvest_fruit', self.execute_callback)

        # Variables for Machine Learning
        self.detected_palm_oil = False
        self.fruit_depth = 0.0

        # Variables for harvest status
        self.harvest_counter = 0
        self.harvest_end = True

        # Variables for orientation
        self.target_pitch = 0
        self.target_yaw = 0
        self.current_pitch = 0
        self.current_yaw = 0

        # Process Variables
        self.state = "Rotate Arm"
        self.first_detect = True
        self.wait_rotate = False
        self.current_harvest_time = 0
        self.target_harvest_time = 0
        self.time_counter = 0.003
        self.actuator_speed = 0.03  # m/s
        self.harvest_offset = 0.5  # m
        self.previous_time = 0
        self.current_time = 0
        self.timer_counter = 0
        self.tilt_counter = 0
        self.harvest_end = True

        self.set_tilt_speed = 0
        self.set_extend_speed = 0
        self.set_rotate_speed = 0
        self.set_vibrate_speed = 0
        self.set_direction = 0

        # Motor Variables
        self.rotate_speed = 18
        self.tilt_speed = 255
        self.extend_speed = 255
        self.vibrate_speed = 50
        self.direction = 0

    def execute_callback(self, goal_handle):
        self.get_logger().info("Palm Oil Harvest Starts...")

        if goal_handle.request.detected:
            self.fruit_depth = goal_handle.request.fruit_depth
            self.target_harvest_time = (self.fruit_depth - self.harvest_offset) / self.actuator_speed - self.current_harvest_time

            self.target_pitch = goal_handle.request.target_pitch
            self.target_yaw = goal_handle.request.target_yaw
            feedback_msg = HarvestFruit.Feedback()

            while True:
                if self.first_detect:
                    self.state = "Rotate Arm"
                    self.first_detect = False
                self.set_tilt_speed = 0
                self.set_extend_speed = 0
                self.set_rotate_speed = 0
                self.set_vibrate_speed = 0
                self.set_direction = 0
                self.harvest_end = False

                if self.state == "Rotate Arm":
                    self.get_logger().info("Rotate Arm")

                    # Extend or retract arm
                    if round(self.target_harvest_time, 2) - round(self.current_harvest_time, 2) > 0.3:
                        self.current_harvest_time += self.time_counter
                        self.set_extend_speed = self.extend_speed
                        self.set_direction += 16
                    elif round(self.target_harvest_time, 2) - round(self.current_harvest_time, 2) < -0.3:
                        self.current_harvest_time -= self.time_counter
                        self.set_extend_speed = self.extend_speed
                        self.set_direction += 0
                    else:
                        self.set_extend_speed = 0

                    # Rotate arm
                    if (self.current_yaw - self.target_yaw) > 2:
                        self.set_rotate_speed = self.rotate_speed
                        self.set_direction += 4
                    elif (self.current_yaw - self.target_yaw) < -2:
                        self.set_rotate_speed = self.rotate_speed
                        self.set_direction += 0
                    else:
                        self.set_rotate_speed = 0
                        if self.set_extend_speed == 0:
                            self.state = "Tilt Arm"

                elif self.state == "Tilt Arm":

                    self.get_logger().info("Tilt Arm")

                    # Tilt the arm
                    if (self.current_pitch - self.target_pitch) < -1:
                        self.set_tilt_speed = self.tilt_speed
                        self.set_direction += 8
                        # # Move linear actuator back in case collision
                        # if round(self.target_harvest_time, 2) - round(self.current_harvest_time, 2) < -0.3:
                        #     self.current_harvest_time -= self.time_counter
                        #     self.set_extend_speed = self.extend_speed
                        #     self.set_direction += 0

                    elif (self.current_pitch - self.target_pitch) > 1:
                        self.set_tilt_speed = self.tilt_speed
                        self.set_direction += 0
                        # # Move linear actuator back in case collision
                        # if round(self.target_harvest_time, 2) - round(self.current_harvest_time, 2) < -0.3:
                        #     self.current_harvest_time -= self.time_counter
                        #     self.set_extend_speed = self.extend_speed
                        #     self.set_direction += 0

                    else:
                        self.tilt_counter += 1
                        if self.tilt_counter == 10:
                            self.state = "Cut"
                            self.tilt_counter = 0

                elif self.state == "Cut":

                    self.get_logger().info("Cut")
                    self.set_vibrate_speed = self.vibrate_speed
                    self.set_extend_speed = self.extend_speed
                    self.set_direction += 16
                    self.timer_counter += self.time_counter

                    # 10 seconds cut
                    if self.timer_counter >= 10:
                        self.current_harvest_time += 0.1 / self.actuator_speed
                        self.timer_counter = 0
                        self.state = "Retract Arm"

                elif self.state == "Retract Arm":

                    self.get_logger().info("Retract Arm")
                    if self.current_yaw >= 3:
                        self.set_rotate_speed = self.rotate_speed
                        self.set_direction += 4
                    elif self.current_yaw <= -3:
                        self.set_rotate_speed = self.rotate_speed
                        self.set_direction += 0
                    else:
                        self.set_rotate_speed = 0

                    if round(self.current_harvest_time, 2) > 0:
                        self.current_harvest_time -= self.time_counter
                        self.set_extend_speed = self.extend_speed
                        self.set_direction += 0
                    else:
                        if self.set_rotate_speed == 0:
                            self.state = ""

                elif self.state == "":
                    self.get_logger().info("End")
                    self.first_detect = True
                    self.harvest_end = True
                
                else:
                    self.set_rotate_speed = 0
                    self.set_tilt_speed = 0
                    self.set_extend_speed = 0
                    self.set_vibrate_speed = 0

                
                feedback_msg.rotate_speed = self.set_rotate_speed
                feedback_msg.tilt_speed = self.set_tilt_speed
                feedback_msg.extend_speed = self.set_extend_speed
                feedback_msg.vibrate_speed = self.set_vibrate_speed
                feedback_msg.direction = self.set_direction
                self.get_logger().info(f"Rotate: {self.set_rotate_speed}, Tilt: {self.set_tilt_speed}, Extend: {self.set_extend_speed}, Vibrate: {self.set_vibrate_speed}, Direction: {self.set_direction}")
                goal_handle.publish_feedback(feedback_msg)

                if self.harvest_end:
                    break

            result = HarvestFruit.Result()
            result.end = self.harvest_end
            self.first_detect = True
            self.harvest_end = False
            goal_handle.succeed()
            
            return result

    def __del__(self):
        self.destroy_node()


class NodeSubscriber(Node):
    def __init__(self,actionServer):
        super().__init__('harvest_subscriber')
        self.realsense_imu_subscriber = self.create_subscription(RealsenseImu, 'realsense_imu', self.realsense_imu_callback, 10)
        self.realsense_imu_subscriber
        self.imu_subscriber = self.create_subscription(ImuData, 'imu_data', self.imu_callback, 10)
        self.imu_subscriber
        self.create_timer(0.01, self.timer_callback)

        self.br = CvBridge()
        self.pitch = 0.0
        self.yaw = 0.0
        self.action_server = actionServer

    def realsense_imu_callback(self, msg):
        self.pitch = msg.pitch

    def imu_callback(self, msg):
        self.yaw = msg.yaw

    def timer_callback(self):
        self.action_server.current_pitch = self.pitch
        self.action_server.current_yaw = self.yaw 



def main(args=None):
    rclpy.init(args=args)
    try:
        harvest_fruit_node = HarvestFruitNode()
        py_sub = NodeSubscriber(actionServer=harvest_fruit_node)
        executor = MultiThreadedExecutor(num_threads=2)
        executor.add_node(harvest_fruit_node)
        executor.add_node(py_sub)

        try:
            executor.spin()
        finally:
            executor.shutdown()
            harvest_fruit_node.destroy_node()

    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
