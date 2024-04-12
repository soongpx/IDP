// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/RealsenseImu.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__REALSENSE_IMU__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__REALSENSE_IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/realsense_imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_RealsenseImu_yaw
{
public:
  explicit Init_RealsenseImu_yaw(::my_robot_interfaces::msg::RealsenseImu & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::RealsenseImu yaw(::my_robot_interfaces::msg::RealsenseImu::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::RealsenseImu msg_;
};

class Init_RealsenseImu_roll
{
public:
  explicit Init_RealsenseImu_roll(::my_robot_interfaces::msg::RealsenseImu & msg)
  : msg_(msg)
  {}
  Init_RealsenseImu_yaw roll(::my_robot_interfaces::msg::RealsenseImu::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_RealsenseImu_yaw(msg_);
  }

private:
  ::my_robot_interfaces::msg::RealsenseImu msg_;
};

class Init_RealsenseImu_pitch
{
public:
  Init_RealsenseImu_pitch()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RealsenseImu_roll pitch(::my_robot_interfaces::msg::RealsenseImu::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_RealsenseImu_roll(msg_);
  }

private:
  ::my_robot_interfaces::msg::RealsenseImu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::RealsenseImu>()
{
  return my_robot_interfaces::msg::builder::Init_RealsenseImu_pitch();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__REALSENSE_IMU__BUILDER_HPP_
