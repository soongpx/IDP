import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import FruitDepth, MotorCommand
from my_robot_interfaces.srv import HarvestConfirmation


class FruitHarvestNode(Node):
    def __init__(self):
        super().__init__('fruit_harvest')
        self.subscription = self.create_subscription(FruitDepth, 'fruit_depth', self.get_fruit_depth, 10)
        self.subscription  # prevent unused variable warning
        self.motor_publisher = self.create_publisher(MotorCommand, 'motor_command', 10)
        self.timer_period = 0.01  # seconds
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        self.confirm_action_service = self.create_service(HarvestConfirmation, 'confirm_action',
                                                          self.confirm_action_callback)  # Create a service server

        # Camera Variables
        self.detected = False
        self.fruit_depth = 0
        self.palm_oil_num = 0
        self.fruit_depth = 0
        self.pitch_direction = 0
        self.yaw_direction = 0
        self.yaw_angle = 0.0

        # Process Variables
        self.state = "Tilt Arm"
        self.first_detect = True
        self.current_harvest_time = 0
        self.target_harvest_time = 0
        self.actuator_speed = 0.03  # m/s
        self.harvest_offset = 0.1  # m
        self.timer_counter = 0
        self.harvest_end = False

        self.set_tilt_speed = 0
        self.set_extend_speed = 0
        self.set_rotate_speed = 0
        self.set_vibrate_speed = 0
        self.set_direction = 0

        # Motor Variables
        self.rotate_speed = 50
        self.tilt_speed = 255
        self.extend_speed = 255
        self.vibrate_speed = 255
        self.direction = 0

    def get_fruit_depth(self, msg):
        self.detected = msg.detected
        self.fruit_depth = msg.fruit_depth
        self.target_harvest_time = (
                                               self.fruit_depth - self.harvest_offset) / self.actuator_speed - self.current_harvest_time
        self.palm_oil_num = msg.palm_oil_num
        self.pitch_direction = msg.pitch_direction
        self.yaw_direction = msg.yaw_direction
        self.yaw_angle = msg.yaw

    def confirm_action_callback(self, response):
        response.success = self.harvest_end
        return response

    def timer_callback(self):
        msg = MotorCommand()
        self.set_tilt_speed = 0
        self.set_extend_speed = 0
        self.set_rotate_speed = 0
        self.set_vibrate_speed = 0
        self.set_direction = 0
        self.harvest_end = False

        if self.detected and self.first_detect:
            self.state = "Tilt Arm"
        else:
            self.state = ""
            self.first_detect = False

        if self.state == "Tilt Arm":
            # Tilt the arm
            if self.pitch_direction == 1:
                self.set_tilt_speed = self.tilt_speed
                self.set_direction += 8
                # Move linear actuator back in case collision
                if round(self.target_harvest_time, 2) < round(self.current_harvest_time, 2):
                    self.current_harvest_time -= self.timer_period
                    self.set_extend_speed = self.extend_speed
                    self.set_direction += 0

            elif self.pitch_direction == -1:
                self.set_tilt_speed = self.tilt_speed
                self.set_direction += 0
                # Move linear actuator back in case collision
                if round(self.target_harvest_time, 2) < round(self.current_harvest_time, 2):
                    self.current_harvest_time -= self.timer_period
                    self.set_extend_speed = self.extend_speed
                    self.set_direction += 0

            else:
                self.state = "Rotate Arm"

        if self.state == "Rotate Arm":
            # Rotate arm
            if self.yaw_direction == 1:
                self.set_rotate_speed = self.rotate_speed
                self.set_direction += 4
            elif self.yaw_direction == -1:
                self.set_rotate_speed = self.rotate_speed
                self.set_direction += 0
            else:
                self.set_rotate_speed = 0

            # Extend or retract arm
            if round(self.target_harvest_time, 2) > round(self.current_harvest_time, 2):
                self.current_harvest_time += self.timer_period
                self.set_extend_speed = self.extend_speed
                self.set_direction += 16
            elif round(self.target_harvest_time, 2) < round(self.current_harvest_time, 2):
                self.current_harvest_time -= self.timer_period
                self.set_extend_speed = self.extend_speed
                self.set_direction += 0
            else:
                self.set_extend_speed = 0

            if self.set_rotate_speed == 0 and self.set_extend_speed == 0:
                self.state = "Cut"

        if self.state == "Cut":
            self.set_vibrate_speed = self.vibrate_speed
            self.set_extend_speed = self.extend_speed
            self.set_direction += 16
            self.timer_counter += self.timer_period

            # 30 seconds cut
            if self.timer_counter >= 30:
                self.current_harvest_time += 0.1 / self.actuator_speed
                self.timer_counter = 0
                self.state = "Retract Arm"

        if self.state == "Retract Arm":
            if self.yaw_angle <= -0.1:
                self.set_rotate_speed = self.rotate_speed
                self.set_direction += 4
            elif self.yaw_angle >= 0.1:
                self.set_rotate_speed = self.rotate_speed
                self.set_direction += 0
            else:
                self.set_rotate_speed = 0

            if round(self.current_harvest_time, 2) > 0:
                self.current_harvest_time -= self.timer_period
                self.set_extend_speed = self.extend_speed
                self.set_direction += 0
                self.state = ""

        if self.state == "":
            self.first_detect = True
            self.harvest_end = True

        msg.left_speed = 0
        msg.right_speed = 0
        msg.rotate_speed = self.set_rotate_speed
        msg.tilt_speed = self.set_tilt_speed
        msg.extend_speed = self.set_extend_speed
        msg.vibrate_speed = self.set_vibrate_speed
        msg.direction = self.set_direction

        self.motor_publisher.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.rotate_speed)


def main(args=None):
    rclpy.init(args=args)

    fruit_harvest_node = FruitHarvestNode()

    rclpy.spin(fruit_harvest_node)

    fruit_harvest_node.destroy_node()
    rclpy.shutdown()
    