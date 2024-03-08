// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_robot_interfaces:msg/LidarScan.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_robot_interfaces/msg/detail/lidar_scan__rosidl_typesupport_introspection_c.h"
#include "my_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_robot_interfaces/msg/detail/lidar_scan__functions.h"
#include "my_robot_interfaces/msg/detail/lidar_scan__struct.h"


// Include directives for member types
// Member `angle`
// Member `range`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_robot_interfaces__msg__LidarScan__init(message_memory);
}

void my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_fini_function(void * message_memory)
{
  my_robot_interfaces__msg__LidarScan__fini(message_memory);
}

size_t my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__size_function__LidarScan__angle(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_const_function__LidarScan__angle(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_function__LidarScan__angle(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__fetch_function__LidarScan__angle(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_const_function__LidarScan__angle(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__assign_function__LidarScan__angle(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_function__LidarScan__angle(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__resize_function__LidarScan__angle(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__size_function__LidarScan__range(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_const_function__LidarScan__range(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_function__LidarScan__range(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__fetch_function__LidarScan__range(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_const_function__LidarScan__range(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__assign_function__LidarScan__range(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_function__LidarScan__range(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__resize_function__LidarScan__range(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_message_member_array[3] = {
  {
    "detected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LidarScan, detected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LidarScan, angle),  // bytes offset in struct
    NULL,  // default value
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__size_function__LidarScan__angle,  // size() function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_const_function__LidarScan__angle,  // get_const(index) function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_function__LidarScan__angle,  // get(index) function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__fetch_function__LidarScan__angle,  // fetch(index, &value) function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__assign_function__LidarScan__angle,  // assign(index, value) function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__resize_function__LidarScan__angle  // resize(index) function pointer
  },
  {
    "range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__msg__LidarScan, range),  // bytes offset in struct
    NULL,  // default value
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__size_function__LidarScan__range,  // size() function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_const_function__LidarScan__range,  // get_const(index) function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__get_function__LidarScan__range,  // get(index) function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__fetch_function__LidarScan__range,  // fetch(index, &value) function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__assign_function__LidarScan__range,  // assign(index, value) function pointer
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__resize_function__LidarScan__range  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_message_members = {
  "my_robot_interfaces__msg",  // message namespace
  "LidarScan",  // message name
  3,  // number of fields
  sizeof(my_robot_interfaces__msg__LidarScan),
  my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_message_member_array,  // message members
  my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_init_function,  // function to initialize message memory (memory has to be allocated)
  my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_message_type_support_handle = {
  0,
  &my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, msg, LidarScan)() {
  if (!my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_message_type_support_handle.typesupport_identifier) {
    my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_robot_interfaces__msg__LidarScan__rosidl_typesupport_introspection_c__LidarScan_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
