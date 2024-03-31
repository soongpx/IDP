// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:msg/Harvest.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/msg/detail/harvest__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Harvest & msg,
  std::ostream & out)
{
  out << "{";
  // member: harvest_end
  {
    out << "harvest_end: ";
    rosidl_generator_traits::value_to_yaml(msg.harvest_end, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Harvest & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: harvest_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "harvest_end: ";
    rosidl_generator_traits::value_to_yaml(msg.harvest_end, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Harvest & msg, bool use_flow_style = false)
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
  const my_robot_interfaces::msg::Harvest & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::msg::Harvest & msg)
{
  return my_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::msg::Harvest>()
{
  return "my_robot_interfaces::msg::Harvest";
}

template<>
inline const char * name<my_robot_interfaces::msg::Harvest>()
{
  return "my_robot_interfaces/msg/Harvest";
}

template<>
struct has_fixed_size<my_robot_interfaces::msg::Harvest>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::msg::Harvest>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::msg::Harvest>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__TRAITS_HPP_
