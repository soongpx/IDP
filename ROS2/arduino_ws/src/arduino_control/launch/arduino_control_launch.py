from launch import LaunchDescription
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

    lidar_node = Node(
        package='arduino_control',
        executable='lidar',
        name='lidar'
    )
    ld.add_action(lidar_node)

    joystick_node = Node(
        package='arduino_control',
        executable='joystick',
        name='joystick'
    )
    ld.add_action(joystick_node)

    imu_node = Node(
        package='arduino_control',
        executable='imu',
        name='imu'
    )
    ld.add_action(imu_node)

    realsense_imu_node = Node(
        package='arduino_control',
        executable='realsense_imu',
        name='realsense_imu'
    )
    ld.add_action(TimerAction(period=3.0, actions=[realsense_imu_node]))

    find_obstacle_node = Node(
        package='arduino_control',
        executable='find_obstacle',
        name='find_obstacle'
    )
    ld.add_action(TimerAction(period=5.0, actions=[find_obstacle_node]))

    detection_node = Node(
        package='arduino_control',
        executable='detection',
        name='detection'
    )
    ld.add_action(TimerAction(period=7.0, actions=[detection_node]))

    harvest_fruit_node = Node(
        package='arduino_control',
        executable='harvest_fruit',
        name='harvest_fruit'
    )
    ld.add_action(TimerAction(period=7.0, actions=[harvest_fruit_node]))

    autonomous_main_node = Node(
        package='arduino_control',
        executable='autonomous_control',
        name='autonomous_control'
    )
    ld.add_action(TimerAction(period=10.0, actions=[autonomous_main_node]))  # Add a 5-second delay before launching node2

    locomotion_node = Node(
        package='arduino_control',
        executable='locomotion_control',
        name='locomotion_control'
    )
    ld.add_action(TimerAction(period=12.0, actions=[locomotion_node]))  # Add a 5-second delay before launching node4

    return ld


if __name__ == "__main__":
    generate_launch_description()
