# from launch import LaunchDescription
# from launch_ros.actions import Node
# from launch.actions import TimerAction, IncludeLaunchDescription
# from launch.launch_description_sources import PythonLaunchDescriptionSource
# import os
# from ament_index_python import get_package_share_directory


# def generate_launch_description():
#     gazebo_path = get_package_share_directory('turtlebot3_gazebo')
#     navigation_path = get_package_share_directory('turtlebot3_navigation2')
#     arduino_path = get_package_share_directory('arduino_control')
#     print(navigation_path)

#     navigation2_launch = IncludeLaunchDescription(
#         PythonLaunchDescriptionSource(navigation_path+'/launch/navigation2.launch.py'),
#         launch_arguments= {
#             'use_sim_time': 'True',
#             'map' : '/home/px/maps/33_map.yaml'
#         }.items()
#     )
    
#     ld = LaunchDescription([
#     	navigation2_launch,
#     ])
     

#     return ld


# if __name__ == "__main__":
#     generate_launch_description()

# Copyright 2019 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Author: Darby Lim

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

TURTLEBOT3_MODEL = os.environ['TURTLEBOT3_MODEL']


def generate_launch_description():
    nav2_launch_file_dir = os.path.join(get_package_share_directory('simulation'), 'launch')
    launch_file_dir = os.path.join(get_package_share_directory('turtlebot3_gazebo'), 'launch')
    pkg_gazebo_ros = get_package_share_directory('gazebo_ros')

    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    x_pose = LaunchConfiguration('x_pose', default='-2.0')
    y_pose = LaunchConfiguration('y_pose', default='-0.5')

    world = os.path.join(
        get_package_share_directory('turtlebot3_gazebo'),
        'worlds',
        'turtlebot3_world.world'
    )

    gzserver_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzserver.launch.py')
        ),
        launch_arguments={'world': world}.items()
    )

    gzclient_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_gazebo_ros, 'launch', 'gzclient.launch.py')
        )
    )

    robot_state_publisher_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_file_dir, 'robot_state_publisher.launch.py')
        ),
        launch_arguments={'use_sim_time': use_sim_time}.items()
    )

    spawn_turtlebot_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_file_dir, 'spawn_turtlebot3.launch.py')
        ),
        launch_arguments={
            'x_pose': x_pose,
            'y_pose': y_pose
        }.items()
    )

    #rviz_config_dir = '/home/px/maps/simulation.rviz'
    rviz_config_dir = os.path.join(
       get_package_share_directory('nav2_bringup'),
      'rviz',
     'nav2_default_view.rviz')

    return LaunchDescription([
        gzserver_cmd,
        gzclient_cmd,
        robot_state_publisher_cmd,
        spawn_turtlebot_cmd,


        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([nav2_launch_file_dir, '/bringup_launch.py']),
            launch_arguments={
                'map': '/home/px/maps/33_map.yaml',
                'use_sim_time': 'True'}.items(),
        ),

        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config_dir],
            parameters=[{'use_sim_time': True}],
            output='screen'),
    ])