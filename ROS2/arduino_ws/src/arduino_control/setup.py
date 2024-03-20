import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'arduino_control'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='px',
    maintainer_email='px@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        	'locomotion_control = arduino_control.arduino_led_node:main',
        	'minimal_publisher = arduino_control.publisher:main',
            'realsense = arduino_control.realsense:main',
            'lidar = arduino_control.lidar:main',
            'joystick = arduino_control.joystick:main',
            'obstacle_avoidance = arduino_control.obstacle_avoidance:main',
            'joystick_control = arduino_control.joystick_control:main',
        ],
    },
)
