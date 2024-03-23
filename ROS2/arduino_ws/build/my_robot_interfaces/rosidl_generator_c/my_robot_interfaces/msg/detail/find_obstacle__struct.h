// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/FindObstacle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FindObstacle in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__FindObstacle
{
  float nearest_distance1;
  float nearest_angle1;
  float nearest_distance2;
  float nearest_angle2;
  bool reach;
} my_robot_interfaces__msg__FindObstacle;

// Struct for a sequence of my_robot_interfaces__msg__FindObstacle.
typedef struct my_robot_interfaces__msg__FindObstacle__Sequence
{
  my_robot_interfaces__msg__FindObstacle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__FindObstacle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__STRUCT_H_
