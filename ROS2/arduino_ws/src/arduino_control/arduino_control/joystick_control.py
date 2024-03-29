import rclpy
from my_robot_interfaces.msg import LidarScan, Joystick, MotorCommand
from rclpy.node import Node


class LocomotionControl(Node):
    def __init__(self):
        super().__init__('joystick_control')

        # Create nodes
        self.joystick_subscription = self.create_subscription(Joystick, 'joystick', self.command_callback, 10)
        self.joystick_subscription
        self.obstacle_subscription = self.create_subscription(LidarScan, 'lidar_scan', self.obstacle_callback, 10)
        self.obstacle_subscription
        self.motor_publisher = self.create_publisher(MotorCommand, 'motor_command', 10)
        self.serial_sender = self.create_timer(0.01, self.send_command)
        self.ros_command = 0
        self.obstacle = False
        self.forward_detected = False
        self.backward_detected = False
        self.target_left_speed = 70
        self.target_right_speed = 70
        self.target_rotate_left_speed = 60
        self.target_rotate_right_speed = 60

    def __del__(self):
        if self.serial_port.is_open:
            self.serial_port.close()
            self.get_logger().info("Serial port closed.")

    def send_command(self):
        command = self.ros_command
        msg = MotorCommand()

        if command == 'Up':
            msg.left_speed = self.target_left_speed
            msg.right_speed = self.target_right_speed
            msg.direction += 3
        elif command == 'Down':
            msg.left_speed = self.target_left_speed
            msg.right_speed = self.target_right_speed
            msg.direction += 0
        elif command == 'Left':
            msg.left_speed = self.target_rotate_left_speed
            msg.right_speed = self.target_right_speed
            msg.direction += 3
        elif command == 'Right':
            msg.left_speed = self.target_left_speed
            msg.right_speed = self.target_rotate_right_speed
            msg.direction += 3
        elif command == "Rotate Left":
            msg.left_speed = self.target_rotate_left_speed
            msg.right_speed = self.target_rotate_right_speed
            msg.direction += 2
        elif command == "Rotate Right":
            msg.left_speed = self.target_rotate_left_speed
            msg.right_speed = self.target_rotate_right_speed
            msg.direction += 1
        elif command == 'No':
            msg.left_speed = 0
            msg.right_speed = 0
            msg.direction += 0
            
        if (self.forward_detected and command == 'Up'):
            msg.left_speed = 0
            msg.right_speed = 0
            msg.direction += 0

        msg.rotate_speed = 0
        msg.tilt_speed = 0
        msg.extend_speed = 0
        msg.vibrate_speed = 0
        self.get_logger().info("Unknown command received: %s" % str(command))
        self.motor_publisher.publish(msg)

    def command_callback(self, msg):
        # Translate ROS 2 command to Arduino command
        buttons = msg.button
        axes = msg.axes
        axes_name = msg.axes_name
        if buttons:
            for button in buttons:
                if button == 'Up':
                    self.ros_command = 'Up'
                elif button == 'Down':
                    self.ros_command = 'Down'
                elif button == 'Right':
                    self.ros_command = 'Right'
                elif button == 'Left':
                    self.ros_command = 'Left'
                elif button == 'LB':
                    self.ros_command = 'Rotate Left'
                elif button == 'RB':
                    self.ros_command = 'Rotate Right'
                elif button == 'No':
                    self.ros_command = 'No'
        else:
            self.ros_command = 'No'

    def obstacle_callback(self, msg):
        # Translate ROS 2 command to Arduino command
        self.obstacle = msg.detected
        forward_obstacle = 0
        self.forward_detected = False
        self.backward_detected = False
        for angle in msg.angle:
            if 1 > angle > -1:
                forward_obstacle += 1
        if forward_obstacle > 3:
            self.forward_detected = True
            self.get_logger().warn("Forward Obstacle")


def main():
    rclpy.init()
    node = LocomotionControl()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
