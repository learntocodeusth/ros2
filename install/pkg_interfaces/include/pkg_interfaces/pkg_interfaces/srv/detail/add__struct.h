// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pkg_interfaces:srv/Add.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pkg_interfaces/srv/add.h"


#ifndef PKG_INTERFACES__SRV__DETAIL__ADD__STRUCT_H_
#define PKG_INTERFACES__SRV__DETAIL__ADD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Add in the package pkg_interfaces.
typedef struct pkg_interfaces__srv__Add_Request
{
  int32_t num1;
  int32_t num2;
} pkg_interfaces__srv__Add_Request;

// Struct for a sequence of pkg_interfaces__srv__Add_Request.
typedef struct pkg_interfaces__srv__Add_Request__Sequence
{
  pkg_interfaces__srv__Add_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_interfaces__srv__Add_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Add in the package pkg_interfaces.
typedef struct pkg_interfaces__srv__Add_Response
{
  int32_t sum;
} pkg_interfaces__srv__Add_Response;

// Struct for a sequence of pkg_interfaces__srv__Add_Response.
typedef struct pkg_interfaces__srv__Add_Response__Sequence
{
  pkg_interfaces__srv__Add_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_interfaces__srv__Add_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  pkg_interfaces__srv__Add_Event__request__MAX_SIZE = 1
};
// response
enum
{
  pkg_interfaces__srv__Add_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Add in the package pkg_interfaces.
typedef struct pkg_interfaces__srv__Add_Event
{
  service_msgs__msg__ServiceEventInfo info;
  pkg_interfaces__srv__Add_Request__Sequence request;
  pkg_interfaces__srv__Add_Response__Sequence response;
} pkg_interfaces__srv__Add_Event;

// Struct for a sequence of pkg_interfaces__srv__Add_Event.
typedef struct pkg_interfaces__srv__Add_Event__Sequence
{
  pkg_interfaces__srv__Add_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pkg_interfaces__srv__Add_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PKG_INTERFACES__SRV__DETAIL__ADD__STRUCT_H_
