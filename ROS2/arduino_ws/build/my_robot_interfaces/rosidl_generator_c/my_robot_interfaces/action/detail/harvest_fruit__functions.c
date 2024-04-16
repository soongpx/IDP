// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:action/HarvestFruit.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/action/detail/harvest_fruit__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_robot_interfaces__action__HarvestFruit_Goal__init(my_robot_interfaces__action__HarvestFruit_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // detected
  // fruit_depth
  // target_pitch
  // target_yaw
  return true;
}

void
my_robot_interfaces__action__HarvestFruit_Goal__fini(my_robot_interfaces__action__HarvestFruit_Goal * msg)
{
  if (!msg) {
    return;
  }
  // detected
  // fruit_depth
  // target_pitch
  // target_yaw
}

bool
my_robot_interfaces__action__HarvestFruit_Goal__are_equal(const my_robot_interfaces__action__HarvestFruit_Goal * lhs, const my_robot_interfaces__action__HarvestFruit_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detected
  if (lhs->detected != rhs->detected) {
    return false;
  }
  // fruit_depth
  if (lhs->fruit_depth != rhs->fruit_depth) {
    return false;
  }
  // target_pitch
  if (lhs->target_pitch != rhs->target_pitch) {
    return false;
  }
  // target_yaw
  if (lhs->target_yaw != rhs->target_yaw) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_Goal__copy(
  const my_robot_interfaces__action__HarvestFruit_Goal * input,
  my_robot_interfaces__action__HarvestFruit_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // detected
  output->detected = input->detected;
  // fruit_depth
  output->fruit_depth = input->fruit_depth;
  // target_pitch
  output->target_pitch = input->target_pitch;
  // target_yaw
  output->target_yaw = input->target_yaw;
  return true;
}

my_robot_interfaces__action__HarvestFruit_Goal *
my_robot_interfaces__action__HarvestFruit_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Goal * msg = (my_robot_interfaces__action__HarvestFruit_Goal *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__action__HarvestFruit_Goal));
  bool success = my_robot_interfaces__action__HarvestFruit_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__action__HarvestFruit_Goal__destroy(my_robot_interfaces__action__HarvestFruit_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__action__HarvestFruit_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__action__HarvestFruit_Goal__Sequence__init(my_robot_interfaces__action__HarvestFruit_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Goal * data = NULL;

  if (size) {
    data = (my_robot_interfaces__action__HarvestFruit_Goal *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__action__HarvestFruit_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__action__HarvestFruit_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__action__HarvestFruit_Goal__fini(&data[i - 1]);
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
my_robot_interfaces__action__HarvestFruit_Goal__Sequence__fini(my_robot_interfaces__action__HarvestFruit_Goal__Sequence * array)
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
      my_robot_interfaces__action__HarvestFruit_Goal__fini(&array->data[i]);
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

my_robot_interfaces__action__HarvestFruit_Goal__Sequence *
my_robot_interfaces__action__HarvestFruit_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Goal__Sequence * array = (my_robot_interfaces__action__HarvestFruit_Goal__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__action__HarvestFruit_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__action__HarvestFruit_Goal__Sequence__destroy(my_robot_interfaces__action__HarvestFruit_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__action__HarvestFruit_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__action__HarvestFruit_Goal__Sequence__are_equal(const my_robot_interfaces__action__HarvestFruit_Goal__Sequence * lhs, const my_robot_interfaces__action__HarvestFruit_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_Goal__Sequence__copy(
  const my_robot_interfaces__action__HarvestFruit_Goal__Sequence * input,
  my_robot_interfaces__action__HarvestFruit_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__action__HarvestFruit_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__action__HarvestFruit_Goal * data =
      (my_robot_interfaces__action__HarvestFruit_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__action__HarvestFruit_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__action__HarvestFruit_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
my_robot_interfaces__action__HarvestFruit_Result__init(my_robot_interfaces__action__HarvestFruit_Result * msg)
{
  if (!msg) {
    return false;
  }
  // end
  return true;
}

void
my_robot_interfaces__action__HarvestFruit_Result__fini(my_robot_interfaces__action__HarvestFruit_Result * msg)
{
  if (!msg) {
    return;
  }
  // end
}

bool
my_robot_interfaces__action__HarvestFruit_Result__are_equal(const my_robot_interfaces__action__HarvestFruit_Result * lhs, const my_robot_interfaces__action__HarvestFruit_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // end
  if (lhs->end != rhs->end) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_Result__copy(
  const my_robot_interfaces__action__HarvestFruit_Result * input,
  my_robot_interfaces__action__HarvestFruit_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // end
  output->end = input->end;
  return true;
}

my_robot_interfaces__action__HarvestFruit_Result *
my_robot_interfaces__action__HarvestFruit_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Result * msg = (my_robot_interfaces__action__HarvestFruit_Result *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__action__HarvestFruit_Result));
  bool success = my_robot_interfaces__action__HarvestFruit_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__action__HarvestFruit_Result__destroy(my_robot_interfaces__action__HarvestFruit_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__action__HarvestFruit_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__action__HarvestFruit_Result__Sequence__init(my_robot_interfaces__action__HarvestFruit_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Result * data = NULL;

  if (size) {
    data = (my_robot_interfaces__action__HarvestFruit_Result *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__action__HarvestFruit_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__action__HarvestFruit_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__action__HarvestFruit_Result__fini(&data[i - 1]);
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
my_robot_interfaces__action__HarvestFruit_Result__Sequence__fini(my_robot_interfaces__action__HarvestFruit_Result__Sequence * array)
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
      my_robot_interfaces__action__HarvestFruit_Result__fini(&array->data[i]);
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

my_robot_interfaces__action__HarvestFruit_Result__Sequence *
my_robot_interfaces__action__HarvestFruit_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Result__Sequence * array = (my_robot_interfaces__action__HarvestFruit_Result__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__action__HarvestFruit_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__action__HarvestFruit_Result__Sequence__destroy(my_robot_interfaces__action__HarvestFruit_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__action__HarvestFruit_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__action__HarvestFruit_Result__Sequence__are_equal(const my_robot_interfaces__action__HarvestFruit_Result__Sequence * lhs, const my_robot_interfaces__action__HarvestFruit_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_Result__Sequence__copy(
  const my_robot_interfaces__action__HarvestFruit_Result__Sequence * input,
  my_robot_interfaces__action__HarvestFruit_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__action__HarvestFruit_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__action__HarvestFruit_Result * data =
      (my_robot_interfaces__action__HarvestFruit_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__action__HarvestFruit_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__action__HarvestFruit_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
my_robot_interfaces__action__HarvestFruit_Feedback__init(my_robot_interfaces__action__HarvestFruit_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // rotate_speed
  // tilt_speed
  // extend_speed
  // vibrate_speed
  // direction
  return true;
}

void
my_robot_interfaces__action__HarvestFruit_Feedback__fini(my_robot_interfaces__action__HarvestFruit_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // rotate_speed
  // tilt_speed
  // extend_speed
  // vibrate_speed
  // direction
}

bool
my_robot_interfaces__action__HarvestFruit_Feedback__are_equal(const my_robot_interfaces__action__HarvestFruit_Feedback * lhs, const my_robot_interfaces__action__HarvestFruit_Feedback * rhs)
{
  if (!lhs || !rhs) {
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
my_robot_interfaces__action__HarvestFruit_Feedback__copy(
  const my_robot_interfaces__action__HarvestFruit_Feedback * input,
  my_robot_interfaces__action__HarvestFruit_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
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

my_robot_interfaces__action__HarvestFruit_Feedback *
my_robot_interfaces__action__HarvestFruit_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Feedback * msg = (my_robot_interfaces__action__HarvestFruit_Feedback *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__action__HarvestFruit_Feedback));
  bool success = my_robot_interfaces__action__HarvestFruit_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__action__HarvestFruit_Feedback__destroy(my_robot_interfaces__action__HarvestFruit_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__action__HarvestFruit_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__action__HarvestFruit_Feedback__Sequence__init(my_robot_interfaces__action__HarvestFruit_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Feedback * data = NULL;

  if (size) {
    data = (my_robot_interfaces__action__HarvestFruit_Feedback *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__action__HarvestFruit_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__action__HarvestFruit_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__action__HarvestFruit_Feedback__fini(&data[i - 1]);
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
my_robot_interfaces__action__HarvestFruit_Feedback__Sequence__fini(my_robot_interfaces__action__HarvestFruit_Feedback__Sequence * array)
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
      my_robot_interfaces__action__HarvestFruit_Feedback__fini(&array->data[i]);
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

my_robot_interfaces__action__HarvestFruit_Feedback__Sequence *
my_robot_interfaces__action__HarvestFruit_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_Feedback__Sequence * array = (my_robot_interfaces__action__HarvestFruit_Feedback__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__action__HarvestFruit_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__action__HarvestFruit_Feedback__Sequence__destroy(my_robot_interfaces__action__HarvestFruit_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__action__HarvestFruit_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__action__HarvestFruit_Feedback__Sequence__are_equal(const my_robot_interfaces__action__HarvestFruit_Feedback__Sequence * lhs, const my_robot_interfaces__action__HarvestFruit_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_Feedback__Sequence__copy(
  const my_robot_interfaces__action__HarvestFruit_Feedback__Sequence * input,
  my_robot_interfaces__action__HarvestFruit_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__action__HarvestFruit_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__action__HarvestFruit_Feedback * data =
      (my_robot_interfaces__action__HarvestFruit_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__action__HarvestFruit_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__action__HarvestFruit_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "my_robot_interfaces/action/detail/harvest_fruit__functions.h"

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__init(my_robot_interfaces__action__HarvestFruit_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    my_robot_interfaces__action__HarvestFruit_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!my_robot_interfaces__action__HarvestFruit_Goal__init(&msg->goal)) {
    my_robot_interfaces__action__HarvestFruit_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__fini(my_robot_interfaces__action__HarvestFruit_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  my_robot_interfaces__action__HarvestFruit_Goal__fini(&msg->goal);
}

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__are_equal(const my_robot_interfaces__action__HarvestFruit_SendGoal_Request * lhs, const my_robot_interfaces__action__HarvestFruit_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!my_robot_interfaces__action__HarvestFruit_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__copy(
  const my_robot_interfaces__action__HarvestFruit_SendGoal_Request * input,
  my_robot_interfaces__action__HarvestFruit_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!my_robot_interfaces__action__HarvestFruit_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__action__HarvestFruit_SendGoal_Request *
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_SendGoal_Request * msg = (my_robot_interfaces__action__HarvestFruit_SendGoal_Request *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Request));
  bool success = my_robot_interfaces__action__HarvestFruit_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__destroy(my_robot_interfaces__action__HarvestFruit_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__action__HarvestFruit_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence__init(my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_SendGoal_Request * data = NULL;

  if (size) {
    data = (my_robot_interfaces__action__HarvestFruit_SendGoal_Request *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__action__HarvestFruit_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__action__HarvestFruit_SendGoal_Request__fini(&data[i - 1]);
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
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence__fini(my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence * array)
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
      my_robot_interfaces__action__HarvestFruit_SendGoal_Request__fini(&array->data[i]);
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

my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence *
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence * array = (my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence__destroy(my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence__are_equal(const my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence * lhs, const my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence__copy(
  const my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence * input,
  my_robot_interfaces__action__HarvestFruit_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__action__HarvestFruit_SendGoal_Request * data =
      (my_robot_interfaces__action__HarvestFruit_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__action__HarvestFruit_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__action__HarvestFruit_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__init(my_robot_interfaces__action__HarvestFruit_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    my_robot_interfaces__action__HarvestFruit_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__fini(my_robot_interfaces__action__HarvestFruit_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__are_equal(const my_robot_interfaces__action__HarvestFruit_SendGoal_Response * lhs, const my_robot_interfaces__action__HarvestFruit_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__copy(
  const my_robot_interfaces__action__HarvestFruit_SendGoal_Response * input,
  my_robot_interfaces__action__HarvestFruit_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__action__HarvestFruit_SendGoal_Response *
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_SendGoal_Response * msg = (my_robot_interfaces__action__HarvestFruit_SendGoal_Response *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Response));
  bool success = my_robot_interfaces__action__HarvestFruit_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__destroy(my_robot_interfaces__action__HarvestFruit_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__action__HarvestFruit_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence__init(my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_SendGoal_Response * data = NULL;

  if (size) {
    data = (my_robot_interfaces__action__HarvestFruit_SendGoal_Response *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__action__HarvestFruit_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__action__HarvestFruit_SendGoal_Response__fini(&data[i - 1]);
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
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence__fini(my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence * array)
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
      my_robot_interfaces__action__HarvestFruit_SendGoal_Response__fini(&array->data[i]);
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

my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence *
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence * array = (my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence__destroy(my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence__are_equal(const my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence * lhs, const my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence__copy(
  const my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence * input,
  my_robot_interfaces__action__HarvestFruit_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__action__HarvestFruit_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__action__HarvestFruit_SendGoal_Response * data =
      (my_robot_interfaces__action__HarvestFruit_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__action__HarvestFruit_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__action__HarvestFruit_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Request__init(my_robot_interfaces__action__HarvestFruit_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    my_robot_interfaces__action__HarvestFruit_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__action__HarvestFruit_GetResult_Request__fini(my_robot_interfaces__action__HarvestFruit_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Request__are_equal(const my_robot_interfaces__action__HarvestFruit_GetResult_Request * lhs, const my_robot_interfaces__action__HarvestFruit_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Request__copy(
  const my_robot_interfaces__action__HarvestFruit_GetResult_Request * input,
  my_robot_interfaces__action__HarvestFruit_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__action__HarvestFruit_GetResult_Request *
my_robot_interfaces__action__HarvestFruit_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_GetResult_Request * msg = (my_robot_interfaces__action__HarvestFruit_GetResult_Request *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Request));
  bool success = my_robot_interfaces__action__HarvestFruit_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__action__HarvestFruit_GetResult_Request__destroy(my_robot_interfaces__action__HarvestFruit_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__action__HarvestFruit_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence__init(my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_GetResult_Request * data = NULL;

  if (size) {
    data = (my_robot_interfaces__action__HarvestFruit_GetResult_Request *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__action__HarvestFruit_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__action__HarvestFruit_GetResult_Request__fini(&data[i - 1]);
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
my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence__fini(my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence * array)
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
      my_robot_interfaces__action__HarvestFruit_GetResult_Request__fini(&array->data[i]);
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

my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence *
my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence * array = (my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence__destroy(my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence__are_equal(const my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence * lhs, const my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence__copy(
  const my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence * input,
  my_robot_interfaces__action__HarvestFruit_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__action__HarvestFruit_GetResult_Request * data =
      (my_robot_interfaces__action__HarvestFruit_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__action__HarvestFruit_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__action__HarvestFruit_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "my_robot_interfaces/action/detail/harvest_fruit__functions.h"

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Response__init(my_robot_interfaces__action__HarvestFruit_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!my_robot_interfaces__action__HarvestFruit_Result__init(&msg->result)) {
    my_robot_interfaces__action__HarvestFruit_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__action__HarvestFruit_GetResult_Response__fini(my_robot_interfaces__action__HarvestFruit_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  my_robot_interfaces__action__HarvestFruit_Result__fini(&msg->result);
}

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Response__are_equal(const my_robot_interfaces__action__HarvestFruit_GetResult_Response * lhs, const my_robot_interfaces__action__HarvestFruit_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!my_robot_interfaces__action__HarvestFruit_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Response__copy(
  const my_robot_interfaces__action__HarvestFruit_GetResult_Response * input,
  my_robot_interfaces__action__HarvestFruit_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!my_robot_interfaces__action__HarvestFruit_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__action__HarvestFruit_GetResult_Response *
my_robot_interfaces__action__HarvestFruit_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_GetResult_Response * msg = (my_robot_interfaces__action__HarvestFruit_GetResult_Response *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Response));
  bool success = my_robot_interfaces__action__HarvestFruit_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__action__HarvestFruit_GetResult_Response__destroy(my_robot_interfaces__action__HarvestFruit_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__action__HarvestFruit_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence__init(my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_GetResult_Response * data = NULL;

  if (size) {
    data = (my_robot_interfaces__action__HarvestFruit_GetResult_Response *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__action__HarvestFruit_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__action__HarvestFruit_GetResult_Response__fini(&data[i - 1]);
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
my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence__fini(my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence * array)
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
      my_robot_interfaces__action__HarvestFruit_GetResult_Response__fini(&array->data[i]);
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

my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence *
my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence * array = (my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence__destroy(my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence__are_equal(const my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence * lhs, const my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence__copy(
  const my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence * input,
  my_robot_interfaces__action__HarvestFruit_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__action__HarvestFruit_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__action__HarvestFruit_GetResult_Response * data =
      (my_robot_interfaces__action__HarvestFruit_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__action__HarvestFruit_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__action__HarvestFruit_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "my_robot_interfaces/action/detail/harvest_fruit__functions.h"

bool
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__init(my_robot_interfaces__action__HarvestFruit_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    my_robot_interfaces__action__HarvestFruit_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!my_robot_interfaces__action__HarvestFruit_Feedback__init(&msg->feedback)) {
    my_robot_interfaces__action__HarvestFruit_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__fini(my_robot_interfaces__action__HarvestFruit_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  my_robot_interfaces__action__HarvestFruit_Feedback__fini(&msg->feedback);
}

bool
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__are_equal(const my_robot_interfaces__action__HarvestFruit_FeedbackMessage * lhs, const my_robot_interfaces__action__HarvestFruit_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!my_robot_interfaces__action__HarvestFruit_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__copy(
  const my_robot_interfaces__action__HarvestFruit_FeedbackMessage * input,
  my_robot_interfaces__action__HarvestFruit_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!my_robot_interfaces__action__HarvestFruit_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__action__HarvestFruit_FeedbackMessage *
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_FeedbackMessage * msg = (my_robot_interfaces__action__HarvestFruit_FeedbackMessage *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__action__HarvestFruit_FeedbackMessage));
  bool success = my_robot_interfaces__action__HarvestFruit_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__destroy(my_robot_interfaces__action__HarvestFruit_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__action__HarvestFruit_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence__init(my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_FeedbackMessage * data = NULL;

  if (size) {
    data = (my_robot_interfaces__action__HarvestFruit_FeedbackMessage *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__action__HarvestFruit_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__action__HarvestFruit_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__action__HarvestFruit_FeedbackMessage__fini(&data[i - 1]);
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
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence__fini(my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence * array)
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
      my_robot_interfaces__action__HarvestFruit_FeedbackMessage__fini(&array->data[i]);
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

my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence *
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence * array = (my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence__destroy(my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence__are_equal(const my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence * lhs, const my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence__copy(
  const my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence * input,
  my_robot_interfaces__action__HarvestFruit_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__action__HarvestFruit_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__action__HarvestFruit_FeedbackMessage * data =
      (my_robot_interfaces__action__HarvestFruit_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__action__HarvestFruit_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__action__HarvestFruit_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__action__HarvestFruit_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}