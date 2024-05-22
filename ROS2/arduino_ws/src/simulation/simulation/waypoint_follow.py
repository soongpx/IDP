# import rclpy
# from rclpy.node import Node
# from geometry_msgs.msg import PoseStamped
# from nav_msgs.msg import Odometry
# import math

# class WaypointSetter(Node):
#     def __init__(self):
#         super().__init__('waypoint_setter')
#         self.publisher = self.create_publisher(PoseStamped, '/goal_pose', 10)
#         self.odom_subscription = self.create_subscription(
#             Odometry,
#             '/odom',
#             self.odom_callback,
#             10)
#         self.odom_subscription
#         self.timer = self.create_timer(1, self.publish_waypoints)
#         self.waypoints = [
#             # (1.0, 1.0, 0.0),  # (x, y, yaw)
#             # (2.0, 2.0, 1.57),
#             (0.0, 0.0, -1.5)
#         ]
#         self.current_waypoint_index = 0
#         self.previous_position = [0,0,0]
#         self.ex_position = [0,0,0]
#         self.first_enter = True
#         self.counter = 0

#     def publish_waypoints(self):
#         if self.current_waypoint_index < len(self.waypoints):
#             pose = PoseStamped()
#             pose.header.frame_id = 'map'
#             pose.pose.position.x, pose.pose.position.y, pose.pose.orientation.z = self.waypoints[self.current_waypoint_index]
#             # Assuming orientation is in quaternion, convert yaw to quaternion if needed
#             # pose.pose.orientation = ...
#             self.publisher.publish(pose)
#             self.get_logger().info(str(self.counter))
#             self.get_logger().info(f"{pose.pose.position.x},{pose.pose.position.y},{pose.pose.orientation.z}")
#             self.get_logger().info(f"{self.current_position[0]},{self.current_position[1]},{self.current_position[2]}")
#             self.get_logger().info(f"{self.previous_position[0]},{self.previous_position[1]},{self.previous_position[2]}")

#             if (abs(self.current_position[0] - self.ex_position[0]) <= 0.01) and (abs(self.current_position[1] - self.ex_position[1]) <= 0.01) and (abs(self.current_position[2] - self.ex_position[2]) <= 0.01):
#                 self.previous_position = self.current_position
#                 self.get_logger().info("Not leaving position yet")
#             else:
#                 if (abs(self.current_position[0] - self.previous_position[0]) <= 0.01) and (abs(self.current_position[1] - self.previous_position[1]) <= 0.01) and (abs(self.current_position[2] - self.previous_position[2]) <= 0.01):
#                     self.counter += 1
#                     if self.counter == 8:
#                         self.current_waypoint_index += 1
#                         self.counter = 0
#                         self.ex_position = self.current_position
#                 else:
#                     self.counter = 0
#                     self.previous_position = self.current_position
#         else:
#             self.get_logger().info("Reached all waypoints")

#     def odom_callback(self, msg):
#         # Extract position information from the odometry message
#         self.current_position = [msg.pose.pose.position.x, msg.pose.pose.position.y, math.atan2(2*(msg.pose.pose.orientation.w * msg.pose.pose.orientation.z + msg.pose.pose.orientation.x * msg.pose.pose.orientation.y), 1 - 2 * (msg.pose.pose.orientation.y ** 2 + msg.pose.pose.orientation.z ** 2))]


# def main(args=None):
#     rclpy.init(args=args)
#     waypoint_setter = WaypointSetter()
#     rclpy.spin(waypoint_setter)
#     waypoint_setter.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()

import time
from enum import Enum

from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from lifecycle_msgs.srv import GetState
from nav2_msgs.action import NavigateThroughPoses, NavigateToPose, FollowWaypoints, ComputePathToPose, \
    ComputePathThroughPoses
from nav2_msgs.srv import LoadMap, ClearEntireCostmap, ManageLifecycleNodes, GetCostmap

import rclpy

from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSReliabilityPolicy
from rclpy.qos import QoSProfile


class NavigationResult(Enum):
    UKNOWN = 0
    SUCCEEDED = 1
    CANCELED = 2
    FAILED = 3


class BasicNavigator(Node):
    def __init__(self):
        super().__init__(node_name='basic_navigator')
        self.initial_pose = PoseStamped()
        self.initial_pose.header.frame_id = 'map'
        self.goal_handle = None
        self.result_future = None
        self.feedback = None
        self.status = None

        amcl_pose_qos = QoSProfile(
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL,
            reliability=QoSReliabilityPolicy.RELIABLE,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1)

        self.initial_pose_received = False
        self.nav_through_poses_client = ActionClient(self,
                                                     NavigateThroughPoses,
                                                     'navigate_through_poses')
        self.nav_to_pose_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.follow_waypoints_client = ActionClient(self, FollowWaypoints, 'follow_waypoints')
        self.compute_path_to_pose_client = ActionClient(self, ComputePathToPose, 'compute_path_to_pose')
        self.compute_path_through_poses_client = ActionClient(self, ComputePathThroughPoses,
                                                              'compute_path_through_poses')
        self.localization_pose_sub = self.create_subscription(PoseWithCovarianceStamped,
                                                              'amcl_pose',
                                                              self._amclPoseCallback,
                                                              amcl_pose_qos)
        self.initial_pose_pub = self.create_publisher(PoseWithCovarianceStamped,
                                                      'initialpose',
                                                      10)
        self.change_maps_srv = self.create_client(LoadMap, '/map_server/load_map')
        self.clear_costmap_global_srv = self.create_client(
            ClearEntireCostmap, '/global_costmap/clear_entirely_global_costmap')
        self.clear_costmap_local_srv = self.create_client(
            ClearEntireCostmap, '/local_costmap/clear_entirely_local_costmap')
        self.get_costmap_global_srv = self.create_client(GetCostmap, '/global_costmap/get_costmap')
        self.get_costmap_local_srv = self.create_client(GetCostmap, '/local_costmap/get_costmap')

    def setInitialPose(self, initial_pose):
        self.initial_pose_received = False
        self.initial_pose = initial_pose
        self._setInitialPose()

    def goThroughPoses(self, poses):
        # Sends a `NavThroughPoses` action request
        self.debug("Waiting for 'NavigateThroughPoses' action server")
        while not self.nav_through_poses_client.wait_for_server(timeout_sec=1.0):
            self.info("'NavigateThroughPoses' action server not available, waiting...")

        goal_msg = NavigateThroughPoses.Goal()
        goal_msg.poses = poses

        self.info('Navigating with ' + str(len(goal_msg.poses)) + ' goals.' + '...')
        send_goal_future = self.nav_through_poses_client.send_goal_async(goal_msg,
                                                                         self._feedbackCallback)
        rclpy.spin_until_future_complete(self, send_goal_future)
        self.goal_handle = send_goal_future.result()

        if not self.goal_handle.accepted:
            self.error('Goal with ' + str(len(poses)) + ' poses was rejected!')
            return False

        self.result_future = self.goal_handle.get_result_async()
        return True

    def goToPose(self, pose):
        # Sends a `NavToPose` action request
        self.debug("Waiting for 'NavigateToPose' action server")
        while not self.nav_to_pose_client.wait_for_server(timeout_sec=1.0):
            self.info("'NavigateToPose' action server not available, waiting...")

        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = pose

        self.info('Navigating to goal: ' + str(pose.pose.position.x) + ' ' +
                  str(pose.pose.position.y) + '...')
        send_goal_future = self.nav_to_pose_client.send_goal_async(goal_msg,
                                                                   self._feedbackCallback)
        rclpy.spin_until_future_complete(self, send_goal_future)
        self.goal_handle = send_goal_future.result()

        if not self.goal_handle.accepted:
            self.error('Goal to ' + str(pose.pose.position.x) + ' ' +
                       str(pose.pose.position.y) + ' was rejected!')
            return False

        self.result_future = self.goal_handle.get_result_async()
        return True

    def followWaypoints(self, poses):
        # Sends a `FollowWaypoints` action request
        self.debug("Waiting for 'FollowWaypoints' action server")
        while not self.follow_waypoints_client.wait_for_server(timeout_sec=1.0):
            self.info("'FollowWaypoints' action server not available, waiting...")

        goal_msg = FollowWaypoints.Goal()
        goal_msg.poses = poses

        self.info('Following ' + str(len(goal_msg.poses)) + ' goals.' + '...')
        send_goal_future = self.follow_waypoints_client.send_goal_async(goal_msg,
                                                                        self._feedbackCallback)
        rclpy.spin_until_future_complete(self, send_goal_future)
        self.goal_handle = send_goal_future.result()

        if not self.goal_handle.accepted:
            self.error('Following ' + str(len(poses)) + ' waypoints request was rejected!')
            return False

        self.result_future = self.goal_handle.get_result_async()
        return True

    def cancelNav(self):
        self.info('Canceling current goal.')
        if self.result_future:
            future = self.goal_handle.cancel_goal_async()
            rclpy.spin_until_future_complete(self, future)
        return

    def isNavComplete(self):
        if not self.result_future:
            # task was cancelled or completed
            return True
        rclpy.spin_until_future_complete(self, self.result_future, timeout_sec=0.10)
        if self.result_future.result():
            self.status = self.result_future.result().status
            if self.status != GoalStatus.STATUS_SUCCEEDED:
                self.debug('Goal with failed with status code: {0}'.format(self.status))
                return True
        else:
            # Timed out, still processing, not complete yet
            return False

        self.debug('Goal succeeded!')
        return True

    def getFeedback(self):
        return self.feedback

    def getResult(self):
        if self.status == GoalStatus.STATUS_SUCCEEDED:
            return NavigationResult.SUCCEEDED
        elif self.status == GoalStatus.STATUS_ABORTED:
            return NavigationResult.FAILED
        elif self.status == GoalStatus.STATUS_CANCELED:
            return NavigationResult.CANCELED
        else:
            return NavigationResult.UNKNOWN

    def waitUntilNav2Active(self):
        self._waitForNodeToActivate('amcl')
        self._waitForInitialPose()
        self._waitForNodeToActivate('bt_navigator')
        self.info('Nav2 is ready for use!')
        return

    def getPath(self, start, goal):
        # Sends a `NavToPose` action request
        self.debug("Waiting for 'ComputePathToPose' action server")
        while not self.compute_path_to_pose_client.wait_for_server(timeout_sec=1.0):
            self.info("'ComputePathToPose' action server not available, waiting...")

        goal_msg = ComputePathToPose.Goal()
        goal_msg.goal = goal
        goal_msg.start = start

        self.info('Getting path...')
        send_goal_future = self.compute_path_to_pose_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)
        self.goal_handle = send_goal_future.result()

        if not self.goal_handle.accepted:
            self.error('Get path was rejected!')
            return None

        self.result_future = self.goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, self.result_future)
        self.status = self.result_future.result().status
        if self.status != GoalStatus.STATUS_SUCCEEDED:
            self.warn('Getting path failed with status code: {0}'.format(self.status))
            return None

        return self.result_future.result().result.path

    def getPathThroughPoses(self, start, goals):
        # Sends a `NavToPose` action request
        self.debug("Waiting for 'ComputePathThroughPoses' action server")
        while not self.compute_path_through_poses_client.wait_for_server(timeout_sec=1.0):
            self.info("'ComputePathThroughPoses' action server not available, waiting...")

        goal_msg = ComputePathThroughPoses.Goal()
        goal_msg.goals = goals
        goal_msg.start = start

        self.info('Getting path...')
        send_goal_future = self.compute_path_through_poses_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)
        self.goal_handle = send_goal_future.result()

        if not self.goal_handle.accepted:
            self.error('Get path was rejected!')
            return None

        self.result_future = self.goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, self.result_future)
        self.status = self.result_future.result().status
        if self.status != GoalStatus.STATUS_SUCCEEDED:
            self.warn('Getting path failed with status code: {0}'.format(self.status))
            return None

        return self.result_future.result().result.path

    def changeMap(self, map_filepath):
        while not self.change_maps_srv.wait_for_service(timeout_sec=1.0):
            self.info('change map service not available, waiting...')
        req = LoadMap.Request()
        req.map_url = map_filepath
        future = self.change_maps_srv.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        status = future.result().result
        if status != LoadMap.Response().RESULT_SUCCESS:
            self.error('Change map request failed!')
        else:
            self.info('Change map request was successful!')
        return

    def clearAllCostmaps(self):
        self.clearLocalCostmap()
        self.clearGlobalCostmap()
        return

    def clearLocalCostmap(self):
        while not self.clear_costmap_local_srv.wait_for_service(timeout_sec=1.0):
            self.info('Clear local costmaps service not available, waiting...')
        req = ClearEntireCostmap.Request()
        future = self.clear_costmap_local_srv.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        return

    def clearGlobalCostmap(self):
        while not self.clear_costmap_global_srv.wait_for_service(timeout_sec=1.0):
            self.info('Clear global costmaps service not available, waiting...')
        req = ClearEntireCostmap.Request()
        future = self.clear_costmap_global_srv.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        return

    def getGlobalCostmap(self):
        while not self.get_costmap_global_srv.wait_for_service(timeout_sec=1.0):
            self.info('Get global costmaps service not available, waiting...')
        req = GetCostmap.Request()
        future = self.get_costmap_global_srv.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        return future.result().map

    def getLocalCostmap(self):
        while not self.get_costmap_local_srv.wait_for_service(timeout_sec=1.0):
            self.info('Get local costmaps service not available, waiting...')
        req = GetCostmap.Request()
        future = self.get_costmap_local_srv.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        return future.result().map

    def lifecycleStartup(self):
        self.info('Starting up lifecycle nodes based on lifecycle_manager.')
        srvs = self.get_service_names_and_types()
        for srv in srvs:
            if srv[1][0] == 'nav2_msgs/srv/ManageLifecycleNodes':
                srv_name = srv[0]
                self.info('Starting up ' + srv_name)
                mgr_client = self.create_client(ManageLifecycleNodes, srv_name)
                while not mgr_client.wait_for_service(timeout_sec=1.0):
                    self.info(srv_name + ' service not available, waiting...')
                req = ManageLifecycleNodes.Request()
                req.command = ManageLifecycleNodes.Request().STARTUP
                future = mgr_client.call_async(req)

                # starting up requires a full map->odom->base_link TF tree
                # so if we're not successful, try forwarding the initial pose
                while True:
                    rclpy.spin_until_future_complete(self, future, timeout_sec=0.10)
                    if not future:
                        self._waitForInitialPose()
                    else:
                        break
        self.info('Nav2 is ready for use!')
        return

    def lifecycleShutdown(self):
        self.info('Shutting down lifecycle nodes based on lifecycle_manager.')
        srvs = self.get_service_names_and_types()
        for srv in srvs:
            if srv[1][0] == 'nav2_msgs/srv/ManageLifecycleNodes':
                srv_name = srv[0]
                self.info('Shutting down ' + srv_name)
                mgr_client = self.create_client(ManageLifecycleNodes, srv_name)
                while not mgr_client.wait_for_service(timeout_sec=1.0):
                    self.info(srv_name + ' service not available, waiting...')
                req = ManageLifecycleNodes.Request()
                req.command = ManageLifecycleNodes.Request().SHUTDOWN
                future = mgr_client.call_async(req)
                rclpy.spin_until_future_complete(self, future)
                future.result()
        return

    def _waitForNodeToActivate(self, node_name):
        # Waits for the node within the tester namespace to become active
        self.debug('Waiting for ' + node_name + ' to become active..')
        node_service = node_name + '/get_state'
        state_client = self.create_client(GetState, node_service)
        while not state_client.wait_for_service(timeout_sec=1.0):
            self.info(node_service + ' service not available, waiting...')

        req = GetState.Request()
        state = 'unknown'
        while (state != 'active'):
            self.debug('Getting ' + node_name + ' state...')
            future = state_client.call_async(req)
            rclpy.spin_until_future_complete(self, future)
            if future.result() is not None:
                state = future.result().current_state.label
                self.debug('Result of get_state: %s' % state)
            time.sleep(2)
        return

    def _waitForInitialPose(self):
        while not self.initial_pose_received:
            self.info('Setting initial pose')
            self._setInitialPose()
            self.info('Waiting for amcl_pose to be received')
            rclpy.spin_once(self, timeout_sec=1.0)
        return

    def _amclPoseCallback(self, msg):
        self.debug('Received amcl pose')
        self.initial_pose_received = True
        return

    def _feedbackCallback(self, msg):
        self.debug('Received action feedback message')
        self.feedback = msg.feedback
        return

    def _setInitialPose(self):
        msg = PoseWithCovarianceStamped()
        msg.pose.pose = self.initial_pose.pose
        msg.header.frame_id = self.initial_pose.header.frame_id
        msg.header.stamp = self.initial_pose.header.stamp
        self.info('Publishing Initial Pose')
        self.initial_pose_pub.publish(msg)
        return

    def info(self, msg):
        self.get_logger().info(msg)
        return

    def warn(self, msg):
        self.get_logger().warn(msg)
        return

    def error(self, msg):
        self.get_logger().error(msg)
        return

    def debug(self, msg):
        self.get_logger().debug(msg)
        return


import time  # Time library

from geometry_msgs.msg import PoseStamped  # Pose with ref frame and timestamp
from rclpy.duration import Duration  # Handles time for ROS 2
import rclpy  # Python client library for ROS 2

'''
Follow waypoints using the ROS 2 Navigation Stack (Nav2)
'''


class Tree:
    def __init__(self, centre):
        self.centre = centre
        self.pose_data = []
        self.pose_data[0] = (self.centre[0]-0.25, self.centre[1]-0.35, -0.3827, 0.9239)
        self.pose_data[1] = (self.centre[0]+0.25, self.centre[1]-0.35, -0.3827, -0.9239)
        self.pose_data[2] = (self.centre[0]+0.25, self.centre[1]+0.35, -0.9239, -0.3827)
        self.pose_data[3] = (self.centre[0]-0.25, self.centre[1]+0.35, -0.9239, 0.3827)

    def fourpoints(self):
        return self.pose_data

    def onepoint(self, order):
        if order <= 3:
            return self.pose_data[order]
        else:
            self.get_logger().warn("Order exceed")
            return None

def main():
    # Start the ROS 2 Python Client Library
    rclpy.init()

    # Launch the ROS 2 Navigation Stack
    navigator = BasicNavigator()

    # Set the robot's initial pose if necessary
    # initial_pose = PoseStamped()
    # initial_pose.header.frame_id = 'map'
    # initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    # initial_pose.pose.position.x = 0.0
    # initial_pose.pose.position.y = 0.0
    # initial_pose.pose.position.z = 0.0
    # initial_pose.pose.orientation.x = 0.0
    # initial_pose.pose.orientation.y = 0.0
    # initial_pose.pose.orientation.z = 0.0
    # initial_pose.pose.orientation.w = 1.0
    # navigator.setInitialPose(initial_pose)

    # Activate navigation, if not autostarted. This should be called after setInitialPose()
    # or this will initialize at the origin of the map and update the costmap with bogus readings.
    # If autostart, you should `waitUntilNav2Active()` instead.
    # navigator.lifecycleStartup()

    # Wait for navigation to fully activate. Use this line if autostart is set to true.
    navigator.waitUntilNav2Active()

    # If desired, you can change or load the map as well
    # navigator.changeMap('/path/to/map.yaml')

    # You may use the navigator to clear or obtain costmaps
    # navigator.clearAllCostmaps()  # also have clearLocalCostmap() and clearGlobalCostmap()
    # global_costmap = navigator.getGlobalCostmap()
    # local_costmap = navigator.getLocalCostmap()

    # Set the robot's goal poses
    goal_poses = []

    # Tree1 = Tree([0.85, 1.05])
    # Tree2 = Tree([0.85, 0.25])
    # Tree3 = Tree([0.85, -0.55])
    # Tree4 = Tree([1.65, -0.55])
    # Tree5 = Tree([1.65, 0.25])
    # Tree6 = Tree([1.65, 1.05])
    # Tree7 = Tree([2.45, 1.05])
    # Tree8 = Tree([2.45, 0.25])
    # Tree9 = Tree([2.45, -0.55])
    # Home = (0, 0, 0.0, 1.0)

    pose_data = [
        # 1, 1
        [
            (0.6, 1.2, -0.3827, 0.9239),
            (1.1, 1.2, -0.3827, -0.9239),
            (1.1, 1.9, -0.9239, -0.3827),
            (0.6, 1.9, -0.9239, 0.3827)
        ],
        # 1, 2
        [
            (0.6, -0.1, -0.3827, 0.9239),
            (1.1, -0.1, -0.3827, -0.9239),
            (1.1, 0.6, -0.9239, -0.3827),
            (0.6, 0.6, -0.9239, 0.3827)
        ],
        # 1, 3
        [
            (0.6, -0.9, -0.3827, 0.9239),
            (1.1, -0.9, -0.3827, -0.9239),
            (1.1, -0.2, -0.9239, -0.3827),
            (0.6, -0.2, -0.9239, 0.3827)
        ],
        # 2, 3
        [
            (1.4, -0.9, -0.3827, 0.9239),
            (1.9, -0.9, -0.3827, -0.9239),
            (1.9, -0.2, -0.9239, -0.3827),
            (1.4, -0.2, -0.9239, 0.3827)
        ],
        # 2, 2
        [
            (1.4, -0.1, -0.3827, 0.9239),
            (1.9, -0.1, -0.3827, -0.9239),
            (1.9, 0.6, -0.9239, -0.3827),
            (1.4, 0.6, -0.9239, 0.3827)
        ],
        # 2, 1
        [
            (1.4, 0.7, -0.3827, 0.9239),
            (1.9, 0.7, -0.3827, -0.9239),
            (1.9, 1.4, -0.9239, -0.3827),
            (1.4, 1.4, -0.9239, 0.3827)
        ],
        # 3, 1
        [
            (2.2, 0.7, -0.3827, 0.9239),
            (2.7, 0.7, -0.3827, -0.9239),
            (2.7, 1.4, -0.9239, -0.3827),
            (2.2, 1.4, -0.9239, 0.3827)
        ],
        # 3, 2
        [
            (2.2, -0.1, -0.3827, 0.9239),
            (2.7, -0.1, -0.3827, -0.9239),
            (2.7, 0.6, -0.9239, -0.3827),
            (2.2, 0.6, -0.9239, 0.3827)
        ],
        # 3, 3
        [
            (2.2, -0.9, -0.3827, 0.9239),
            (2.7, -0.9, -0.3827, -0.9239),
            (2.7, -0.2, -0.9239, -0.3827),
            (2.2, -0.2, -0.9239, 0.3827)
        ],
    ]

    for tree in pose_data:
        for pose_info in tree:
            goal_pose = PoseStamped()
            goal_pose.header.frame_id = 'map'
            goal_pose.header.stamp = navigator.get_clock().now().to_msg()
            goal_pose.pose.position.x, goal_pose.pose.position.y, goal_pose.pose.orientation.z, goal_pose.pose.orientation.w = pose_info
            goal_pose.pose.position.z = 0.0
            goal_pose.pose.orientation.x = 0.0
            goal_pose.pose.orientation.y = 0.0
            goal_poses.append(goal_pose)

    #   goal_pose = PoseStamped()
    #   goal_pose.header.frame_id = 'map'
    #   goal_pose.header.stamp = navigator.get_clock().now().to_msg()
    #   goal_pose.pose.position.x = 0.0
    #   goal_pose.pose.position.y = 0.0
    #   goal_pose.pose.position.z = 0.0
    #   goal_pose.pose.orientation.x = 0.0
    #   goal_pose.pose.orientation.y = 0.0
    #   goal_pose.pose.orientation.z = 0.0
    #   goal_pose.pose.orientation.w = 1.0
    #   goal_poses.append(goal_pose)

    # sanity check a valid path exists
    # path = navigator.getPathThroughPoses(initial_pose, goal_poses)

    nav_start = navigator.get_clock().now()
    navigator.followWaypoints(goal_poses)

    i = 0
    while not navigator.isNavComplete():
        ################################################
        #
        # Implement some code here for your application!
        #
        ################################################

        # Do something with the feedback
        i = i + 1
        feedback = navigator.getFeedback()
        if feedback and i % 5 == 0:
            print('Executing current waypoint: ' +
                  str(feedback.current_waypoint + 1) + '/' + str(len(goal_poses)))
            now = navigator.get_clock().now()

            # Some navigation timeout to demo cancellation
            if now - nav_start > Duration(seconds=100000000.0):
                navigator.cancelNav()

            # Some follow waypoints request change to demo preemption
            if now - nav_start > Duration(seconds=500000.0):
                goal_pose_alt = PoseStamped()
                goal_pose_alt.header.frame_id = 'map'
                goal_pose_alt.header.stamp = now.to_msg()
                goal_pose_alt.pose.position.x = 0.0
                goal_pose_alt.pose.position.y = 0.0
                goal_pose_alt.pose.position.z = 0.0
                goal_pose_alt.pose.orientation.x = 0.0
                goal_pose_alt.pose.orientation.y = 0.0
                goal_pose_alt.pose.orientation.z = 0.0
                goal_pose_alt.pose.orientation.w = 1.0
                goal_poses = [goal_pose_alt]
                nav_start = now
                navigator.followWaypoints(goal_poses)

    # Do something depending on the return code
    result = navigator.getResult()
    if result == NavigationResult.SUCCEEDED:
        print('Goal succeeded!')
    elif result == NavigationResult.CANCELED:
        print('Goal was canceled!')
    elif result == NavigationResult.FAILED:
        print('Goal failed!')
    else:
        print('Goal has an invalid return status!')

    navigator.lifecycleShutdown()

    exit(0)


if __name__ == '__main__':
    main()
