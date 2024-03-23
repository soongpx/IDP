// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_robot_interfaces:msg/FindObstacle.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/find_obstacle__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_robot_interfaces/msg/detail/find_obstacle__struct.h"
#include "my_robot_interfaces/msg/detail/find_obstacle__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _FindObstacle__ros_msg_type = my_robot_interfaces__msg__FindObstacle;

static bool _FindObstacle__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FindObstacle__ros_msg_type * ros_message = static_cast<const _FindObstacle__ros_msg_type *>(untyped_ros_message);
  // Field name: nearest_distance1
  {
    cdr << ros_message->nearest_distance1;
  }

  // Field name: nearest_angle1
  {
    cdr << ros_message->nearest_angle1;
  }

  // Field name: nearest_distance2
  {
    cdr << ros_message->nearest_distance2;
  }

  // Field name: nearest_angle2
  {
    cdr << ros_message->nearest_angle2;
  }

  // Field name: reach
  {
    cdr << (ros_message->reach ? true : false);
  }

  return true;
}

static bool _FindObstacle__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FindObstacle__ros_msg_type * ros_message = static_cast<_FindObstacle__ros_msg_type *>(untyped_ros_message);
  // Field name: nearest_distance1
  {
    cdr >> ros_message->nearest_distance1;
  }

  // Field name: nearest_angle1
  {
    cdr >> ros_message->nearest_angle1;
  }

  // Field name: nearest_distance2
  {
    cdr >> ros_message->nearest_distance2;
  }

  // Field name: nearest_angle2
  {
    cdr >> ros_message->nearest_angle2;
  }

  // Field name: reach
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->reach = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_robot_interfaces
size_t get_serialized_size_my_robot_interfaces__msg__FindObstacle(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FindObstacle__ros_msg_type * ros_message = static_cast<const _FindObstacle__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name nearest_distance1
  {
    size_t item_size = sizeof(ros_message->nearest_distance1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nearest_angle1
  {
    size_t item_size = sizeof(ros_message->nearest_angle1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nearest_distance2
  {
    size_t item_size = sizeof(ros_message->nearest_distance2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nearest_angle2
  {
    size_t item_size = sizeof(ros_message->nearest_angle2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reach
  {
    size_t item_size = sizeof(ros_message->reach);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FindObstacle__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_robot_interfaces__msg__FindObstacle(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_robot_interfaces
size_t max_serialized_size_my_robot_interfaces__msg__FindObstacle(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: nearest_distance1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nearest_angle1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nearest_distance2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nearest_angle2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: reach
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_robot_interfaces__msg__FindObstacle;
    is_plain =
      (
      offsetof(DataType, reach) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FindObstacle__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_robot_interfaces__msg__FindObstacle(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FindObstacle = {
  "my_robot_interfaces::msg",
  "FindObstacle",
  _FindObstacle__cdr_serialize,
  _FindObstacle__cdr_deserialize,
  _FindObstacle__get_serialized_size,
  _FindObstacle__max_serialized_size
};

static rosidl_message_type_support_t _FindObstacle__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FindObstacle,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, msg, FindObstacle)() {
  return &_FindObstacle__type_support;
}

#if defined(__cplusplus)
}
#endif
