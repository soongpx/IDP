// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/FruitDepth.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/fruit_depth__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FruitDepth & msg,
  std::ostream & out)
{
  out << "{";
  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << ", ";
  }

  // member: palm_oil_num
  {
    out << "palm_oil_num: ";
    rosidl_generator_traits::value_to_yaml(msg.palm_oil_num, out);
    out << ", ";
  }

  // member: fruit_depth
  {
    out << "fruit_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.fruit_depth, out);
    out << ", ";
  }

  // member: pitch_direction
  {
    out << "pitch_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_direction, out);
    out << ", ";
  }

  // member: yaw_direction
  {
    out << "yaw_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_direction, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FruitDepth & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << "\n";
  }

  // member: palm_oil_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "palm_oil_num: ";
    rosidl_generator_traits::value_to_yaml(msg.palm_oil_num, out);
    out << "\n";
  }

  // member: fruit_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fruit_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.fruit_depth, out);
    out << "\n";
  }

  // member: pitch_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_direction, out);
    out << "\n";
  }

  // member: yaw_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_direction, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FruitDepth & msg, bool use_flow_style = false)
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
  const my_robot_interfaces::msg::FruitDepth & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::FruitDepth & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::FruitDepth>()
{
  return "my_robot_interfaces::msg::FruitDepth";
}

template<>
inline const char * name<my_robot_interfaces::msg::FruitDepth>()
{
  return "my_robot_interfaces/msg/FruitDepth";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::FruitDepth>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::FruitDepth>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::msg::FruitDepth>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__TRAITS_HPP_
