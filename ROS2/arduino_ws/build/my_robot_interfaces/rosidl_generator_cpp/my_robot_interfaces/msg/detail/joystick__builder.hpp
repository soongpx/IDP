// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/Joystick.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__JOYSTICK__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__JOYSTICK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/joystick__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Joystick_button
{
public:
  explicit Init_Joystick_button(::my_robot_interfaces::msg::Joystick & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::Joystick button(::my_robot_interfaces::msg::Joystick::_button_type arg)
  {
    msg_.button = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::Joystick msg_;
};

class Init_Joystick_axes_name
{
public:
  explicit Init_Joystick_axes_name(::my_robot_interfaces::msg::Joystick & msg)
  : msg_(msg)
  {}
  Init_Joystick_button axes_name(::my_robot_interfaces::msg::Joystick::_axes_name_type arg)
  {
    msg_.axes_name = std::move(arg);
    return Init_Joystick_button(msg_);
  }

private:
  ::my_robot_interfaces::msg::Joystick msg_;
};

class Init_Joystick_axes
{
public:
  Init_Joystick_axes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Joystick_axes_name axes(::my_robot_interfaces::msg::Joystick::_axes_type arg)
  {
    msg_.axes = std::move(arg);
    return Init_Joystick_axes_name(msg_);
  }

private:
  ::my_robot_interfaces::msg::Joystick msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::Joystick>()
{
  return my_robot_interfaces::msg::builder::Init_Joystick_axes();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__JOYSTICK__BUILDER_HPP_
