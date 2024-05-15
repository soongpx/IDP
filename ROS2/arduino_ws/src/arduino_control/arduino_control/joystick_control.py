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
        self.loco_command = ''
        self.rotate_command = 0
        self.tilt_command = 0
        self.extend_command = 0
        self.vibrate_command = 0

        self.obstacle = False
        self.forward_detected = False

        self.target_left_speed = 90
        self.target_right_speed = 85
        self.target_rotate_left_speed = 150
        self.target_rotate_right_speed = 140
        self.rotate_speed = 50
        self.tilt_speed = 255
        self.extend_speed = 255
        self.vibrate_speed = 240
        self.previous_direction = 0

    def __del__(self):
        if self.serial_port.is_open:
            self.serial_port.close()
            self.get_logger().info("Serial port closed.")

    def send_command(self):
        msg = MotorCommand()
        msg.direction = 0

        if self.loco_command == 'Up':
            msg.left_speed = self.target_left_speed
            msg.right_speed = self.target_right_speed
            msg.direction += 3
            self.previous_direction = 3
        elif self.loco_command == 'Down':
            msg.left_speed = self.target_left_speed
            msg.right_speed = self.target_right_speed
            msg.direction += 0
            self.previous_direction = 0
        elif self.loco_command == 'Left':
            msg.left_speed = self.target_left_speed - 30
            msg.right_speed = self.target_right_speed + 10
            msg.direction += 3
            self.previous_direction = 3
        elif self.loco_command == 'Right':
            msg.left_speed = self.target_left_speed + 10
            msg.right_speed = self.target_right_speed - 30
            msg.direction += 3
            self.previous_direction = 3
        elif self.loco_command == "Rotate Left":
            msg.left_speed = self.target_rotate_left_speed
            msg.right_speed = self.target_rotate_right_speed
            msg.direction += 2
            self.previous_direction = 2
        elif self.loco_command == "Rotate Right":
            msg.left_speed = self.target_rotate_left_speed
            msg.right_speed = self.target_rotate_right_speed
            msg.direction += 1
            self.previous_direction = 1
        elif self.loco_command == '':
            msg.left_speed = 0
            msg.right_speed = 0
            msg.direction += self.previous_direction
            
        # if (self.forward_detected and self.loco_command == 'Up'):
        #     msg.left_speed = 0
        #     msg.right_speed = 0
        #     msg.direction += 0

        if self.rotate_command == 1:
            msg.rotate_speed = self.rotate_speed
            msg.direction += 4
        elif self.rotate_command == -1:
            msg.rotate_speed = self.rotate_speed
            msg.direction += 0
        else:
            msg.rotate_speed = 0

        if self.tilt_command == 1:
            msg.tilt_speed = self.tilt_speed
            msg.direction += 8
        elif self.tilt_command == -1:
            msg.tilt_speed = self.tilt_speed
            msg.direction += 0
        else:
            msg.tilt_speed = 0

        if self.extend_command == 1:
            msg.extend_speed = self.extend_speed
            msg.direction += 16
        elif self.extend_command == -1:
            msg.extend_speed = self.extend_speed
            msg.direction += 0
        else:
            msg.extend_speed = 0

        if self.vibrate_command == 1:
            msg.vibrate_speed = self.vibrate_speed
            msg.direction += 32
        elif self.vibrate_command == -1:
            msg.vibrate_speed = self.vibrate_speed
            msg.direction += 0
        else:
            msg.vibrate_speed = 0

        self.motor_publisher.publish(msg)

    def command_callback(self, msg):
        # Translate ROS 2 command to Arduino command
        buttons = msg.button
        axes = msg.axes
        axes_name = msg.axes_name

        self.loco_command = ''
        self.rotate_command = 0
        self.tilt_command = 0
        self.extend_command = 0

        if buttons:
            for button in buttons:
                # Locomotion
                if button == 'Up':
                    self.loco_command = 'Up'
                elif button == 'Down':
                    self.loco_command = 'Down'
                elif button == 'Right':
                    self.loco_command = 'Right'
                elif button == 'Left':
                    self.loco_command = 'Left'
                elif button == 'LB':
                    self.loco_command = 'Rotate Left'
                elif button == 'RB':
                    self.loco_command = 'Rotate Right'
                elif button == 'No':
                    self.loco_command = ''
                
                # Mechanism
                if button == 'Y':
                    self.tilt_command = 1
                elif button == 'A':
                    self.tilt_command = -1

                if button == 'B':
                    self.extend_command = 1
                elif button == 'X':
                    self.extend_command = -1

                if button == 'RT':
                    self.rotate_command = 1
                elif button == 'LT':
                    self.rotate_command = -1

                if button == 'Start':
                    self.vibrate_command = 1
                elif button == 'Back':
                    self.vibrate_command = 0

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
