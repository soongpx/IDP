import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import MotorCommand
import serial


class LocomotionControl(Node):
    def __init__(self):
        super().__init__('locomotion_control')

        # Initialize serial port
        self.header_byte = 0x33

        # Initialize serial port settings
        SERIAL_PORT = '/dev/ttyACM0'  # Change this to match your Arduino's serial port
        BAUD_RATE = 115200

        try:
            self.serial_port = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
            if not self.serial_port.is_open:
                self.get_logger().error("Failed to open serial port.")
                return
            if self.serial_port.readline().decode().strip() == "Start Arduino":
                self.get_logger().info(f"Serial port {SERIAL_PORT} opened successfully.")
            # self.serial_port.close()
        except serial.SerialException as e:
            self.get_logger().error(f"Serial communication error: {e}")

        self.create_timer(0.01, self.send_data)
        self.motor_subscription = self.create_subscription(MotorCommand, 'motor_command', self.motor_command_callback, 10)
        self.motor_subscription

        # Initialize variables
        self.target_speeds = []

    def get_input(self):
        # input_data = [0, 0, 0]
        if self.serial_port.in_waiting > 0:
            input_data = self.serial_port.read(3)
            # self.get_logger().info(f'Received data: {str(input_data[0])}, {str(input_data[1])}, {str(input_data[2])}')
            if input_data[0] == self.header_byte and len(input_data) == 3:
                # Process the received data
                # self.get_logger().info("Header byte matched. Processing data...")
                print("")

    def send_data(self):
        # data = [0, 0, 0, 0, 0, 0, 0, 0]
        if self.target_speeds:
            data = bytearray([self.header_byte])  # Start with the header byte
            data.extend(speed.to_bytes(1, byteorder='big')[0] for speed in self.target_speeds)  # Append each speed
            checksum = sum(data) % 256
            data.append(checksum)  # Append checksum
            # self.get_logger().info(
            #     f'Sending data: {str(data[0])}, {str(data[1])}, {str(data[2])}, {str(data[3])}, {str(data[4])}, {str(data[5])}, {str(data[6])}, {str(data[7])}, {str(data[8])}')
            self.serial_port.write(data)
            self.get_input()
        else:
            self.get_logger().error(f"Serial communication error")

    def motor_command_callback(self, msg):
        self.target_speeds = [msg.left_speed, msg.right_speed, msg.rotate_speed, msg.tilt_speed, msg.extend_speed,
                              msg.vibrate_speed, msg.direction]

    def __del__(self):
        if self.serial_port.is_open:
            self.serial_port.close()
            self.get_logger().info("Serial port closed.")


def main(args=None):
    rclpy.init(args=args)
    node = LocomotionControl()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
