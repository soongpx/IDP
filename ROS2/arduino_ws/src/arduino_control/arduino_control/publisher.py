import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import MotorCommand
from std_msgs.msg import Int32


class MinimalPublisher(Node):
    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(MotorCommand, 'motor_command', 10)
        self.subscription = self.create_subscription(Int32, 'motor_speed', self.speed_callback, 10)
        self.subscription  # prevent unused variable warning
        self.timer_period = 0.1  # seconds
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        self.i = 0

    def speed_callback(self, msg):
        self.get_logger().info('Received motor speed: "%d"' % msg.data)
        # You can use the received motor speed value here to adjust the command
        self.i = msg.data

    def timer_callback(self):
        msg = MotorCommand()
        msg.left_speed = self.i
        msg.right_speed = 100
        msg.rotate_speed = 50
        msg.tilt_speed = 60
        msg.extend_speed = 80
        msg.vibrate_speed = 30
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.left_speed)


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
