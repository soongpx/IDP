import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from my_robot_interfaces.msg import LaserScan


class AutonomousNode(Node):

    def __init__(self):

        super().__init__('autonomous_control')
        self.lidar_subscription = self.create_subscription(LaserScan, 'laser_scan', self.lidar_callback, 10)
        self.lidar_subscription
        self.publisher_ = self.create_publisher(String, 'motor_command', 10)
        self.timer = self.create_timer(10, self.timer_callback)

        # Initialise variables
        self.range = []
        self.angle = []
        self.detected = False
        self.find = False

        self.nearest_distance = float('inf')
        self.nearest_angle = None

    def lidar_callback(self, msg):
        self.range = msg.ranges
        self.angle = msg.angles
        self.detected = True

    def timer_callback(self):
        # Step 1: Find nearest obstacle
        self.find_nearest_obstacle()
        self.get_logger().info(f"Nearest obstacle: Angle = {self.nearest_angle}, Distance = {self.nearest_distance}cm")

        # Step 2: Rotate to face the nearest obstacle at front
        self.rotate_to_face(self.nearest_angle)

        # Step 3: Move forward until 50cm to obstacle
        self.move_forward(self.nearest_distance)

        # Step 4: Rotate until centre of obstacle is at left 90 degree
        self.rotate_until_left_90_degrees()

        # Step 5: Start speed differential and maintain 50cm distance with obstacle
        self.start_speed_differential()

    # Function to find the nearest obstacle
    def find_nearest_obstacle(self):
        self.nearest_distance = float('inf')
        self.nearest_angle = None
        for angle, distance in zip(self.angle, self.range):
            if distance < self.nearest_distance:
                self.nearest_distance = distance
                self.nearest_angle = angle

    # Function to rotate to face the nearest obstacle at front
    def rotate_to_face(self, nearest_angle):
        # Implement rotation to face the nearest obstacle
        print(f"Rotating to face nearest obstacle at angle {nearest_angle}")

    # Function to move forward until 50cm to obstacle
    def move_forward(self, distance_to_obstacle):
        # Implement forward movement until the specified distance is reached
        print(f"Moving forward until 50cm to obstacle. Current distance: {distance_to_obstacle}")

    # Function to rotate until centre of obstacle is at left 90 degree
    def rotate_until_left_90_degrees(self):
        # Implement rotation until the centre of the obstacle is at left 90 degrees
        print("Rotating until centre of obstacle is at left 90 degrees")

    # Function to start speed differential and maintain 50cm distance with obstacle
    def start_speed_differential(self):
        # Implement speed differential to maintain distance with the obstacle
        print("Starting speed differential and maintaining 50cm distance with obstacle")


def main(args=None):
    rclpy.init(args=args)
    autonomous_node = AutonomousNode()  # Corrected variable name
    try:
        rclpy.spin(autonomous_node)  # Corrected variable name
    except KeyboardInterrupt:
        pass

    autonomous_node.destroy_node()  # Corrected variable name
    rclpy.shutdown()


if __name__ == '__main__':
    main()
