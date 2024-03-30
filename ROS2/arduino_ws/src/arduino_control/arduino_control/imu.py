import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import Imu
import time
import serial.tools.list_ports
import lib.device_model as deviceModel
from lib.data_processor.roles.jy901s_dataProcessor import JY901SDataProcessor
from lib.protocol_resolver.roles.wit_protocol_resolver import WitProtocolResolver



class ImuNode(Node):
    def __init__(self):
        super().__init__('imu_node')
        self.publisher = self.create_publisher(Imu, 'imu_data', 10)
        timer_period = 0.01 
        self.timer = self.create_timer(timer_period, self.onUpdate)
        self.device = None

        # Message Variable
        self.temperature = 0.0
        self.pitch = 0.0
        self.roll = 0.0
        self.yaw = 0.0

    def connect_imu(self):
        while rclpy.ok():
            imu_ports = []
            ports = serial.tools.list_ports.comports()
            for port in ports:
                if 'USB Serial' in port.description:
                    imu_ports.append(port.device)

            if not ports:
                self.get_logger().error("No IMU ports found. Retrying...")
                time.sleep(1)  # Wait before retrying
                return False
            else:
                port = list(imu_ports)[-1]  # Select the last available port
                self.get_logger().info("IMU port: %s" % port)

                self.device = deviceModel.DeviceModel(
                    "我的JY901",
                    WitProtocolResolver(),
                    JY901SDataProcessor(),
                    "51_0"
                )
                self.device.serialConfig.portName = port  
                self.device.serialConfig.baud = 9600            
                self.device.openDevice() 
                return True

        return False

    
    def onUpdate(self):
        msg = Imu()
        # print("Temperature:" + str(self.device.getDeviceData("temperature")))
        # print("Pitch:" + str(self.device.getDeviceData("angleX")))
        # print("Roll:" + str(self.device.getDeviceData("angleY"))) 
        # print("Yaw:" + str(self.device.getDeviceData("angleZ")))

        if self.device.getDeviceData("temperature") and self.device.getDeviceData("angleX") and self.device.getDeviceData("angleY") and self.device.getDeviceData("angleZ"):
            self.temperature = self.device.getDeviceData("temperature")
            self.pitch = self.device.getDeviceData("angleX")
            self.roll = self.device.getDeviceData("angleY")
            self.yaw = self.device.getDeviceData("angleZ")

        msg.temperature = self.temperature
        msg.pitch = self.pitch
        msg.roll = self.roll
        msg.yaw = self.yaw
        self.publisher.publish(msg)

    def stop(self):
        if self.device is not None:
            self.device.closeDevice()
        self.destroy_node()
        rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    imu_node = ImuNode()

    if imu_node.connect_imu():
        rclpy.spin(imu_node)

    imu_node.stop()


if __name__ == "__main__":
    main()
