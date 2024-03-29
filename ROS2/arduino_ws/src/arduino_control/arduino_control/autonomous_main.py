import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import FindObstacle, LaserScan, Joystick, MotorCommand, FruitDepth


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
        self.fruit_subscription = self.create_subscription(FruitDepth, 'fruit_depth', self.detect_fruit, 10)
        self.fruit_subscription
        
        # Declare publisher
        self.publisher_ = self.create_publisher(MotorCommand, 'motor_command', 10)
        self.timer = self.create_timer(0.01, self.timer_callback)
        
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
        self.palm_oil_num = 0
        self.pitch_direction = 0
        self.yaw_direction = 0
        
        # Variables for motor command
        self.left_speed = 0
        self.right_speed = 0
        self.rotate_speed = 0
        self.tilt_speed = 0
        self.extend_speed = 0
        self.vibrate_speed = 0
        self.direction = 0
        
        # Variables for algorithm
        self.start = False
        self.state = "Reaching tree"
        self.state1 = "Rotate"
        self.target_left_speed = 50
        self.target_right_speed = 60
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
        
    def detect_fruit(self, msg):
        self.fruit_detected = msg.detected
        self.palm_oil_num = msg.palm_oil_num
        self.pitch_direction = msg.pitch_direction
        self.yaw_direction = msg.yaw_direction

    def cap_255(self, speed):
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
            elif button == "A":
                self.start = False
                self.state = "Reaching tree"
                self.state1 = "Rotate"
            msg.left_speed = 0
            msg.right_speed = 0
            msg.extend_speed = 0
            msg.rotate_speed = 0
            msg.tilt_speed = 0
            msg.vibrate_speed = 0
            msg.direction = 0
        if self.start:
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
                self.find_fruit()
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

            msg.left_speed = self.cap_255(self.left_speed)
            msg.right_speed = self.cap_255(self.right_speed)
            msg.extend_speed = self.cap_255(self.extend_speed)
            msg.rotate_speed = self.cap_255(self.rotate_speed)
            msg.tilt_speed = self.cap_255(self.tilt_speed)
            msg.vibrate_speed = self.cap_255(self.vibrate_speed)
            msg.direction = self.cap_255(self.direction)
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
        if -0.2 < self.nearest_angle1 < 0.2:
            if self.forward_state >= 10:
                self.state1 = "Forward"
            else:
                self.forward_state += 1
        elif 0.2 <= self.nearest_angle1 <= 3.142:
            self.left_speed = self.target_left_speed
            self.right_speed = self.target_right_speed
            self.direction += 2
        elif -3.142 <= self.nearest_angle1 <= -0.2:
            self.left_speed = self.target_left_speed
            self.right_speed = self.target_right_speed
            self.direction += 1
        
        self.get_logger().info("Rotate")

    # Function to move forward until 50cm to obstacle
    def move_forward(self):
        if self.stop_counter <= 30:
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter += 1
        else:
            if self.nearest_distance1 > 0.65:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 3
                if self.nearest_angle1 > 0.2:
                    if self.increase_counter >= 50:
                        self.increase_counter = 0
                        self.increase_right_speed += 1
                    else:
                        self.increase_counter += 1
                elif self.nearest_angle1 < -0.2:
                    if self.increase_counter >= 50:
                        self.increase_counter = 0
                        self.increase_left_speed += 1
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
                self.direction += 2
        self.get_logger().info("Rotate 90")


    def cap100(self, speed):
        if speed > 100:
            return 100
        else:
            return speed
        
    # Function to start speed differential and maintain 50cm distance with obstacle
    def start_speed_differential(self):
        if self.stop_counter2 <= 30:
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter2 += 1
        else:
            if self.timer_counter >= 2000:
                self.state = "Next Obstacle"
            else:
                self.left_speed = self.target_left_speed + 45
                self.right_speed = self.target_right_speed - 25
                self.direction += 3
                if self.nearest_distance1 < 0.3:
                    if self.increase_counter >= 1:
                        self.increase_counter = 0
                        self.increase_right_speed -= 1
                    else:
                        self.increase_counter += 1
                elif self.nearest_distance1 > 0.7:
                    if self.increase_counter >= 1:
                        self.increase_counter = 0
                        self.increase_right_speed += 1
                    else:
                        self.increase_counter += 1
                self.left_speed = self.cap100(self.left_speed + self.increase_right_speed)
                self.timer_counter += 1

        self.get_logger().info("Speed differential")

    def find_fruit(self):
        if self.fruit_detected:
            self.left_speed = 0
            self.right_speed = 0


    def reach_next_obstacle(self):
        if self.stop_counter3 <= 30:
            self.left_speed = 0
            self.right_speed = 0
            self.stop_counter3 += 1
        else:
            if -0.2 < self.nearest_angle2 < 0.2:
                if self.forward_state1 >= 30:
                    self.state1 = "Forward"
                else:
                    self.forward_state1 += 1
            elif 0.2 <= self.nearest_angle2 <= 3.142:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 1
            elif -3.142 <= self.nearest_angle2 <= -0.2:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 2
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
                if -0.2 < angle < 0.2:
                    filtered_angle.append(angle)
                    filtered_range.append(distance)

            nearest_distance = min(filter(lambda x: x != 0, filtered_range))
            nearest_angle = filtered_angle[filtered_range.index(nearest_distance)]
            if nearest_distance > 0.65:
                self.left_speed = self.target_left_speed
                self.right_speed = self.target_right_speed
                self.direction += 3
                if nearest_angle > 0.2:
                    if self.increase_counter >= 50:
                        self.increase_counter = 0
                        self.increase_right_speed += 1
                    else:
                        self.increase_counter += 1
                elif nearest_angle < -0.2:
                    if self.increase_counter >= 50:
                        self.increase_counter = 0
                        self.increase_left_speed += 1
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
