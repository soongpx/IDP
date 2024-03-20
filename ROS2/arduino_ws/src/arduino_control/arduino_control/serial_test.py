import rclpy
from rclpy.node import Node
import serial
import time

class LocomotionControl(Node):
    def __init__(self):
        super().__init__('locomotion_control')

        # Initialize serial port
        self.header_byte = 0x33
        self.init_serial_port()

        self.create_timer(0.05, lambda: self.send_data(200, 100, 50, 60, 80, 30))

        # Initialize variables
        self.ros_command = 0
        self.obstacle_detected = False
        self.forward_detected = False
        self.backward_detected = False

    def init_serial_port(self):
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
        except serial.SerialException as e:
            self.get_logger().error(f"Serial communication error: {e}")

    def get_input(self):
        if self.serial_port.in_waiting > 0:
            input_data = self.serial_port.read(3)
            print(f'Received data: {int(input_data[0])}, {int(input_data[1])}, {int(input_data[2])}')
            if input_data[0] == self.header_byte and len(input_data) == 3:
                # Process the received data
                print("Header byte matched. Processing data...")

    def send_data(self, target_left_motor_speed: int, target_right_motor_speed: int, target_rotating_speed: int,
                target_tilting_speed: int, target_extend_speed: int, target_vibrate_speed: int):
        target_speeds = [target_left_motor_speed, target_right_motor_speed, target_rotating_speed,
                        target_tilting_speed, target_extend_speed, target_vibrate_speed]
        data = bytearray([self.header_byte])  # Start with the header byte
        data.extend(speed.to_bytes(1, byteorder='big')[0] for speed in target_speeds)  # Append each speed
        checksum = sum(data) % 256
        data.append(checksum)  # Append checksum
        print(f'Sending data: {int(data[0])}, {int(data[1])}, {int(data[2])}, {int(data[3])}, {int(data[4])}, {int(data[5])}, {int(data[6])}, {int(data[7])}')
        self.serial_port.write(data)
        self.get_input()

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
