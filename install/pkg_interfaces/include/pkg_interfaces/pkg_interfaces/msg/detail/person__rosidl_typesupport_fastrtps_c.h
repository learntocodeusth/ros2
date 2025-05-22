// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from pkg_interfaces:msg/Person.idl
// generated code does not contain a copyright notice
#ifndef PKG_INTERFACES__MSG__DETAIL__PERSON__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define PKG_INTERFACES__MSG__DETAIL__PERSON__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pkg_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pkg_interfaces/msg/detail/person__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pkg_interfaces
bool cdr_serialize_pkg_interfaces__msg__Person(
  const pkg_interfaces__msg__Person * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pkg_interfaces
bool cdr_deserialize_pkg_interfaces__msg__Person(
  eprosima::fastcdr::Cdr &,
  pkg_interfaces__msg__Person * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pkg_interfaces
size_t get_serialized_size_pkg_interfaces__msg__Person(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pkg_interfaces
size_t max_serialized_size_pkg_interfaces__msg__Person(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pkg_interfaces
bool cdr_serialize_key_pkg_interfaces__msg__Person(
  const pkg_interfaces__msg__Person * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pkg_interfaces
size_t get_serialized_size_key_pkg_interfaces__msg__Person(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pkg_interfaces
size_t max_serialized_size_key_pkg_interfaces__msg__Person(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pkg_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pkg_interfaces, msg, Person)();

#ifdef __cplusplus
}
#endif

#endif  // PKG_INTERFACES__MSG__DETAIL__PERSON__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
