// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__IMU_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/imu_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_ImuData_yaw
{
public:
  explicit Init_ImuData_yaw(::my_robot_interfaces::msg::ImuData & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::ImuData yaw(::my_robot_interfaces::msg::ImuData::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::ImuData msg_;
};

class Init_ImuData_roll
{
public:
  explicit Init_ImuData_roll(::my_robot_interfaces::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_yaw roll(::my_robot_interfaces::msg::ImuData::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_ImuData_yaw(msg_);
  }

private:
  ::my_robot_interfaces::msg::ImuData msg_;
};

class Init_ImuData_pitch
{
public:
  explicit Init_ImuData_pitch(::my_robot_interfaces::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_roll pitch(::my_robot_interfaces::msg::ImuData::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_ImuData_roll(msg_);
  }

private:
  ::my_robot_interfaces::msg::ImuData msg_;
};

class Init_ImuData_temperature
{
public:
  Init_ImuData_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuData_pitch temperature(::my_robot_interfaces::msg::ImuData::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_ImuData_pitch(msg_);
  }

private:
  ::my_robot_interfaces::msg::ImuData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::ImuData>()
{
  return my_robot_interfaces::msg::builder::Init_ImuData_temperature();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
