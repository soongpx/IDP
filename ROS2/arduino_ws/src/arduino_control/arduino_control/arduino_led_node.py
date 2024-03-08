import rclpy
from std_msgs.msg import String
from rclpy.node import Node

import serial
import serial.tools.list_ports
import ydlidar

class ArduinoControl(Node):

    def __init__(self):
        super().__init__('arduino_control_node')

        # Find ports of MCU


        ports = ydlidar.lidarPortList()

        port = list(ports.values()).pop(-1)
        # arduino_ports = [
        #     p.device
        #     for p in serial.tools.list_ports.comports()
        #     if 'Arduino' in p.description or 'ST' in p.description # may need tweaking to match new arduinos
        # ]
        # if not arduino_ports:
        #     self.get_logger().error("No MCU found")
        # if len(arduino_ports) > 1:
        #     self.get_logger().warn("Multiple MCU found - using the first")

        # Declare Serial Port
        # SERIAL_PORT = arduino_ports[0] # Change this to your Arduino's serial port
        SERIAL_PORT = port
        BAUD_RATE = 115200

        # Create nodes
        self.subscription = self.create_subscription(String, 'motor_command', self.command_callback, 1)
        self.serial_port = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        if not self.serial_port.is_open:
            self.get_logger().error("Failed to open serial port.")
            return
        self.get_logger().info(f"Serial port {self.serial_port} opened successfully.")

    def __del__(self):
        if self.serial_port.is_open:
            self.serial_port.close()
            self.get_logger().info("Serial port closed.")

    def send_command(self, command):
        try:
            self.get_logger().info("Unknown command received: %s" % str(command))
            self.serial_port.write(command.to_bytes(1,'big'))
        except serial.SerialException as e:
            self.get_logger().error("Serial communication error: %s" % str(e))

    def command_callback(self, msg):
        # Translate ROS 2 command to Arduino command
        ros_command = msg.data
        if ros_command == 'forward':    
            self.send_command(192)
        elif ros_command == 'backward':
            self.send_command(128)
        elif ros_command == 'stop':
            self.send_command(0)

def main():
    rclpy.init()
    node = ArduinoControl()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
