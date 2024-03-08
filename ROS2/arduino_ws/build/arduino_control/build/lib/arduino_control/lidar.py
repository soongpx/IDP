import ydlidar
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import LidarScan

class LidarControllerNode(Node):
    def __init__(self):
        super().__init__('lidar_node')
        self.publisher = self.create_publisher(LidarScan, 'lidar_scan', 10)
        timer_period = 0.05  # seconds (adjust as needed)
        self.timer = self.create_timer(timer_period, self.process_lidar_scan)
        self.laser = ydlidar.CYdLidar()
        self.detected = False

    def connect_lidar(self):
        ydlidar.os_init()
        ports = ydlidar.lidarPortList()

        if not ports:
            self.get_logger().error("No lidar ports found.")
            return False

        port = list(ports.values())[-1]  # Select the last available port
        self.get_logger().info("Using port: %s" % port)

        self.laser.setlidaropt(ydlidar.LidarPropSerialPort, port)
        self.laser.setlidaropt(ydlidar.LidarPropSerialBaudrate, 115200)
        self.laser.setlidaropt(ydlidar.LidarPropLidarType, ydlidar.TYPE_TRIANGLE)
        self.laser.setlidaropt(ydlidar.LidarPropDeviceType, ydlidar.YDLIDAR_TYPE_SERIAL)
        self.laser.setlidaropt(ydlidar.LidarPropScanFrequency, 10.0)
        self.laser.setlidaropt(ydlidar.LidarPropSampleRate, 3)
        self.laser.setlidaropt(ydlidar.LidarPropSingleChannel, True)

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
        return False

    def process_lidar_scan(self):
        scan_msg = LidarScan()
        scan = ydlidar.LaserScan()
        if self.laser.isScanning and ydlidar.os_isOk():
            if self.laser.doProcessSimple(scan):
                self.detected = False
                for point in scan.points:
                    # self.get_logger().info("Angle: %f Distance: %f" % (point.angle, point.range))
                    if point.range < 0.3 and point.range != 0:
                        self.get_logger().info("Danger")  # You can add further actions based on this information
                        self.detected = True
                        scan_msg.angle.append(point.angle)
                        scan_msg.range.append(point.range)
                if self.detected == True:
                    scan_msg.detected = True
                else:
                    scan_msg.detected = False
                    scan_msg.angle = []
                    scan_msg.range = []
                        
                self.publisher.publish(scan_msg)
            else:
                self.get_logger().error("Failed to get Lidar data")

    def stop(self):
        if self.laser.isScanning:
            self.laser.turnOff()
        self.laser.disconnecting()
        self.destroy_node()
        rclpy.shutdown()
        

def main(args=None):
    rclpy.init(args=args)
    lidar_controller_node = LidarControllerNode()

    if lidar_controller_node.connect_lidar():
        rclpy.spin(lidar_controller_node)
    
    lidar_controller_node.stop()

if __name__ == "__main__":
    main()
