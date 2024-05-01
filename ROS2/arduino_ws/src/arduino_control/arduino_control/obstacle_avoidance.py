import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import LidarScan
from my_robot_interfaces.msg import LaserScan


class ObstacleAvoidanceNode(Node):
    def __init__(self):
        super().__init__('lidar_node')
        self.publisher = self.create_publisher(LidarScan, 'lidar_scan', 10)
        timer_period = 0.1  # seconds (adjust as needed)
        self.timer = self.create_timer(timer_period, self.process_lidar_scan)
        self.detected = False
        self.subscription = self.create_subscription(LaserScan, 'laser_scan', self.connect_lidar, 10)
        self.subscription
        self.range = []
        self.angle = []
        self.sub = False

    def connect_lidar(self, msg):
        self.range = msg.ranges
        self.angle = msg.angles
        self.sub = True

    def process_lidar_scan(self):
        scan_msg = LidarScan()
        if self.sub:
            self.detected = False
            filtered_angles = []
            filtered_distances = []
            for angle, distance in zip(self.angle, self.range):
                if 3.2 > angle > 0.8 or -3.2 < angle < -0.8:
                    filtered_angles.append(angle)
                    filtered_distances.append(distance)  
            for r, a in zip(filtered_distances, filtered_angles):
                if r < 0.4 and r != 0:
                    # self.get_logger().info("Angle: %f Distance: %f" % (a, r))
                    # self.get_logger().info("Danger at")  # You can add further actions based on this information
                    self.detected = True
                    scan_msg.angle.append(a)
                    scan_msg.range.append(r)
            if self.detected:
                scan_msg.detected = True
            else:
                scan_msg.detected = False
                scan_msg.angle = []
                scan_msg.range = []

            self.publisher.publish(scan_msg)
            self.sub = False
        else:
            self.get_logger().error("No Lidar data is obtained")

    def stop(self):
        if self.laser.isScanning:
            self.laser.turnOff()
        self.laser.disconnecting()
        self.destroy_node()
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    lidar_controller_node = ObstacleAvoidanceNode()
    rclpy.spin(lidar_controller_node)
    lidar_controller_node.stop()


if __name__ == "__main__":
    main()
