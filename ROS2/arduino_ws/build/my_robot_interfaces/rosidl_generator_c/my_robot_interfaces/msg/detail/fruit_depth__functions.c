// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/FruitDepth.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/fruit_depth__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_robot_interfaces__msg__FruitDepth__init(my_robot_interfaces__msg__FruitDepth * msg)
{
  if (!msg) {
    return false;
  }
  // detected
  // palm_oil_num
  // pitch_direction
  // yaw_direction
  return true;
}

void
my_robot_interfaces__msg__FruitDepth__fini(my_robot_interfaces__msg__FruitDepth * msg)
{
  if (!msg) {
    return;
  }
  // detected
  // palm_oil_num
  // pitch_direction
  // yaw_direction
}

bool
my_robot_interfaces__msg__FruitDepth__are_equal(const my_robot_interfaces__msg__FruitDepth * lhs, const my_robot_interfaces__msg__FruitDepth * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detected
  if (lhs->detected != rhs->detected) {
    return false;
  }
  // palm_oil_num
  if (lhs->palm_oil_num != rhs->palm_oil_num) {
    return false;
  }
  // pitch_direction
  if (lhs->pitch_direction != rhs->pitch_direction) {
    return false;
  }
  // yaw_direction
  if (lhs->yaw_direction != rhs->yaw_direction) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__FruitDepth__copy(
  const my_robot_interfaces__msg__FruitDepth * input,
  my_robot_interfaces__msg__FruitDepth * output)
{
  if (!input || !output) {
    return false;
  }
  // detected
  output->detected = input->detected;
  // palm_oil_num
  output->palm_oil_num = input->palm_oil_num;
  // pitch_direction
  output->pitch_direction = input->pitch_direction;
  // yaw_direction
  output->yaw_direction = input->yaw_direction;
  return true;
}

my_robot_interfaces__msg__FruitDepth *
my_robot_interfaces__msg__FruitDepth__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__FruitDepth * msg = (my_robot_interfaces__msg__FruitDepth *)allocator.allocate(sizeof(my_robot_interfaces__msg__FruitDepth), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__FruitDepth));
  bool success = my_robot_interfaces__msg__FruitDepth__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__FruitDepth__destroy(my_robot_interfaces__msg__FruitDepth * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__FruitDepth__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__FruitDepth__Sequence__init(my_robot_interfaces__msg__FruitDepth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__FruitDepth * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__FruitDepth *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__FruitDepth), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__FruitDepth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__FruitDepth__fini(&data[i - 1]);
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
my_robot_interfaces__msg__FruitDepth__Sequence__fini(my_robot_interfaces__msg__FruitDepth__Sequence * array)
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
      my_robot_interfaces__msg__FruitDepth__fini(&array->data[i]);
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

my_robot_interfaces__msg__FruitDepth__Sequence *
my_robot_interfaces__msg__FruitDepth__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__FruitDepth__Sequence * array = (my_robot_interfaces__msg__FruitDepth__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__FruitDepth__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__FruitDepth__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__FruitDepth__Sequence__destroy(my_robot_interfaces__msg__FruitDepth__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__FruitDepth__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__FruitDepth__Sequence__are_equal(const my_robot_interfaces__msg__FruitDepth__Sequence * lhs, const my_robot_interfaces__msg__FruitDepth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__FruitDepth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__FruitDepth__Sequence__copy(
  const my_robot_interfaces__msg__FruitDepth__Sequence * input,
  my_robot_interfaces__msg__FruitDepth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__FruitDepth);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__FruitDepth * data =
      (my_robot_interfaces__msg__FruitDepth *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__FruitDepth__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__FruitDepth__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__FruitDepth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
