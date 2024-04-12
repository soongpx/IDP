from launch import LaunchDescription
import launch
from launch_ros.actions import Node
from launch.actions import TimerAction


def generate_launch_description():
    ld = LaunchDescription()

    node1 = Node(
        package='arduino_control',
        executable='imu',
        name='imu'
    )
    ld.add_action(node1)

    node2 = Node(
        package='arduino_control',
        executable='joystick',
        name='joystick'
    )
    ld.add_action(node2)

    node3 = Node(
        package='arduino_control',
        executable='realsense',
        name='realsense'
    )
    ld.add_action(node3)
    included_launch = launch.actions.IncludeLaunchDescription()

    node4 = Node(
        package='arduino_control',
        executable='fruit_harvest',
        name='fruit_harvest'
    )
    ld.add_action(TimerAction(period=13.0, actions=[node4]))  # Add a 5-second delay before launching node2

    node5 = Node(
        package='arduino_control',
        executable='locomotion_control',
        name='locomotion_control'
    )
    ld.add_action(TimerAction(period=15.0, actions=[node5]))  # Add a 5-second delay before launching node2

    return ld


if __name__ == "__main__":
    generate_launch_description()
