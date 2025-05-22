// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from pkg_interfaces:msg/Person.idl
// generated code does not contain a copyright notice

#include "pkg_interfaces/msg/detail/person__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_pkg_interfaces
const rosidl_type_hash_t *
pkg_interfaces__msg__Person__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc7, 0x59, 0x3b, 0x64, 0x66, 0x59, 0xcd, 0xdc,
      0xc4, 0xd6, 0x11, 0x76, 0x65, 0x18, 0xd6, 0x67,
      0x8b, 0x34, 0x83, 0x5b, 0xa5, 0xd2, 0x81, 0x58,
      0xfd, 0x2c, 0xbc, 0xc9, 0x57, 0x3b, 0x94, 0x36,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char pkg_interfaces__msg__Person__TYPE_NAME[] = "pkg_interfaces/msg/Person";

// Define type names, field names, and default values
static char pkg_interfaces__msg__Person__FIELD_NAME__name[] = "name";
static char pkg_interfaces__msg__Person__FIELD_NAME__age[] = "age";
static char pkg_interfaces__msg__Person__FIELD_NAME__height[] = "height";

static rosidl_runtime_c__type_description__Field pkg_interfaces__msg__Person__FIELDS[] = {
  {
    {pkg_interfaces__msg__Person__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pkg_interfaces__msg__Person__FIELD_NAME__age, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pkg_interfaces__msg__Person__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pkg_interfaces__msg__Person__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pkg_interfaces__msg__Person__TYPE_NAME, 25, 25},
      {pkg_interfaces__msg__Person__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string   name\n"
  "int32    age\n"
  "float64  height";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
pkg_interfaces__msg__Person__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pkg_interfaces__msg__Person__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 42, 42},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pkg_interfaces__msg__Person__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pkg_interfaces__msg__Person__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
