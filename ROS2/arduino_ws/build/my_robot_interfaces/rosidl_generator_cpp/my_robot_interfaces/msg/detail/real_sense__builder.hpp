// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/RealSense.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/real_sense__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_RealSense_depth
{
public:
  explicit Init_RealSense_depth(::my_robot_interfaces::msg::RealSense & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::RealSense depth(::my_robot_interfaces::msg::RealSense::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::RealSense msg_;
};

class Init_RealSense_blue
{
public:
  explicit Init_RealSense_blue(::my_robot_interfaces::msg::RealSense & msg)
  : msg_(msg)
  {}
  Init_RealSense_depth blue(::my_robot_interfaces::msg::RealSense::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return Init_RealSense_depth(msg_);
  }

private:
  ::my_robot_interfaces::msg::RealSense msg_;
};

class Init_RealSense_green
{
public:
  explicit Init_RealSense_green(::my_robot_interfaces::msg::RealSense & msg)
  : msg_(msg)
  {}
  Init_RealSense_blue green(::my_robot_interfaces::msg::RealSense::_green_type arg)
  {
    msg_.green = std::move(arg);
    return Init_RealSense_blue(msg_);
  }

private:
  ::my_robot_interfaces::msg::RealSense msg_;
};

class Init_RealSense_red
{
public:
  Init_RealSense_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RealSense_green red(::my_robot_interfaces::msg::RealSense::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_RealSense_green(msg_);
  }

private:
  ::my_robot_interfaces::msg::RealSense msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::RealSense>()
{
  return my_robot_interfaces::msg::builder::Init_RealSense_red();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__BUILDER_HPP_
