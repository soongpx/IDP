from launch import LaunchDescription
import launch
from launch_ros.actions import Node
from launch.actions import TimerAction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python import get_package_share_directory


def generate_launch_description():
    ld = LaunchDescription()

    realsense_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('realsense2_camera'), 
                         'launch/rs_launch.py')
        ),
        launch_arguments= {
            'config_file': '/home/px/arduino_ws/src/arduino_control/arduino_control/Realsense/config.yaml'
        }.items()
    )

    ld.add_action(realsense_launch)

    imu_node = Node(
        package='arduino_control',
        executable='imu',
        name='imu'
    )
    ld.add_action(TimerAction(period=3.0, actions=[imu_node]))

    realsense_imu_node = Node(
        package='arduino_control',
        executable='realsense_imu',
        name='realsense_imu'
    )
    ld.add_action(TimerAction(period=3.0, actions=[realsense_imu_node]))

    harvest_fruit_node = Node(
        package='arduino_control',
        executable='harvest_fruit',
        name='harvest_fruit'
    )
    ld.add_action(TimerAction(period=7.0, actions=[harvest_fruit_node]))

    return ld


if __name__ == "__main__":
    generate_launch_description()
