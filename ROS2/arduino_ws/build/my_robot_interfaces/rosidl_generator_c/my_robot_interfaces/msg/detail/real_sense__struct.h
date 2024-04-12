// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/RealSense.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'red'
// Member 'green'
// Member 'blue'
// Member 'depth'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RealSense in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__RealSense
{
  rosidl_runtime_c__uint8__Sequence red;
  rosidl_runtime_c__uint8__Sequence green;
  rosidl_runtime_c__uint8__Sequence blue;
  rosidl_runtime_c__uint32__Sequence depth;
  double pitch;
} my_robot_interfaces__msg__RealSense;

// Struct for a sequence of my_robot_interfaces__msg__RealSense.
typedef struct my_robot_interfaces__msg__RealSense__Sequence
{
  my_robot_interfaces__msg__RealSense * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__RealSense__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__REAL_SENSE__STRUCT_H_
