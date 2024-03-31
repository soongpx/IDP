// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_robot_interfaces:msg/FruitDepth.idl
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
#include "my_robot_interfaces/msg/detail/fruit_depth__struct.h"
#include "my_robot_interfaces/msg/detail/fruit_depth__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_robot_interfaces__msg__fruit_depth__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
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
    assert(strncmp("my_robot_interfaces.msg._fruit_depth.FruitDepth", full_classname_dest, 47) == 0);
  }
  my_robot_interfaces__msg__FruitDepth * ros_message = _ros_message;
  {  // detected
    PyObject * field = PyObject_GetAttrString(_pymsg, "detected");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->detected = (Py_True == field);
    Py_DECREF(field);
  }
  {  // palm_oil_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "palm_oil_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->palm_oil_num = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // fruit_depth
    PyObject * field = PyObject_GetAttrString(_pymsg, "fruit_depth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fruit_depth = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch_direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_direction");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pitch_direction = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // yaw_direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw_direction");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->yaw_direction = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_robot_interfaces__msg__fruit_depth__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FruitDepth */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_robot_interfaces.msg._fruit_depth");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FruitDepth");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_robot_interfaces__msg__FruitDepth * ros_message = (my_robot_interfaces__msg__FruitDepth *)raw_ros_message;
  {  // detected
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->detected ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "detected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // palm_oil_num
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->palm_oil_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "palm_oil_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fruit_depth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fruit_depth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fruit_depth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_direction
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pitch_direction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw_direction
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->yaw_direction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw_direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
