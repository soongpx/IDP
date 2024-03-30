// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__IMU__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__IMU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Imu in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__Imu
{
  float temperature;
  float pitch;
  float roll;
  float yaw;
} my_robot_interfaces__msg__Imu;

// Struct for a sequence of my_robot_interfaces__msg__Imu.
typedef struct my_robot_interfaces__msg__Imu__Sequence
{
  my_robot_interfaces__msg__Imu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__Imu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__IMU__STRUCT_H_
