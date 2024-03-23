// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from my_robot_interfaces:msg/FindObstacle.idl
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
#include "my_robot_interfaces/msg/detail/find_obstacle__struct.h"
#include "my_robot_interfaces/msg/detail/find_obstacle__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool my_robot_interfaces__msg__find_obstacle__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("my_robot_interfaces.msg._find_obstacle.FindObstacle", full_classname_dest, 51) == 0);
  }
  my_robot_interfaces__msg__FindObstacle * ros_message = _ros_message;
  {  // nearest_distance1
    PyObject * field = PyObject_GetAttrString(_pymsg, "nearest_distance1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->nearest_distance1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // nearest_angle1
    PyObject * field = PyObject_GetAttrString(_pymsg, "nearest_angle1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->nearest_angle1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // nearest_distance2
    PyObject * field = PyObject_GetAttrString(_pymsg, "nearest_distance2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->nearest_distance2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // nearest_angle2
    PyObject * field = PyObject_GetAttrString(_pymsg, "nearest_angle2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->nearest_angle2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // reach
    PyObject * field = PyObject_GetAttrString(_pymsg, "reach");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->reach = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * my_robot_interfaces__msg__find_obstacle__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FindObstacle */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("my_robot_interfaces.msg._find_obstacle");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FindObstacle");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  my_robot_interfaces__msg__FindObstacle * ros_message = (my_robot_interfaces__msg__FindObstacle *)raw_ros_message;
  {  // nearest_distance1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->nearest_distance1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nearest_distance1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nearest_angle1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->nearest_angle1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nearest_angle1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nearest_distance2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->nearest_distance2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nearest_distance2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nearest_angle2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->nearest_angle2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nearest_angle2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reach
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->reach ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reach", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
