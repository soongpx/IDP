// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_robot_interfaces:msg/LaserScan.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_robot_interfaces/msg/detail/laser_scan__rosidl_typesupport_introspection_c.h"
#include "my_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_robot_interfaces/msg/detail/laser_scan__functions.h"
#include "my_robot_interfaces/msg/detail/laser_scan__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `ranges`
// Member `intensities`
// Member `angles`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_robot_interfaces__msg__LaserScan__init(message_memory);
}

void my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_fini_function(void * message_memory)
{
  my_robot_interfaces__msg__LaserScan__fini(message_memory);
}

size_t my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__size_function__LaserScan__ranges(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__ranges(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__ranges(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__fetch_function__LaserScan__ranges(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__ranges(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__assign_function__LaserScan__ranges(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__ranges(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__resize_function__LaserScan__ranges(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__size_function__LaserScan__intensities(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__intensities(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__intensities(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__fetch_function__LaserScan__intensities(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__intensities(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__assign_function__LaserScan__intensities(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__intensities(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__resize_function__LaserScan__intensities(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__size_function__LaserScan__angles(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__angles(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__angles(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__fetch_function__LaserScan__angles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__angles(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__assign_function__LaserScan__angles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__angles(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__resize_function__LaserScan__angles(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_member_array[11] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle_min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, angle_min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, angle_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle_increment",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, angle_increment),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time_increment",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, time_increment),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scan_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, scan_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, range_min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, range_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ranges",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, ranges),  // bytes offset in struct
    NULL,  // default value
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__size_function__LaserScan__ranges,  // size() function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__ranges,  // get_const(index) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__ranges,  // get(index) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__fetch_function__LaserScan__ranges,  // fetch(index, &value) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__assign_function__LaserScan__ranges,  // assign(index, value) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__resize_function__LaserScan__ranges  // resize(index) function pointer
  },
  {
    "intensities",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, intensities),  // bytes offset in struct
    NULL,  // default value
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__size_function__LaserScan__intensities,  // size() function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__intensities,  // get_const(index) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__intensities,  // get(index) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__fetch_function__LaserScan__intensities,  // fetch(index, &value) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__assign_function__LaserScan__intensities,  // assign(index, value) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__resize_function__LaserScan__intensities  // resize(index) function pointer
  },
  {
    "angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LaserScan, angles),  // bytes offset in struct
    NULL,  // default value
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__size_function__LaserScan__angles,  // size() function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_const_function__LaserScan__angles,  // get_const(index) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__get_function__LaserScan__angles,  // get(index) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__fetch_function__LaserScan__angles,  // fetch(index, &value) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__assign_function__LaserScan__angles,  // assign(index, value) function pointer
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__resize_function__LaserScan__angles  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_members = {
  "my_robot_interfaces__msg",  // message namespace
  "LaserScan",  // message name
  11,  // number of fields
  sizeof(my_robot_interfaces__msg__LaserScan),
  my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_member_array,  // message members
  my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_init_function,  // function to initialize message memory (memory has to be allocated)
  my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_type_support_handle = {
  0,
  &my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, msg, LaserScan)() {
  my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_type_support_handle.typesupport_identifier) {
    my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_robot_interfaces__msg__LaserScan__rosidl_typesupport_introspection_c__LaserScan_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
