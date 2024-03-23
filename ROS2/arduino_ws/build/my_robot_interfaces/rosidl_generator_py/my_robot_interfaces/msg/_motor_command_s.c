// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_robot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "my_robot_interfaces/msg/detail/motor_command__struct.h"
#include "my_robot_interfaces/msg/detail/motor_command__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_robot_interfaces__msg__motor_command__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("my_robot_interfaces.msg._motor_command.MotorCommand", full_classname_dest, 51) == 0);
  }
  my_robot_interfaces__msg__MotorCommand * ros_message = _ros_message;
  {  // left_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_speed = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // right_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_speed = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rotate_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "rotate_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rotate_speed = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // tilt_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tilt_speed = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // extend_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "extend_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->extend_speed = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vibrate_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "vibrate_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vibrate_speed = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "direction");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->direction = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_robot_interfaces__msg__motor_command__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MotorCommand */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_robot_interfaces.msg._motor_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MotorCommand");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_robot_interfaces__msg__MotorCommand * ros_message = (my_robot_interfaces__msg__MotorCommand *)raw_ros_message;
  {  // left_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->left_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->right_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rotate_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rotate_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rotate_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->tilt_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // extend_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->extend_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "extend_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vibrate_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vibrate_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vibrate_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // direction
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->direction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
