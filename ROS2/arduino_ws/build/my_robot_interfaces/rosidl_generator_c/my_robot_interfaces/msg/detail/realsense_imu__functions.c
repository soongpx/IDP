// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/RealsenseImu.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/realsense_imu__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_robot_interfaces__msg__RealsenseImu__init(my_robot_interfaces__msg__RealsenseImu * msg)
{
  if (!msg) {
    return false;
  }
  // pitch
  // roll
  // yaw
  return true;
}

void
my_robot_interfaces__msg__RealsenseImu__fini(my_robot_interfaces__msg__RealsenseImu * msg)
{
  if (!msg) {
    return;
  }
  // pitch
  // roll
  // yaw
}

bool
my_robot_interfaces__msg__RealsenseImu__are_equal(const my_robot_interfaces__msg__RealsenseImu * lhs, const my_robot_interfaces__msg__RealsenseImu * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__RealsenseImu__copy(
  const my_robot_interfaces__msg__RealsenseImu * input,
  my_robot_interfaces__msg__RealsenseImu * output)
{
  if (!input || !output) {
    return false;
  }
  // pitch
  output->pitch = input->pitch;
  // roll
  output->roll = input->roll;
  // yaw
  output->yaw = input->yaw;
  return true;
}

my_robot_interfaces__msg__RealsenseImu *
my_robot_interfaces__msg__RealsenseImu__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__RealsenseImu * msg = (my_robot_interfaces__msg__RealsenseImu *)allocator.allocate(sizeof(my_robot_interfaces__msg__RealsenseImu), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__RealsenseImu));
  bool success = my_robot_interfaces__msg__RealsenseImu__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__RealsenseImu__destroy(my_robot_interfaces__msg__RealsenseImu * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__RealsenseImu__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__RealsenseImu__Sequence__init(my_robot_interfaces__msg__RealsenseImu__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__RealsenseImu * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__RealsenseImu *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__RealsenseImu), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__RealsenseImu__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__RealsenseImu__fini(&data[i - 1]);
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
my_robot_interfaces__msg__RealsenseImu__Sequence__fini(my_robot_interfaces__msg__RealsenseImu__Sequence * array)
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
      my_robot_interfaces__msg__RealsenseImu__fini(&array->data[i]);
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

my_robot_interfaces__msg__RealsenseImu__Sequence *
my_robot_interfaces__msg__RealsenseImu__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__RealsenseImu__Sequence * array = (my_robot_interfaces__msg__RealsenseImu__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__RealsenseImu__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__RealsenseImu__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__RealsenseImu__Sequence__destroy(my_robot_interfaces__msg__RealsenseImu__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__RealsenseImu__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__RealsenseImu__Sequence__are_equal(const my_robot_interfaces__msg__RealsenseImu__Sequence * lhs, const my_robot_interfaces__msg__RealsenseImu__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__RealsenseImu__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__RealsenseImu__Sequence__copy(
  const my_robot_interfaces__msg__RealsenseImu__Sequence * input,
  my_robot_interfaces__msg__RealsenseImu__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__RealsenseImu);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__RealsenseImu * data =
      (my_robot_interfaces__msg__RealsenseImu *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__RealsenseImu__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__RealsenseImu__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__RealsenseImu__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
