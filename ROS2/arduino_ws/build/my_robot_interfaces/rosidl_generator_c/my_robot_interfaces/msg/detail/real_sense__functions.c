// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/RealSense.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/real_sense__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `red`
// Member `green`
// Member `blue`
// Member `depth`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
my_robot_interfaces__msg__RealSense__init(my_robot_interfaces__msg__RealSense * msg)
{
  if (!msg) {
    return false;
  }
  // red
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->red, 0)) {
    my_robot_interfaces__msg__RealSense__fini(msg);
    return false;
  }
  // green
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->green, 0)) {
    my_robot_interfaces__msg__RealSense__fini(msg);
    return false;
  }
  // blue
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->blue, 0)) {
    my_robot_interfaces__msg__RealSense__fini(msg);
    return false;
  }
  // depth
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->depth, 0)) {
    my_robot_interfaces__msg__RealSense__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__msg__RealSense__fini(my_robot_interfaces__msg__RealSense * msg)
{
  if (!msg) {
    return;
  }
  // red
  rosidl_runtime_c__uint8__Sequence__fini(&msg->red);
  // green
  rosidl_runtime_c__uint8__Sequence__fini(&msg->green);
  // blue
  rosidl_runtime_c__uint8__Sequence__fini(&msg->blue);
  // depth
  rosidl_runtime_c__uint32__Sequence__fini(&msg->depth);
}

bool
my_robot_interfaces__msg__RealSense__are_equal(const my_robot_interfaces__msg__RealSense * lhs, const my_robot_interfaces__msg__RealSense * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // red
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->red), &(rhs->red)))
  {
    return false;
  }
  // green
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->green), &(rhs->green)))
  {
    return false;
  }
  // blue
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->blue), &(rhs->blue)))
  {
    return false;
  }
  // depth
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->depth), &(rhs->depth)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__RealSense__copy(
  const my_robot_interfaces__msg__RealSense * input,
  my_robot_interfaces__msg__RealSense * output)
{
  if (!input || !output) {
    return false;
  }
  // red
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->red), &(output->red)))
  {
    return false;
  }
  // green
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->green), &(output->green)))
  {
    return false;
  }
  // blue
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->blue), &(output->blue)))
  {
    return false;
  }
  // depth
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->depth), &(output->depth)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__msg__RealSense *
my_robot_interfaces__msg__RealSense__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__RealSense * msg = (my_robot_interfaces__msg__RealSense *)allocator.allocate(sizeof(my_robot_interfaces__msg__RealSense), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__RealSense));
  bool success = my_robot_interfaces__msg__RealSense__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__RealSense__destroy(my_robot_interfaces__msg__RealSense * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__RealSense__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__RealSense__Sequence__init(my_robot_interfaces__msg__RealSense__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__RealSense * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__RealSense *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__RealSense), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__RealSense__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__RealSense__fini(&data[i - 1]);
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
my_robot_interfaces__msg__RealSense__Sequence__fini(my_robot_interfaces__msg__RealSense__Sequence * array)
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
      my_robot_interfaces__msg__RealSense__fini(&array->data[i]);
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

my_robot_interfaces__msg__RealSense__Sequence *
my_robot_interfaces__msg__RealSense__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__RealSense__Sequence * array = (my_robot_interfaces__msg__RealSense__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__RealSense__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__RealSense__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__RealSense__Sequence__destroy(my_robot_interfaces__msg__RealSense__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__RealSense__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__RealSense__Sequence__are_equal(const my_robot_interfaces__msg__RealSense__Sequence * lhs, const my_robot_interfaces__msg__RealSense__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__RealSense__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__RealSense__Sequence__copy(
  const my_robot_interfaces__msg__RealSense__Sequence * input,
  my_robot_interfaces__msg__RealSense__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__RealSense);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__RealSense * data =
      (my_robot_interfaces__msg__RealSense *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__RealSense__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__RealSense__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__RealSense__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
