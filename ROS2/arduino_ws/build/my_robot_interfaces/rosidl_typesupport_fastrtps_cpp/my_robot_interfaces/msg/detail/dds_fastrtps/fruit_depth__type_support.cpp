// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from my_robot_interfaces:msg/FruitDepth.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/fruit_depth__rosidl_typesupport_fastrtps_cpp.hpp"
#include "my_robot_interfaces/msg/detail/fruit_depth__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace my_robot_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_robot_interfaces
cdr_serialize(
  const my_robot_interfaces::msg::FruitDepth & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: detected
  cdr << (ros_message.detected ? true : false);
  // Member: depth
  cdr << ros_message.depth;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_robot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  my_robot_interfaces::msg::FruitDepth & ros_message)
{
  // Member: detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.detected = tmp ? true : false;
  }

  // Member: depth
  cdr >> ros_message.depth;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_robot_interfaces
get_serialized_size(
  const my_robot_interfaces::msg::FruitDepth & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: detected
  {
    size_t item_size = sizeof(ros_message.detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: depth
  {
    size_t item_size = sizeof(ros_message.depth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_robot_interfaces
max_serialized_size_FruitDepth(
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


  // Member: detected
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: depth
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
    using DataType = my_robot_interfaces::msg::FruitDepth;
    is_plain =
      (
      offsetof(DataType, depth) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _FruitDepth__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const my_robot_interfaces::msg::FruitDepth *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FruitDepth__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<my_robot_interfaces::msg::FruitDepth *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FruitDepth__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const my_robot_interfaces::msg::FruitDepth *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FruitDepth__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FruitDepth(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FruitDepth__callbacks = {
  "my_robot_interfaces::msg",
  "FruitDepth",
  _FruitDepth__cdr_serialize,
  _FruitDepth__cdr_deserialize,
  _FruitDepth__get_serialized_size,
  _FruitDepth__max_serialized_size
};

static rosidl_message_type_support_t _FruitDepth__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FruitDepth__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace my_robot_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_my_robot_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<my_robot_interfaces::msg::FruitDepth>()
{
  return &my_robot_interfaces::msg::typesupport_fastrtps_cpp::_FruitDepth__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, my_robot_interfaces, msg, FruitDepth)() {
  return &my_robot_interfaces::msg::typesupport_fastrtps_cpp::_FruitDepth__handle;
}

#ifdef __cplusplus
}
#endif
