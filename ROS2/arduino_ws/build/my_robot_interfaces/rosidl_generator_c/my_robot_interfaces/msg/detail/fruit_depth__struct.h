// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/FruitDepth.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FruitDepth in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__FruitDepth
{
  bool detected;
  uint8_t palm_oil_num;
  float fruit_depth;
  int8_t pitch_direction;
  int8_t yaw_direction;
} my_robot_interfaces__msg__FruitDepth;

// Struct for a sequence of my_robot_interfaces__msg__FruitDepth.
typedef struct my_robot_interfaces__msg__FruitDepth__Sequence
{
  my_robot_interfaces__msg__FruitDepth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__FruitDepth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__STRUCT_H_
