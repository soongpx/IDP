import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from my_robot_interfaces.msg import RealsenseImu
from rclpy.qos import QoSProfile, QoSHistoryPolicy, QoSReliabilityPolicy, QoSDurabilityPolicy, QoSLivelinessPolicy
import numpy as np


class KalmanFilter:
    def __init__(self, A, H, Q, R):
        self.A = A  # State transition matrix
        self.H = H  # Measurement matrix
        self.Q = Q  # Process noise covariance
        self.R = R  # Measurement noise covariance
        self.P = np.eye(A.shape[1])  # Estimate error covariance

    def predict(self, x):
        # Predict the next state
        x = np.dot(self.A, x)
        self.P = np.dot(self.A, np.dot(self.P, self.A.T)) + self.Q
        return x


class DepthPublisherNode(Node):
    def __init__(self):
        super().__init__('realsense_imu')
        self.qos_profile = QoSProfile(
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=5,
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            durability=QoSDurabilityPolicy.VOLATILE,
            liveliness=QoSLivelinessPolicy.AUTOMATIC,
        )
        self.accel_subscriber = self.create_subscription(Imu, 'camera/accel/sample', self.accel_data, qos_profile=self.qos_profile)
        self.gyro_subscriber = self.create_subscription(Imu, 'camera/gyro/sample', self.gyro_data, qos_profile=self.qos_profile)
        self.publisher = self.create_publisher(RealsenseImu, 'realsense_imu', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.compute_angles)

        # Variables for Accel
        self.accel_x = 0
        self.accel_y = 0
        self.accel_z = 0

        # Variables for Gyro
        self.gyro_x = 0
        self.gyro_y = 0
        self.gyro_z = 0

        # Variables for orientation
        self.roll_angle = 0
        self.pitch_angle = 0
        self.yaw_angle = 0
        self.roll = 0
        self.pitch = 0
        self.yaw = 0

        # Variables for sensor fusion
        self.dt = 1 / 200  # Time interval (assuming gyro runs at 200 Hz)
        self.beta = 0.98  # Complementary filter coefficient
        self.kf_accel = KalmanFilter(A=np.eye(3), H=np.eye(3), Q=0.01*np.eye(3), R=0.1*np.eye(3))
        self.kf_gyro = KalmanFilter(A=np.eye(3), H=np.eye(3), Q=0.01*np.eye(3), R=0.1*np.eye(3))

    def accel_data(self, msg):
        accel_data = np.array([msg.linear_acceleration.x, msg.linear_acceleration.y, msg.linear_acceleration.z])
        filtered_accel = self.kf_accel.predict(accel_data)
        self.accel_x = filtered_accel[0]
        self.accel_y = filtered_accel[1]
        self.accel_z = filtered_accel[2]

    def gyro_data(self, msg):
        gyro_data = np.array([msg.angular_velocity.x, msg.angular_velocity.y, msg.angular_velocity.z])
        filtered_gyro = self.kf_gyro.predict(gyro_data)
        self.gyro_x = filtered_gyro[0]
        self.gyro_y = filtered_gyro[1]
        self.gyro_z = filtered_gyro[2]

    def compute_angles(self):
        self.get_imu_data()
        # self.get_logger().info(f"Pitch: {self.pitch_angle}")
        msg = RealsenseImu()
        msg.roll = self.roll_angle
        msg.pitch = self.pitch_angle
        msg.yaw = self.yaw_angle
        self.publisher.publish(msg)

    def get_imu_data(self):
        # Perform sensor fusion (complementary filter)
        self.roll += self.gyro_y * self.dt
        self.pitch += self.gyro_x * self.dt
        self.yaw += self.gyro_z * self.dt

        # Compensate for drift using accelerometer data
        roll_acc = np.arctan2(self.accel_x, np.sqrt(self.accel_y ** 2 + self.accel_z ** 2))
        pitch_acc = np.arctan2(self.accel_y, np.sqrt(self.accel_x ** 2 + self.accel_z ** 2))

        # Apply complementary filter for roll and pitch
        self.roll = self.beta * (self.roll + self.gyro_y * self.dt) + (1 - self.beta) * roll_acc
        self.pitch = self.beta * (self.pitch + self.gyro_x * self.dt) + (1 - self.beta) * pitch_acc

        # Convert angles to degrees
        self.roll_angle = np.degrees(self.roll)
        self.pitch_angle = np.degrees(self.pitch)
        self.yaw_angle = np.degrees(self.yaw)

    def __del__(self):
        self.destroy_node()



def main(args=None):
    rclpy.init(args=args)
    depth_publisher = DepthPublisherNode()
    rclpy.spin(depth_publisher)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
