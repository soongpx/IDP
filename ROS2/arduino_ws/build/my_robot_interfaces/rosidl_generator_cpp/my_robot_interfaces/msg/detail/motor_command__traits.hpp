// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: left_speed
  {
    out << "left_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.left_speed, out);
    out << ", ";
  }

  // member: right_speed
  {
    out << "right_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.right_speed, out);
    out << ", ";
  }

  // member: rotate_speed
  {
    out << "rotate_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.rotate_speed, out);
    out << ", ";
  }

  // member: tilt_speed
  {
    out << "tilt_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_speed, out);
    out << ", ";
  }

  // member: extend_speed
  {
    out << "extend_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.extend_speed, out);
    out << ", ";
  }

  // member: vibrate_speed
  {
    out << "vibrate_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.vibrate_speed, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.left_speed, out);
    out << "\n";
  }

  // member: right_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.right_speed, out);
    out << "\n";
  }

  // member: rotate_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotate_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.rotate_speed, out);
    out << "\n";
  }

  // member: tilt_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_speed, out);
    out << "\n";
  }

  // member: extend_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "extend_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.extend_speed, out);
    out << "\n";
  }

  // member: vibrate_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vibrate_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.vibrate_speed, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::msg::MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::MotorCommand & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::MotorCommand>()
{
  return "my_robot_interfaces::msg::MotorCommand";
}

template<>
inline const char * name<my_robot_interfaces::msg::MotorCommand>()
{
  return "my_robot_interfaces/msg/MotorCommand";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::MotorCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::MotorCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::msg::MotorCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
