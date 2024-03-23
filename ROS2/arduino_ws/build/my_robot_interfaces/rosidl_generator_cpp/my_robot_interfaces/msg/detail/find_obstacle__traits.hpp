// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/FindObstacle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/find_obstacle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FindObstacle & msg,
  std::ostream & out)
{
  out << "{";
  // member: nearest_distance1
  {
    out << "nearest_distance1: ";
    rosidl_generator_traits::value_to_yaml(msg.nearest_distance1, out);
    out << ", ";
  }

  // member: nearest_angle1
  {
    out << "nearest_angle1: ";
    rosidl_generator_traits::value_to_yaml(msg.nearest_angle1, out);
    out << ", ";
  }

  // member: nearest_distance2
  {
    out << "nearest_distance2: ";
    rosidl_generator_traits::value_to_yaml(msg.nearest_distance2, out);
    out << ", ";
  }

  // member: nearest_angle2
  {
    out << "nearest_angle2: ";
    rosidl_generator_traits::value_to_yaml(msg.nearest_angle2, out);
    out << ", ";
  }

  // member: reach
  {
    out << "reach: ";
    rosidl_generator_traits::value_to_yaml(msg.reach, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FindObstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: nearest_distance1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nearest_distance1: ";
    rosidl_generator_traits::value_to_yaml(msg.nearest_distance1, out);
    out << "\n";
  }

  // member: nearest_angle1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nearest_angle1: ";
    rosidl_generator_traits::value_to_yaml(msg.nearest_angle1, out);
    out << "\n";
  }

  // member: nearest_distance2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nearest_distance2: ";
    rosidl_generator_traits::value_to_yaml(msg.nearest_distance2, out);
    out << "\n";
  }

  // member: nearest_angle2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "nearest_angle2: ";
    rosidl_generator_traits::value_to_yaml(msg.nearest_angle2, out);
    out << "\n";
  }

  // member: reach
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reach: ";
    rosidl_generator_traits::value_to_yaml(msg.reach, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FindObstacle & msg, bool use_flow_style = false)
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
  const my_robot_interfaces::msg::FindObstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::FindObstacle & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::FindObstacle>()
{
  return "my_robot_interfaces::msg::FindObstacle";
}

template<>
inline const char * name<my_robot_interfaces::msg::FindObstacle>()
{
  return "my_robot_interfaces/msg/FindObstacle";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::FindObstacle>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::FindObstacle>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::msg::FindObstacle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__TRAITS_HPP_
