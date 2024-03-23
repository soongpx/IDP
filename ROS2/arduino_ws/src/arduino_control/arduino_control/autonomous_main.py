import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from my_robot_interfaces.msg import FindObstacle, MotorCommand
import time


class AutonomousNode(Node):

    def __init__(self):

        super().__init__('AutonomousNode')
        self.lidar_subscription = self.create_subscription(FindObstacle, 'find_obstacle', self.find_obstacle, 10)
        self.lidar_subscription
        self.publisher_ = self.create_publisher(MotorCommand, 'motor_command', 10)
        self.timer = self.create_timer(0.01, self.timer_callback)
        self.nearest_distance1 = 0
        self.nearest_angle1 = 0
        self.nearest_distance2 = 0
        self.nearest_angle2 = 0
        self.reach = False
        self.left_speed = 0
        self.right_speed = 0
        self.rotate_speed = 0
        self.tilt_speed = 0
        self.extend_speed = 0
        self.vibrate_speed = 0
        self.direction = 0
        self.state = "Reaching tree"
        self.state1 = "Rotate"
        self.stop_counter = 0
        self.forward_state = 0
        self.increase_left_speed = 0
        self.increase_right_speed = 0
        self.increase_counter = 0

    # Function to find nearest obstacle
    def find_obstacle(self, msg):
        self.nearest_distance1 = msg.nearest_distance1
        self.nearest_angle1 = msg.nearest_angle1
        self.nearest_distance2 = msg.nearest_distance2
        self.nearest_angle2 = msg.nearest_angle2
        self.reach = msg.reach

    def cap_255(self, speed):
        if speed > 255:
            return 255
        elif speed < 0:
            return 0
        else:
            return speed

    def timer_callback(self):
        msg = MotorCommand()
        self.direction = 0
        if self.state == "Reaching tree":
            if self.state1 == "Rotate":
                self.rotate_to_face()
            elif self.state1 == "Forward":
                self.move_forward()
                print("Forward")
        elif self.state == "Rotate 90":
            self.rotate_until_left_90_degrees()


        msg.left_speed = self.cap_255(self.left_speed)
        msg.right_speed = self.cap_255(self.right_speed)
        msg.extend_speed = self.cap_255(self.extend_speed)
        msg.rotate_speed = self.cap_255(self.rotate_speed)
        msg.tilt_speed = self.cap_255(self.tilt_speed)
        msg.vibrate_speed = self.cap_255(self.vibrate_speed)
        msg.direction = self.cap_255(self.direction)
        self.publisher_.publish(msg)

        # # Step 4: Rotate until centre of obstacle is at left 90 degree
        # self.rotate_until_left_90_degrees()

        # # Step 5: Start speed differential and maintain 50cm distance with obstacle
        # self.start_speed_differential()

    # Function to rotate to face nearest obstacle at front
    def rotate_to_face(self):
        if -0.2 < self.nearest_angle1 < 0.2:
            if self.forward_state >= 10:
                self.state1 = "Forward"
            else:
                self.forward_state += 1
        elif 0.2 <= self.nearest_angle1 <= 3.142:
            self.left_speed = 60
            self.right_speed = 60
            self.direction += 1
        elif -3.142 <= self.nearest_angle1 <=-0.2:
            self.left_speed = 60
            self.right_speed = 60
            self.direction += 2


    # Function to move forward until 50cm to obstacle
    def move_forward(self):
        if (self.stop_counter <= 15):
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter += 1
        else:
            if self.nearest_distance1 > 0.4:
                self.left_speed = 60
                self.right_speed = 60
                self.direction += 3
                if self.nearest_angle1 > 0.2:
                    if self.increase_counter == 100:
                        self.increase_right_speed += 1
                        self.right_speed += self.increase_right_speed
                    else:
                        self.increase_counter += 1
                elif self.nearest_angle1 < -0.2:
                    if self.increase_counter == 100:
                        self.increase_left_speed += 1
                        self.left_speed += self.increase_left_speed
                    else:
                        self.increase_counter += 1
                else:
                    self.increase_left_speed = 0
                    self.increase_right_speed = 0
            else:
                self.state = "Rotate 90"
                self.state1 = "Rotate"

    # Function to rotate until centre of obstacle is at left 90 degree
    def rotate_until_left_90_degrees(self):
        # Implement rotation until the centre of the obstacle is at left 90 degrees
        
        self.get_logger().info(("Rotating until centre of obstacle is at left 90 degrees"))

    # Function to start speed differential and maintain 50cm distance with obstacle
    def start_speed_differential(self):
        # Implement speed differential to maintain distance with the obstacle
        print("Starting speed differential and maintaining 50cm distance with obstacle")


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
