// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/Harvest.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/harvest__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Harvest_harvest_end
{
public:
  Init_Harvest_harvest_end()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::Harvest harvest_end(::my_robot_interfaces::msg::Harvest::_harvest_end_type arg)
  {
    msg_.harvest_end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::Harvest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::Harvest>()
{
  return my_robot_interfaces::msg::builder::Init_Harvest_harvest_end();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__BUILDER_HPP_
