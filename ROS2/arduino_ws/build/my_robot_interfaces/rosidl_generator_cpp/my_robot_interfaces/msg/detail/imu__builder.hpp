// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__IMU__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Imu_yaw
{
public:
  explicit Init_Imu_yaw(::my_robot_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::Imu yaw(::my_robot_interfaces::msg::Imu::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::Imu msg_;
};

class Init_Imu_roll
{
public:
  explicit Init_Imu_roll(::my_robot_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_yaw roll(::my_robot_interfaces::msg::Imu::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Imu_yaw(msg_);
  }

private:
  ::my_robot_interfaces::msg::Imu msg_;
};

class Init_Imu_pitch
{
public:
  explicit Init_Imu_pitch(::my_robot_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_roll pitch(::my_robot_interfaces::msg::Imu::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Imu_roll(msg_);
  }

private:
  ::my_robot_interfaces::msg::Imu msg_;
};

class Init_Imu_temperature
{
public:
  Init_Imu_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Imu_pitch temperature(::my_robot_interfaces::msg::Imu::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_Imu_pitch(msg_);
  }

private:
  ::my_robot_interfaces::msg::Imu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::Imu>()
{
  return my_robot_interfaces::msg::builder::Init_Imu_temperature();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__IMU__BUILDER_HPP_
