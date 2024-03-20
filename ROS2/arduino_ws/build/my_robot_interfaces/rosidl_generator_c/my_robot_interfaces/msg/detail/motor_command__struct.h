// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorCommand in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__MotorCommand
{
  int32_t left_speed;
  int32_t right_speed;
  int32_t rotate_speed;
  int32_t tilt_speed;
  int32_t extend_speed;
  int32_t vibrate_speed;
  int32_t direction;
} my_robot_interfaces__msg__MotorCommand;

// Struct for a sequence of my_robot_interfaces__msg__MotorCommand.
typedef struct my_robot_interfaces__msg__MotorCommand__Sequence
{
  my_robot_interfaces__msg__MotorCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__MotorCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_
