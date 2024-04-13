import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import LaserScan, FindObstacle


class FindObstacleNode(Node):

    def __init__(self):

        super().__init__('FindObstacle')
        self.lidar_subscription = self.create_subscription(LaserScan, 'laser_scan', self.lidar_callback, 10)
        self.lidar_subscription
        self.publisher_ = self.create_publisher(FindObstacle, 'find_obstacle', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.range = []
        self.angle = []
        self.sub = False

    def lidar_callback(self, msg):
        self.range = msg.ranges
        self.angle = msg.angles
        self.sub = True
    
    def timer_callback(self):
        if self.sub:
            msg = FindObstacle()     
            filtered_angles = []
            filtered_distances = []
            for angle, distance in zip(self.angle, self.range):
                if 3.2 > angle > 0.8 or -3.2 < angle < -0.8:
                    filtered_angles.append(angle)
                    filtered_distances.append(distance)   
            msg.nearest_distance1 = min(filter(lambda x: x != 0, filtered_distances))
            msg.nearest_angle1 = filtered_angles[filtered_distances.index(msg.nearest_distance1)]
            msg.nearest_distance2 = float('inf')
            msg.nearest_angle2 = 0.0
            for angle, distance in zip(filtered_angles, filtered_distances):
                if distance != 0 and distance != msg.nearest_distance1:
                    if abs(angle - msg.nearest_angle1) >= 1 and distance < msg.nearest_distance2:
                        msg.nearest_distance2 = distance
                        msg.nearest_angle2 = angle

            if msg.nearest_distance1 < 40:
                msg.reach = True

            # self.get_logger().info(str(msg.nearest_distance1))
            # self.get_logger().info("")
            # self.get_logger().info(str(msg.nearest_angle1))
            self.publisher_.publish(msg)
            self.sub = False
        else:
            self.get_logger().error("No Lidar data is obtained")


def main(args=None):
    rclpy.init(args=args)
    findobstacle_node = FindObstacleNode()  # Corrected variable name
    try:
        rclpy.spin(findobstacle_node)  # Corrected variable name
    except KeyboardInterrupt:
        pass

    findobstacle_node.destroy_node()  # Corrected variable name
    rclpy.shutdown()


if __name__ == '__main__':
    main()
