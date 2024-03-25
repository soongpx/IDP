from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction


def generate_launch_description():
    ld = LaunchDescription()

    node1 = Node(
        package='arduino_control',
        executable='lidar',
        name='lidar'
    )
    ld.add_action(node1)

    node3 = Node(
        package='arduino_control',
        executable='joystick',
        name='joystick'
    )
    ld.add_action(node3)

    node2 = Node(
        package='arduino_control',
        executable='obstacle_avoidance',
        name='obstacle_avoidance'
    )
    ld.add_action(TimerAction(period=5.0, actions=[node2]))  # Add a 5-second delay before launching node2

    node4 = Node(
        package='arduino_control',
        executable='joystick_control',
        name='joystick_control'
    )
    ld.add_action(TimerAction(period=5.0, actions=[node4]))  # Add a 5-second delay before launching node4

    return ld


if __name__ == "__main__":
    generate_launch_description()