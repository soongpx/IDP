// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/motor_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_robot_interfaces__msg__MotorCommand__init(my_robot_interfaces__msg__MotorCommand * msg)
{
  if (!msg) {
    return false;
  }
  // left_speed
  // right_speed
  // rotate_speed
  // tilt_speed
  // extend_speed
  // vibrate_speed
  // direction
  return true;
}

void
my_robot_interfaces__msg__MotorCommand__fini(my_robot_interfaces__msg__MotorCommand * msg)
{
  if (!msg) {
    return;
  }
  // left_speed
  // right_speed
  // rotate_speed
  // tilt_speed
  // extend_speed
  // vibrate_speed
  // direction
}

bool
my_robot_interfaces__msg__MotorCommand__are_equal(const my_robot_interfaces__msg__MotorCommand * lhs, const my_robot_interfaces__msg__MotorCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left_speed
  if (lhs->left_speed != rhs->left_speed) {
    return false;
  }
  // right_speed
  if (lhs->right_speed != rhs->right_speed) {
    return false;
  }
  // rotate_speed
  if (lhs->rotate_speed != rhs->rotate_speed) {
    return false;
  }
  // tilt_speed
  if (lhs->tilt_speed != rhs->tilt_speed) {
    return false;
  }
  // extend_speed
  if (lhs->extend_speed != rhs->extend_speed) {
    return false;
  }
  // vibrate_speed
  if (lhs->vibrate_speed != rhs->vibrate_speed) {
    return false;
  }
  // direction
  if (lhs->direction != rhs->direction) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__MotorCommand__copy(
  const my_robot_interfaces__msg__MotorCommand * input,
  my_robot_interfaces__msg__MotorCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // left_speed
  output->left_speed = input->left_speed;
  // right_speed
  output->right_speed = input->right_speed;
  // rotate_speed
  output->rotate_speed = input->rotate_speed;
  // tilt_speed
  output->tilt_speed = input->tilt_speed;
  // extend_speed
  output->extend_speed = input->extend_speed;
  // vibrate_speed
  output->vibrate_speed = input->vibrate_speed;
  // direction
  output->direction = input->direction;
  return true;
}

my_robot_interfaces__msg__MotorCommand *
my_robot_interfaces__msg__MotorCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__MotorCommand * msg = (my_robot_interfaces__msg__MotorCommand *)allocator.allocate(sizeof(my_robot_interfaces__msg__MotorCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__MotorCommand));
  bool success = my_robot_interfaces__msg__MotorCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__MotorCommand__destroy(my_robot_interfaces__msg__MotorCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__MotorCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__MotorCommand__Sequence__init(my_robot_interfaces__msg__MotorCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__MotorCommand * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__MotorCommand *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__MotorCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__MotorCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__MotorCommand__fini(&data[i - 1]);
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
my_robot_interfaces__msg__MotorCommand__Sequence__fini(my_robot_interfaces__msg__MotorCommand__Sequence * array)
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
      my_robot_interfaces__msg__MotorCommand__fini(&array->data[i]);
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

my_robot_interfaces__msg__MotorCommand__Sequence *
my_robot_interfaces__msg__MotorCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__MotorCommand__Sequence * array = (my_robot_interfaces__msg__MotorCommand__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__MotorCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__MotorCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__MotorCommand__Sequence__destroy(my_robot_interfaces__msg__MotorCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__MotorCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__MotorCommand__Sequence__are_equal(const my_robot_interfaces__msg__MotorCommand__Sequence * lhs, const my_robot_interfaces__msg__MotorCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__MotorCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__MotorCommand__Sequence__copy(
  const my_robot_interfaces__msg__MotorCommand__Sequence * input,
  my_robot_interfaces__msg__MotorCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__MotorCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__MotorCommand * data =
      (my_robot_interfaces__msg__MotorCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__MotorCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__MotorCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__MotorCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
