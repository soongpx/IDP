import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import FruitDepth, MotorCommand, Harvest


class MinimalPublisher(Node):
    def __init__(self):
        super().__init__('fruit_harvest')
        self.subscription = self.create_subscription(FruitDepth, 'fruit_depth', self.get_fruit_depth, 10)
        self.subscription  # prevent unused variable warning
        self.motor_publisher = self.create_publisher(MotorCommand, 'motor_command', 10)
        self.harvest_publisher = self.create_publisher(MotorCommand, 'motor_command', 10)
        self.timer_period = 0.01  # seconds
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        # Camera Variables
        self.detected = False
        self.fruit_depth = 0
        self.palm_oil_num = 0
        self.fruit_depth = 0
        self.pitch_direction = 0
        self.yaw_direction = 0

        # Process Variables
        self.current_harvest_time = 0
        self.target_harvest_time = 0
        self.actuator_speed = 0.03 # m/s
        self.harvest_offset = 0.1 # m

        # Motor Variables
        self.rotate_speed = 50
        self.tilt_speed = 255
        self.extend_speed = 255
        self.vibrate_speed = 255
        self.direction = 0

    def get_fruit_depth(self, msg):
        self.detected = msg.detected
        self.fruit_depth = msg.fruit_depth
        self.target_harvest_time = (self.fruit_depth - self.harvest_offset) / self.actuator_speed - self.current_harvest_time 
        self.palm_oil_num = msg.palm_oil_num
        self.pitch_direction = msg.pitch_direction
        self.yaw_direction = msg.yaw_direction

    def timer_callback(self):
        msg = MotorCommand()
        harvest_msg = Harvest()
        msg.left_speed = 0
        msg.right_speed = 0
        msg.direction = 0

        if self.detected:
            if round(self.target_harvest_time, 2) < round(self.current_harvest_time, 2):
                self.current_harvest_time -= self.timer_period
                msg.extend_speed = self.extend_speed
                msg.direction += 0
            if self.pitch_direction == 1:
                msg.tilt_speed = self.tilt_speed
                msg.direction += 8
            elif self.pitch_direction == -1:
                msg.tilt_speed = self.tilt_speed
                msg.direction += 0
            else:
                msg.tilt_speed = 0
            
                if self.yaw_direction == 1:
                    msg.rotate_speed = self.rotate_speed
                    msg.direction += 4
                elif self.yaw_direction == -1:
                    msg.rotate_speed = self.rotate_speed
                    msg.direction += 4
                else:
                    msg.rotate_speed = 0
                
                if round(self.target_harvest_time, 2) > round(self.current_harvest_time, 2):
                    self.current_harvest_time += self.timer_period
                    msg.extend_speed = self.extend_speed
                    msg.direction += 16
                elif round(self.target_harvest_time, 2) < round(self.current_harvest_time, 2):
                    self.current_harvest_time -= self.timer_period
                    msg.extend_speed = self.extend_speed
                    msg.direction += 0
                else:
                    msg.extend_speed = 0

            msg.vibrate_speed = self.vibrate_speed

        else:
            msg.rotate_speed = 0
            msg.tilt_speed = 0
            msg.extend_speed = 0
            msg.vibrate_speed = 0


        self.motor_publisher.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.rotate_speed)


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
