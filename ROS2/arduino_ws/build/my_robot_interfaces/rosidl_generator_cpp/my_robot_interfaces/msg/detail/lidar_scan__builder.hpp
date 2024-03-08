// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/LidarScan.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/lidar_scan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_LidarScan_range
{
public:
  explicit Init_LidarScan_range(::my_robot_interfaces::msg::LidarScan & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::LidarScan range(::my_robot_interfaces::msg::LidarScan::_range_type arg)
  {
    msg_.range = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::LidarScan msg_;
};

class Init_LidarScan_angle
{
public:
  explicit Init_LidarScan_angle(::my_robot_interfaces::msg::LidarScan & msg)
  : msg_(msg)
  {}
  Init_LidarScan_range angle(::my_robot_interfaces::msg::LidarScan::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_LidarScan_range(msg_);
  }

private:
  ::my_robot_interfaces::msg::LidarScan msg_;
};

class Init_LidarScan_detected
{
public:
  Init_LidarScan_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LidarScan_angle detected(::my_robot_interfaces::msg::LidarScan::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_LidarScan_angle(msg_);
  }

private:
  ::my_robot_interfaces::msg::LidarScan msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::LidarScan>()
{
  return my_robot_interfaces::msg::builder::Init_LidarScan_detected();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__BUILDER_HPP_
