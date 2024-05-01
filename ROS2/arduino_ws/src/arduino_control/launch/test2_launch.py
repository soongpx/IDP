from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python import get_package_share_directory


def generate_launch_description():
    ld = LaunchDescription()

    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('turtlebot3_gazebo'), 
                         'launch/turtlebot3_world.launch.py')
        ),
    )

    ld.add_action(gazebo_launch)    

    navigation2_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('arduino_control'), 
                         'launch/joystick_control_launch.py')
        ),
        launch_arguments= {
            'use_sim_time': 'True',
            'map' : '/home/px/maps/33_map.yaml'
        }.items()
    )
    ld.add_action(TimerAction(period=8.0, actions=[navigation2_launch]))  

    return ld


if __name__ == "__main__":
    generate_launch_description()
