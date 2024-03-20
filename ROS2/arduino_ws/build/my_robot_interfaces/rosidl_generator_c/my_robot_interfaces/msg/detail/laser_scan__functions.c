// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/LaserScan.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/laser_scan__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `ranges`
// Member `intensities`
// Member `angles`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
my_robot_interfaces__msg__LaserScan__init(my_robot_interfaces__msg__LaserScan * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    my_robot_interfaces__msg__LaserScan__fini(msg);
    return false;
  }
  // angle_min
  // angle_max
  // angle_increment
  // time_increment
  // scan_time
  // range_min
  // range_max
  // ranges
  if (!rosidl_runtime_c__float__Sequence__init(&msg->ranges, 0)) {
    my_robot_interfaces__msg__LaserScan__fini(msg);
    return false;
  }
  // intensities
  if (!rosidl_runtime_c__float__Sequence__init(&msg->intensities, 0)) {
    my_robot_interfaces__msg__LaserScan__fini(msg);
    return false;
  }
  // angles
  if (!rosidl_runtime_c__float__Sequence__init(&msg->angles, 0)) {
    my_robot_interfaces__msg__LaserScan__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__msg__LaserScan__fini(my_robot_interfaces__msg__LaserScan * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // angle_min
  // angle_max
  // angle_increment
  // time_increment
  // scan_time
  // range_min
  // range_max
  // ranges
  rosidl_runtime_c__float__Sequence__fini(&msg->ranges);
  // intensities
  rosidl_runtime_c__float__Sequence__fini(&msg->intensities);
  // angles
  rosidl_runtime_c__float__Sequence__fini(&msg->angles);
}

bool
my_robot_interfaces__msg__LaserScan__are_equal(const my_robot_interfaces__msg__LaserScan * lhs, const my_robot_interfaces__msg__LaserScan * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // angle_min
  if (lhs->angle_min != rhs->angle_min) {
    return false;
  }
  // angle_max
  if (lhs->angle_max != rhs->angle_max) {
    return false;
  }
  // angle_increment
  if (lhs->angle_increment != rhs->angle_increment) {
    return false;
  }
  // time_increment
  if (lhs->time_increment != rhs->time_increment) {
    return false;
  }
  // scan_time
  if (lhs->scan_time != rhs->scan_time) {
    return false;
  }
  // range_min
  if (lhs->range_min != rhs->range_min) {
    return false;
  }
  // range_max
  if (lhs->range_max != rhs->range_max) {
    return false;
  }
  // ranges
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->ranges), &(rhs->ranges)))
  {
    return false;
  }
  // intensities
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->intensities), &(rhs->intensities)))
  {
    return false;
  }
  // angles
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->angles), &(rhs->angles)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__LaserScan__copy(
  const my_robot_interfaces__msg__LaserScan * input,
  my_robot_interfaces__msg__LaserScan * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // angle_min
  output->angle_min = input->angle_min;
  // angle_max
  output->angle_max = input->angle_max;
  // angle_increment
  output->angle_increment = input->angle_increment;
  // time_increment
  output->time_increment = input->time_increment;
  // scan_time
  output->scan_time = input->scan_time;
  // range_min
  output->range_min = input->range_min;
  // range_max
  output->range_max = input->range_max;
  // ranges
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->ranges), &(output->ranges)))
  {
    return false;
  }
  // intensities
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->intensities), &(output->intensities)))
  {
    return false;
  }
  // angles
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->angles), &(output->angles)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__msg__LaserScan *
my_robot_interfaces__msg__LaserScan__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__LaserScan * msg = (my_robot_interfaces__msg__LaserScan *)allocator.allocate(sizeof(my_robot_interfaces__msg__LaserScan), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__LaserScan));
  bool success = my_robot_interfaces__msg__LaserScan__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__LaserScan__destroy(my_robot_interfaces__msg__LaserScan * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__LaserScan__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__LaserScan__Sequence__init(my_robot_interfaces__msg__LaserScan__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__LaserScan * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__LaserScan *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__LaserScan), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__LaserScan__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__LaserScan__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_robot_interfaces__msg__LaserScan__Sequence__fini(my_robot_interfaces__msg__LaserScan__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_interfaces__msg__LaserScan__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_robot_interfaces__msg__LaserScan__Sequence *
my_robot_interfaces__msg__LaserScan__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__LaserScan__Sequence * array = (my_robot_interfaces__msg__LaserScan__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__LaserScan__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__LaserScan__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__LaserScan__Sequence__destroy(my_robot_interfaces__msg__LaserScan__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__LaserScan__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__LaserScan__Sequence__are_equal(const my_robot_interfaces__msg__LaserScan__Sequence * lhs, const my_robot_interfaces__msg__LaserScan__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__LaserScan__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__LaserScan__Sequence__copy(
  const my_robot_interfaces__msg__LaserScan__Sequence * input,
  my_robot_interfaces__msg__LaserScan__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__LaserScan);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__LaserScan * data =
      (my_robot_interfaces__msg__LaserScan *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__LaserScan__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__LaserScan__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__LaserScan__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
