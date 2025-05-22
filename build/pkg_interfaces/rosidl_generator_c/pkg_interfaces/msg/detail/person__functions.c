// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pkg_interfaces:msg/Person.idl
// generated code does not contain a copyright notice
#include "pkg_interfaces/msg/detail/person__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
pkg_interfaces__msg__Person__init(pkg_interfaces__msg__Person * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    pkg_interfaces__msg__Person__fini(msg);
    return false;
  }
  // age
  // height
  return true;
}

void
pkg_interfaces__msg__Person__fini(pkg_interfaces__msg__Person * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // age
  // height
}

bool
pkg_interfaces__msg__Person__are_equal(const pkg_interfaces__msg__Person * lhs, const pkg_interfaces__msg__Person * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // age
  if (lhs->age != rhs->age) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  return true;
}

bool
pkg_interfaces__msg__Person__copy(
  const pkg_interfaces__msg__Person * input,
  pkg_interfaces__msg__Person * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // age
  output->age = input->age;
  // height
  output->height = input->height;
  return true;
}

pkg_interfaces__msg__Person *
pkg_interfaces__msg__Person__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pkg_interfaces__msg__Person * msg = (pkg_interfaces__msg__Person *)allocator.allocate(sizeof(pkg_interfaces__msg__Person), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pkg_interfaces__msg__Person));
  bool success = pkg_interfaces__msg__Person__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pkg_interfaces__msg__Person__destroy(pkg_interfaces__msg__Person * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pkg_interfaces__msg__Person__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pkg_interfaces__msg__Person__Sequence__init(pkg_interfaces__msg__Person__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pkg_interfaces__msg__Person * data = NULL;

  if (size) {
    data = (pkg_interfaces__msg__Person *)allocator.zero_allocate(size, sizeof(pkg_interfaces__msg__Person), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pkg_interfaces__msg__Person__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pkg_interfaces__msg__Person__fini(&data[i - 1]);
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
pkg_interfaces__msg__Person__Sequence__fini(pkg_interfaces__msg__Person__Sequence * array)
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
      pkg_interfaces__msg__Person__fini(&array->data[i]);
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

pkg_interfaces__msg__Person__Sequence *
pkg_interfaces__msg__Person__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pkg_interfaces__msg__Person__Sequence * array = (pkg_interfaces__msg__Person__Sequence *)allocator.allocate(sizeof(pkg_interfaces__msg__Person__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pkg_interfaces__msg__Person__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pkg_interfaces__msg__Person__Sequence__destroy(pkg_interfaces__msg__Person__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pkg_interfaces__msg__Person__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pkg_interfaces__msg__Person__Sequence__are_equal(const pkg_interfaces__msg__Person__Sequence * lhs, const pkg_interfaces__msg__Person__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pkg_interfaces__msg__Person__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pkg_interfaces__msg__Person__Sequence__copy(
  const pkg_interfaces__msg__Person__Sequence * input,
  pkg_interfaces__msg__Person__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pkg_interfaces__msg__Person);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pkg_interfaces__msg__Person * data =
      (pkg_interfaces__msg__Person *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pkg_interfaces__msg__Person__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pkg_interfaces__msg__Person__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pkg_interfaces__msg__Person__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
