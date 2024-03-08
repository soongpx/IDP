from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='arduino_control',
            executable='arduino_control_node',
            name='arduino_control_node'
        ),
        Node(
            package='arduino_control',
            executable='minimal_publisher',
            name='publisher'
        )
    ])

