// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/Joystick.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__JOYSTICK__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__JOYSTICK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'axes'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'axes_name'
// Member 'button'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Joystick in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__Joystick
{
  rosidl_runtime_c__double__Sequence axes;
  rosidl_runtime_c__String__Sequence axes_name;
  rosidl_runtime_c__String__Sequence button;
} my_robot_interfaces__msg__Joystick;

// Struct for a sequence of my_robot_interfaces__msg__Joystick.
typedef struct my_robot_interfaces__msg__Joystick__Sequence
{
  my_robot_interfaces__msg__Joystick * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__Joystick__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__JOYSTICK__STRUCT_H_
