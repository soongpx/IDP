import ydlidar
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import LaserScan
import time
import serial.tools.list_ports


class LidarControllerNode(Node):
    def __init__(self):
        super().__init__('lidar_node')
        self.publisher = self.create_publisher(LaserScan, 'laser_scan', 10)
        timer_period = 0.05  # seconds (adjust as needed)
        self.timer = self.create_timer(timer_period, self.process_lidar_scan)
        self.laser = None
        self.pi = 3.141592653589793238462643383279502884197

    def connect_lidar(self):
        while rclpy.ok():
            try:
                if self.laser is None:
                    self.laser = ydlidar.CYdLidar()
                    ydlidar.os_init()

                lidar_ports = []
                ports = serial.tools.list_ports.comports()
                for port in ports:
                    print(port.description)
                    if 'CP2102' in port.description:
                        lidar_ports.append(port.device)

                if not ports:
                    self.get_logger().error("No lidar ports found. Retrying...")
                    time.sleep(1)  # Wait before retrying
                    continue

                port = list(lidar_ports)[-1]  # Select the last available port
                self.get_logger().info("LIDAR port: %s" % port)

                self.laser.setlidaropt(ydlidar.LidarPropSerialPort, port)
                self.laser.setlidaropt(ydlidar.LidarPropIgnoreArray, "")
                self.laser.setlidaropt(ydlidar.LidarPropSerialBaudrate, 115200)
                self.laser.setlidaropt(ydlidar.LidarPropLidarType, ydlidar.TYPE_TRIANGLE)
                self.laser.setlidaropt(ydlidar.LidarPropDeviceType, ydlidar.YDLIDAR_TYPE_SERIAL)
                self.laser.setlidaropt(ydlidar.LidarPropSampleRate, 3)
                self.laser.setlidaropt(ydlidar.LidarPropAbnormalCheckCount, 4)
                self.laser.setlidaropt(ydlidar.LidarPropFixedResolution, True)
                self.laser.setlidaropt(ydlidar.LidarPropReversion, True)
                self.laser.setlidaropt(ydlidar.LidarPropInverted, True)
                self.laser.setlidaropt(ydlidar.LidarPropAutoReconnect, True)
                self.laser.setlidaropt(ydlidar.LidarPropSingleChannel, True)
                self.laser.setlidaropt(ydlidar.LidarPropIntenstiy, False)
                self.laser.setlidaropt(ydlidar.LidarPropSupportMotorDtrCtrl, True)
                self.laser.setlidaropt(ydlidar.LidarPropMaxAngle, 180.0)
                self.laser.setlidaropt(ydlidar.LidarPropMinAngle, -180.0)
                self.laser.setlidaropt(ydlidar.LidarPropMaxRange, 12.0)
                self.laser.setlidaropt(ydlidar.LidarPropMinRange, 0.1)
                self.laser.setlidaropt(ydlidar.LidarPropScanFrequency, 10.0)


                ret = self.laser.initialize()
                if ret:
                    ret = self.laser.turnOn()
                    if ret:
                        self.get_logger().info("Lidar initialized and turned on.")
                        return True
                    else:
                        self.get_logger().error("Failed to turn on the lidar.")
                else:
                    self.get_logger().error("Failed to initialize the lidar.")
            except Exception as e:
                self.get_logger().error("Error connecting lidar: %s" % str(e))

            # Wait before retrying
            time.sleep(1)
            self.laser = None
            self.get_logger().info("Retrying lidar connection...")

        return False

    def process_lidar_scan(self):
        if self.laser is not None and self.laser.isScanning and ydlidar.os_isOk():
            scan_msg = LaserScan()
            scan = ydlidar.LaserScan()

            if self.laser.doProcessSimple(scan):
                scan_msg.header.frame_id = "laser_frame"
                scan_msg.header.stamp = self.get_clock().now().to_msg()
                scan_msg.angle_min = -180.0 / 180 * self.pi
                scan_msg.angle_max = 180.0 / 180 * self.pi
                scan_msg.angle_increment = scan.config.angle_increment
                scan_msg.time_increment = scan.config.time_increment
                scan_msg.scan_time = scan.config.scan_time
                scan_msg.range_min = 0.1
                scan_msg.range_max = 12.0

                for point in scan.points:
                    if scan_msg.range_min > point.range > scan_msg.range_max:
                        point.range = 0
                    scan_msg.angles.append(point.angle)
                    scan_msg.ranges.append(point.range)
                    scan_msg.intensities.append(point.intensity)

                # Publish the LaserScan message
                self.publisher.publish(scan_msg)
            else:
                self.get_logger().error("Failed to get Lidar data")
                # Attempt to reconnect lidar
                self.connect_lidar()

    def stop(self):
        if self.laser is not None and self.laser.isScanning:
            self.laser.turnOff()
            self.laser.disconnecting()
        self.destroy_node()
        rclpy.shutdown()

    def mapping_angle_to_360(self, angle):
        return (angle + self.pi) * (180 / self.pi)


def main(args=None):
    rclpy.init(args=args)
    lidar_controller_node = LidarControllerNode()

    if lidar_controller_node.connect_lidar():
        rclpy.spin(lidar_controller_node)

    lidar_controller_node.stop()


if __name__ == "__main__":
    main()
