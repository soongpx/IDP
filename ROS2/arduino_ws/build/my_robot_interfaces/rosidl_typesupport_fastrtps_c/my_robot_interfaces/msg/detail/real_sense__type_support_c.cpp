// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from my_robot_interfaces:msg/RealSense.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/real_sense__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "my_robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "my_robot_interfaces/msg/detail/real_sense__struct.h"
#include "my_robot_interfaces/msg/detail/real_sense__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // blue, depth, green, red
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // blue, depth, green, red

// forward declare type support functions


using _RealSense__ros_msg_type = my_robot_interfaces__msg__RealSense;

static bool _RealSense__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RealSense__ros_msg_type * ros_message = static_cast<const _RealSense__ros_msg_type *>(untyped_ros_message);
  // Field name: red
  {
    size_t size = ros_message->red.size;
    auto array_ptr = ros_message->red.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: green
  {
    size_t size = ros_message->green.size;
    auto array_ptr = ros_message->green.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: blue
  {
    size_t size = ros_message->blue.size;
    auto array_ptr = ros_message->blue.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: depth
  {
    size_t size = ros_message->depth.size;
    auto array_ptr = ros_message->depth.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  return true;
}

static bool _RealSense__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RealSense__ros_msg_type * ros_message = static_cast<_RealSense__ros_msg_type *>(untyped_ros_message);
  // Field name: red
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->red.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->red);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->red, size)) {
      fprintf(stderr, "failed to create array for field 'red'");
      return false;
    }
    auto array_ptr = ros_message->red.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: green
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->green.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->green);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->green, size)) {
      fprintf(stderr, "failed to create array for field 'green'");
      return false;
    }
    auto array_ptr = ros_message->green.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: blue
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->blue.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->blue);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->blue, size)) {
      fprintf(stderr, "failed to create array for field 'blue'");
      return false;
    }
    auto array_ptr = ros_message->blue.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: depth
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->depth.data) {
      rosidl_runtime_c__uint32__Sequence__fini(&ros_message->depth);
    }
    if (!rosidl_runtime_c__uint32__Sequence__init(&ros_message->depth, size)) {
      fprintf(stderr, "failed to create array for field 'depth'");
      return false;
    }
    auto array_ptr = ros_message->depth.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: pitch
  {
    cdr >> ros_message->pitch;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_robot_interfaces
size_t get_serialized_size_my_robot_interfaces__msg__RealSense(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RealSense__ros_msg_type * ros_message = static_cast<const _RealSense__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name red
  {
    size_t array_size = ros_message->red.size;
    auto array_ptr = ros_message->red.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name green
  {
    size_t array_size = ros_message->green.size;
    auto array_ptr = ros_message->green.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name blue
  {
    size_t array_size = ros_message->blue.size;
    auto array_ptr = ros_message->blue.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name depth
  {
    size_t array_size = ros_message->depth.size;
    auto array_ptr = ros_message->depth.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch
  {
    size_t item_size = sizeof(ros_message->pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RealSense__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_my_robot_interfaces__msg__RealSense(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_my_robot_interfaces
size_t max_serialized_size_my_robot_interfaces__msg__RealSense(
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

  // member: red
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: green
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: blue
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: depth
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_robot_interfaces__msg__RealSense;
    is_plain =
      (
      offsetof(DataType, pitch) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RealSense__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_my_robot_interfaces__msg__RealSense(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RealSense = {
  "my_robot_interfaces::msg",
  "RealSense",
  _RealSense__cdr_serialize,
  _RealSense__cdr_deserialize,
  _RealSense__get_serialized_size,
  _RealSense__max_serialized_size
};

static rosidl_message_type_support_t _RealSense__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RealSense,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, my_robot_interfaces, msg, RealSense)() {
  return &_RealSense__type_support;
}

#if defined(__cplusplus)
}
#endif
