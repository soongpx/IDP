// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorCommand_direction
{
public:
  explicit Init_MotorCommand_direction(::my_robot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::MotorCommand direction(::my_robot_interfaces::msg::MotorCommand::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_vibrate_speed
{
public:
  explicit Init_MotorCommand_vibrate_speed(::my_robot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_direction vibrate_speed(::my_robot_interfaces::msg::MotorCommand::_vibrate_speed_type arg)
  {
    msg_.vibrate_speed = std::move(arg);
    return Init_MotorCommand_direction(msg_);
  }

private:
  ::my_robot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_extend_speed
{
public:
  explicit Init_MotorCommand_extend_speed(::my_robot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_vibrate_speed extend_speed(::my_robot_interfaces::msg::MotorCommand::_extend_speed_type arg)
  {
    msg_.extend_speed = std::move(arg);
    return Init_MotorCommand_vibrate_speed(msg_);
  }

private:
  ::my_robot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_tilt_speed
{
public:
  explicit Init_MotorCommand_tilt_speed(::my_robot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_extend_speed tilt_speed(::my_robot_interfaces::msg::MotorCommand::_tilt_speed_type arg)
  {
    msg_.tilt_speed = std::move(arg);
    return Init_MotorCommand_extend_speed(msg_);
  }

private:
  ::my_robot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_rotate_speed
{
public:
  explicit Init_MotorCommand_rotate_speed(::my_robot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_tilt_speed rotate_speed(::my_robot_interfaces::msg::MotorCommand::_rotate_speed_type arg)
  {
    msg_.rotate_speed = std::move(arg);
    return Init_MotorCommand_tilt_speed(msg_);
  }

private:
  ::my_robot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_right_speed
{
public:
  explicit Init_MotorCommand_right_speed(::my_robot_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_rotate_speed right_speed(::my_robot_interfaces::msg::MotorCommand::_right_speed_type arg)
  {
    msg_.right_speed = std::move(arg);
    return Init_MotorCommand_rotate_speed(msg_);
  }

private:
  ::my_robot_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_left_speed
{
public:
  Init_MotorCommand_left_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCommand_right_speed left_speed(::my_robot_interfaces::msg::MotorCommand::_left_speed_type arg)
  {
    msg_.left_speed = std::move(arg);
    return Init_MotorCommand_right_speed(msg_);
  }

private:
  ::my_robot_interfaces::msg::MotorCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::MotorCommand>()
{
  return my_robot_interfaces::msg::builder::Init_MotorCommand_left_speed();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
