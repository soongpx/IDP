// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/RealSense.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/real_sense__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RealSense & msg,
  std::ostream & out)
{
  out << "{";
  // member: red
  {
    if (msg.red.size() == 0) {
      out << "red: []";
    } else {
      out << "red: [";
      size_t pending_items = msg.red.size();
      for (auto item : msg.red) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: green
  {
    if (msg.green.size() == 0) {
      out << "green: []";
    } else {
      out << "green: [";
      size_t pending_items = msg.green.size();
      for (auto item : msg.green) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: blue
  {
    if (msg.blue.size() == 0) {
      out << "blue: []";
    } else {
      out << "blue: [";
      size_t pending_items = msg.blue.size();
      for (auto item : msg.blue) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: depth
  {
    if (msg.depth.size() == 0) {
      out << "depth: []";
    } else {
      out << "depth: [";
      size_t pending_items = msg.depth.size();
      for (auto item : msg.depth) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RealSense & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: red
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.red.size() == 0) {
      out << "red: []\n";
    } else {
      out << "red:\n";
      for (auto item : msg.red) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: green
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.green.size() == 0) {
      out << "green: []\n";
    } else {
      out << "green:\n";
      for (auto item : msg.green) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: blue
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.blue.size() == 0) {
      out << "blue: []\n";
    } else {
      out << "blue:\n";
      for (auto item : msg.blue) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.depth.size() == 0) {
      out << "depth: []\n";
    } else {
      out << "depth:\n";
      for (auto item : msg.depth) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RealSense & msg, bool use_flow_style = false)
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
  const my_robot_interfaces::msg::RealSense & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::RealSense & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::RealSense>()
{
  return "my_robot_interfaces::msg::RealSense";
}

template<>
inline const char * name<my_robot_interfaces::msg::RealSense>()
{
  return "my_robot_interfaces/msg/RealSense";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::RealSense>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::RealSense>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::msg::RealSense>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__TRAITS_HPP_
