// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/LidarScan.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/lidar_scan__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LidarScan & msg,
  std::ostream & out)
{
  out << "{";
  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << ", ";
  }

  // member: angle
  {
    if (msg.angle.size() == 0) {
      out << "angle: []";
    } else {
      out << "angle: [";
      size_t pending_items = msg.angle.size();
      for (auto item : msg.angle) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: range
  {
    if (msg.range.size() == 0) {
      out << "range: []";
    } else {
      out << "range: [";
      size_t pending_items = msg.range.size();
      for (auto item : msg.range) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LidarScan & msg,
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

  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.angle.size() == 0) {
      out << "angle: []\n";
    } else {
      out << "angle:\n";
      for (auto item : msg.angle) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.range.size() == 0) {
      out << "range: []\n";
    } else {
      out << "range:\n";
      for (auto item : msg.range) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LidarScan & msg, bool use_flow_style = false)
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
  const my_robot_interfaces::msg::LidarScan & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::LidarScan & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::LidarScan>()
{
  return "my_robot_interfaces::msg::LidarScan";
}

template<>
inline const char * name<my_robot_interfaces::msg::LidarScan>()
{
  return "my_robot_interfaces/msg/LidarScan";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::LidarScan>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::LidarScan>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::msg::LidarScan>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__TRAITS_HPP_
