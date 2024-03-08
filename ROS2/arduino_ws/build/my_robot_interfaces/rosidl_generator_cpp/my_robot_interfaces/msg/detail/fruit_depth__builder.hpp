// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/FruitDepth.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/fruit_depth__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_FruitDepth_depth
{
public:
  explicit Init_FruitDepth_depth(::my_robot_interfaces::msg::FruitDepth & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::FruitDepth depth(::my_robot_interfaces::msg::FruitDepth::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::FruitDepth msg_;
};

class Init_FruitDepth_detected
{
public:
  Init_FruitDepth_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FruitDepth_depth detected(::my_robot_interfaces::msg::FruitDepth::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_FruitDepth_depth(msg_);
  }

private:
  ::my_robot_interfaces::msg::FruitDepth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::FruitDepth>()
{
  return my_robot_interfaces::msg::builder::Init_FruitDepth_detected();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__BUILDER_HPP_
