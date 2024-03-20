import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import Joystick
import pygame

class NintendoSwitchControllerPublisher(Node):
    def __init__(self):
        super().__init__('joystick_node')
        pygame.init()
        self.publisher_ = self.create_publisher(Joystick, 'joystick', 10)
        self.timer_ = self.create_timer(0.1, self.publish_controller_data)
        self.joysticks = {}
        self.done = False
        self.connected = False
        self.joystick_connected = None

    def publish_controller_data(self):
        msg = Joystick()
        msg.axes = []
        msg.axes_name = []
        msg.button = []
        
        if not self.done:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.done = True  # Flag that we are done so we exit this loop.

                # Handle hotplugging
                if event.type == pygame.JOYDEVICEADDED:
                    # This event will be generated when the program starts for every
                    # joystick, filling up the list without needing to create them manually.
                    joy = pygame.joystick.Joystick(event.device_index)
                    self.joysticks[joy.get_instance_id()] = joy
                    print(f"Joystick {joy.get_instance_id()} connected")
                    self.connected = True
                    self.joystick_connected = joy.get_instance_id()

                if event.type == pygame.JOYDEVICEREMOVED:
                    self.joystick_connected = None
                    self.connected = False
                    del self.joysticks[event.instance_id]
                    print(f"Joystick {event.instance_id} disconnected")

            if self.connected:
                buttons = self.joysticks[self.joystick_connected].get_numbuttons()
                for i in range(buttons):
                    button = self.joysticks[self.joystick_connected].get_button(i)
                    if button:
                        if i == 0:
                            msg.button.append('A')
                        elif i == 1:
                            msg.button.append('B')
                        elif i == 2:
                            msg.button.append('Y')
                        elif i == 3:
                            msg.button.append('X')
                        elif i == 4:
                            msg.button.append('Z')
                        elif i == 5:
                            msg.button.append('LB')
                        elif i == 6:
                            msg.button.append('RB')
                        elif i == 7:
                            msg.button.append('LT')
                        elif i == 8:
                            msg.button.append('RT')
                        elif i == 9:
                            msg.button.append('Back')
                        elif i == 10:
                            msg.button.append('Start')
                            self.joysticks[self.joystick_connected].rumble(0, 0.7, 500)
                        self.get_logger().info(msg.button[-1])
                
                hats = self.joysticks[self.joystick_connected].get_numhats()
                for i in range(hats):
                    hat = self.joysticks[self.joystick_connected].get_hat(i)
                    if hat[0] == 1:
                        msg.button.append("Right")
                        self.get_logger().info(msg.button[-1])
                    elif hat[0] == -1:
                        msg.button.append("Left")
                        self.get_logger().info(msg.button[-1])
                    elif hat[1] == 1:
                        msg.button.append("Up")
                        self.get_logger().info(msg.button[-1])
                    elif hat[1] == -1:
                        msg.button.append("Down")
                        self.get_logger().info(msg.button[-1])

                axes = self.joysticks[self.joystick_connected].get_numaxes()
                for i in range(axes):
                    axis = self.joysticks[self.joystick_connected].get_axis(i)
                    axis = self.limit_axis(axis)
                    if abs(axis) > 0:
                        msg.axes.append(axis)  
                        if i == 0:
                            msg.axes_name.append('LX')
                        if i == 1:
                            msg.axes_name.append('LY')
                        if i == 2:
                            msg.axes_name.append('RX')
                        if i == 3:
                            msg.axes_name.append('RY')
                        self.get_logger().info(str(axis))
                        self.get_logger().info(msg.axes_name[-1])

            self.publisher_.publish(msg)
    
    def limit_axis(self, axis):
        if abs(axis) < 0.05:
            return 0
        else:
            return axis
        
    def __del__(self):
        self.done = True
        self.destroy_node()
        pygame.quit()


def main(args=None):
    rclpy.init(args=args)
    controller_publisher = NintendoSwitchControllerPublisher()
    rclpy.spin(controller_publisher)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
