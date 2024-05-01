import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
import math

class WaypointSetter(Node):
    def __init__(self):
        super().__init__('waypoint_setter')
        self.publisher = self.create_publisher(PoseStamped, '/goal_pose', 10)
        self.odom_subscription = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10)
        self.odom_subscription
        self.timer = self.create_timer(1, self.publish_waypoints)
        self.waypoints = [
            (1.0, 1.0, 0.0),  # (x, y, yaw)
            (2.0, 2.0, 1.57),
            (3.0, 3.0, 0.0)
        ]
        self.current_waypoint_index = 0

    def publish_waypoints(self):
        if self.current_waypoint_index < len(self.waypoints):
            pose = PoseStamped()
            pose.header.frame_id = 'map'
            pose.pose.position.x, pose.pose.position.y, pose.pose.position.z = self.waypoints[self.current_waypoint_index]
            # Assuming orientation is in quaternion, convert yaw to quaternion if needed
            # pose.pose.orientation = ...
            self.publisher.publish(pose)
            self.previous_position = self.current_position
            if self.current_position == self.waypoints[self.current_waypoint_index]:
                    self.current_waypoint_index += 1
        else:
            self.get_logger().info("Reached all waypoints")

    def odom_callback(self, msg):
        # Extract position information from the odometry message
        self.current_position = (msg.pose.pose.position.x, msg.pose.pose.position.y, math.atan2(2*(msg.pose.pose.orientation.w * msg.pose.pose.orientation.z + msg.pose.pose.orientation.x * msg.pose.pose.orientation.y), 1 - 2 * (msg.pose.pose.orientation.y ** 2 + msg.pose.pose.orientation.z ** 2)))


def main(args=None):
    rclpy.init(args=args)
    waypoint_setter = WaypointSetter()
    rclpy.spin(waypoint_setter)
    waypoint_setter.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
