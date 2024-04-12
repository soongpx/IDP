// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/HarvestConfirmation.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST_CONFIRMATION__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST_CONFIRMATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/harvest_confirmation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_HarvestConfirmation_success
{
public:
  Init_HarvestConfirmation_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::msg::HarvestConfirmation success(::my_robot_interfaces::msg::HarvestConfirmation::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::HarvestConfirmation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::HarvestConfirmation>()
{
  return my_robot_interfaces::msg::builder::Init_HarvestConfirmation_success();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST_CONFIRMATION__BUILDER_HPP_
