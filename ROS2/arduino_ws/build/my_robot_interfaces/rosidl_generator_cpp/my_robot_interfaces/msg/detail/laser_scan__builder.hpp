// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/LaserScan.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LASER_SCAN__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LASER_SCAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/laser_scan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_LaserScan_angles
{
public:
  explicit Init_LaserScan_angles(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::LaserScan angles(::my_robot_interfaces::msg::LaserScan::_angles_type arg)
  {
    msg_.angles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_intensities
{
public:
  explicit Init_LaserScan_intensities(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_angles intensities(::my_robot_interfaces::msg::LaserScan::_intensities_type arg)
  {
    msg_.intensities = std::move(arg);
    return Init_LaserScan_angles(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_ranges
{
public:
  explicit Init_LaserScan_ranges(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_intensities ranges(::my_robot_interfaces::msg::LaserScan::_ranges_type arg)
  {
    msg_.ranges = std::move(arg);
    return Init_LaserScan_intensities(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_range_max
{
public:
  explicit Init_LaserScan_range_max(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_ranges range_max(::my_robot_interfaces::msg::LaserScan::_range_max_type arg)
  {
    msg_.range_max = std::move(arg);
    return Init_LaserScan_ranges(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_range_min
{
public:
  explicit Init_LaserScan_range_min(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_range_max range_min(::my_robot_interfaces::msg::LaserScan::_range_min_type arg)
  {
    msg_.range_min = std::move(arg);
    return Init_LaserScan_range_max(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_scan_time
{
public:
  explicit Init_LaserScan_scan_time(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_range_min scan_time(::my_robot_interfaces::msg::LaserScan::_scan_time_type arg)
  {
    msg_.scan_time = std::move(arg);
    return Init_LaserScan_range_min(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_time_increment
{
public:
  explicit Init_LaserScan_time_increment(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_scan_time time_increment(::my_robot_interfaces::msg::LaserScan::_time_increment_type arg)
  {
    msg_.time_increment = std::move(arg);
    return Init_LaserScan_scan_time(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_angle_increment
{
public:
  explicit Init_LaserScan_angle_increment(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_time_increment angle_increment(::my_robot_interfaces::msg::LaserScan::_angle_increment_type arg)
  {
    msg_.angle_increment = std::move(arg);
    return Init_LaserScan_time_increment(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_angle_max
{
public:
  explicit Init_LaserScan_angle_max(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_angle_increment angle_max(::my_robot_interfaces::msg::LaserScan::_angle_max_type arg)
  {
    msg_.angle_max = std::move(arg);
    return Init_LaserScan_angle_increment(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_angle_min
{
public:
  explicit Init_LaserScan_angle_min(::my_robot_interfaces::msg::LaserScan & msg)
  : msg_(msg)
  {}
  Init_LaserScan_angle_max angle_min(::my_robot_interfaces::msg::LaserScan::_angle_min_type arg)
  {
    msg_.angle_min = std::move(arg);
    return Init_LaserScan_angle_max(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

class Init_LaserScan_header
{
public:
  Init_LaserScan_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LaserScan_angle_min header(::my_robot_interfaces::msg::LaserScan::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LaserScan_angle_min(msg_);
  }

private:
  ::my_robot_interfaces::msg::LaserScan msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::LaserScan>()
{
  return my_robot_interfaces::msg::builder::Init_LaserScan_header();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LASER_SCAN__BUILDER_HPP_
