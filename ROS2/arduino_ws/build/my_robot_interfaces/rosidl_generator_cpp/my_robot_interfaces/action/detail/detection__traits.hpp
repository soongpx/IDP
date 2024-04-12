// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:action/Detection.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__DETECTION__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/action/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Detection_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::Detection_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::Detection_Goal & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_Goal>()
{
  return "my_robot_interfaces::action::Detection_Goal";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_Goal>()
{
  return "my_robot_interfaces/action/Detection_Goal";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::action::Detection_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Detection_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << ", ";
  }

  // member: fruit_depth
  {
    out << "fruit_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.fruit_depth, out);
    out << ", ";
  }

  // member: fruit_number
  {
    out << "fruit_number: ";
    rosidl_generator_traits::value_to_yaml(msg.fruit_number, out);
    out << ", ";
  }

  // member: target_pitch
  {
    out << "target_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.target_pitch, out);
    out << ", ";
  }

  // member: target_yaw
  {
    out << "target_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.target_yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_Result & msg,
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

  // member: fruit_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fruit_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.fruit_depth, out);
    out << "\n";
  }

  // member: fruit_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fruit_number: ";
    rosidl_generator_traits::value_to_yaml(msg.fruit_number, out);
    out << "\n";
  }

  // member: target_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.target_pitch, out);
    out << "\n";
  }

  // member: target_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.target_yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::Detection_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::Detection_Result & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_Result>()
{
  return "my_robot_interfaces::action::Detection_Result";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_Result>()
{
  return "my_robot_interfaces/action/Detection_Result";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::action::Detection_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Detection_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: fruit_detected
  {
    out << "fruit_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.fruit_detected, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fruit_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fruit_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.fruit_detected, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::Detection_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::Detection_Feedback & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_Feedback>()
{
  return "my_robot_interfaces::action::Detection_Feedback";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_Feedback>()
{
  return "my_robot_interfaces/action/Detection_Feedback";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_robot_interfaces::action::Detection_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "my_robot_interfaces/action/detail/detection__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Detection_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::Detection_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::Detection_SendGoal_Request & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_SendGoal_Request>()
{
  return "my_robot_interfaces::action::Detection_SendGoal_Request";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_SendGoal_Request>()
{
  return "my_robot_interfaces/action/Detection_SendGoal_Request";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<my_robot_interfaces::action::Detection_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<my_robot_interfaces::action::Detection_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<my_robot_interfaces::action::Detection_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Detection_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::Detection_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::Detection_SendGoal_Response & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_SendGoal_Response>()
{
  return "my_robot_interfaces::action::Detection_SendGoal_Response";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_SendGoal_Response>()
{
  return "my_robot_interfaces/action/Detection_SendGoal_Response";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<my_robot_interfaces::action::Detection_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_SendGoal>()
{
  return "my_robot_interfaces::action::Detection_SendGoal";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_SendGoal>()
{
  return "my_robot_interfaces/action/Detection_SendGoal";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<my_robot_interfaces::action::Detection_SendGoal_Request>::value &&
    has_fixed_size<my_robot_interfaces::action::Detection_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<my_robot_interfaces::action::Detection_SendGoal_Request>::value &&
    has_bounded_size<my_robot_interfaces::action::Detection_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<my_robot_interfaces::action::Detection_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<my_robot_interfaces::action::Detection_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_robot_interfaces::action::Detection_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Detection_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::Detection_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::Detection_GetResult_Request & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_GetResult_Request>()
{
  return "my_robot_interfaces::action::Detection_GetResult_Request";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_GetResult_Request>()
{
  return "my_robot_interfaces/action/Detection_GetResult_Request";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<my_robot_interfaces::action::Detection_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "my_robot_interfaces/action/detail/detection__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Detection_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::Detection_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::Detection_GetResult_Response & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_GetResult_Response>()
{
  return "my_robot_interfaces::action::Detection_GetResult_Response";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_GetResult_Response>()
{
  return "my_robot_interfaces/action/Detection_GetResult_Response";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<my_robot_interfaces::action::Detection_Result>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<my_robot_interfaces::action::Detection_Result>::value> {};

template<>
struct is_message<my_robot_interfaces::action::Detection_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_GetResult>()
{
  return "my_robot_interfaces::action::Detection_GetResult";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_GetResult>()
{
  return "my_robot_interfaces/action/Detection_GetResult";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<my_robot_interfaces::action::Detection_GetResult_Request>::value &&
    has_fixed_size<my_robot_interfaces::action::Detection_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<my_robot_interfaces::action::Detection_GetResult_Request>::value &&
    has_bounded_size<my_robot_interfaces::action::Detection_GetResult_Response>::value
  >
{
};

template<>
struct is_service<my_robot_interfaces::action::Detection_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<my_robot_interfaces::action::Detection_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_robot_interfaces::action::Detection_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "my_robot_interfaces/action/detail/detection__traits.hpp"

namespace my_robot_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Detection_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detection_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detection_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::action::Detection_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::action::Detection_FeedbackMessage & msg)
{
  return my_robot_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::action::Detection_FeedbackMessage>()
{
  return "my_robot_interfaces::action::Detection_FeedbackMessage";
}

template<>
inline const char * name<my_robot_interfaces::action::Detection_FeedbackMessage>()
{
  return "my_robot_interfaces/action/Detection_FeedbackMessage";
}

template<>
struct has_fixed_size<my_robot_interfaces::action::Detection_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<my_robot_interfaces::action::Detection_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<my_robot_interfaces::action::Detection_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<my_robot_interfaces::action::Detection_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<my_robot_interfaces::action::Detection_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<my_robot_interfaces::action::Detection>
  : std::true_type
{
};

template<>
struct is_action_goal<my_robot_interfaces::action::Detection_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<my_robot_interfaces::action::Detection_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<my_robot_interfaces::action::Detection_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__DETECTION__TRAITS_HPP_
