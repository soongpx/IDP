# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robot_interfaces:msg/FindObstacle.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FindObstacle(type):
    """Metaclass of message 'FindObstacle'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robot_interfaces.msg.FindObstacle')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__find_obstacle
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__find_obstacle
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__find_obstacle
            cls._TYPE_SUPPORT = module.type_support_msg__msg__find_obstacle
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__find_obstacle

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FindObstacle(metaclass=Metaclass_FindObstacle):
    """Message class 'FindObstacle'."""

    __slots__ = [
        '_nearest_distance1',
        '_nearest_angle1',
        '_nearest_distance2',
        '_nearest_angle2',
        '_reach',
    ]

    _fields_and_field_types = {
        'nearest_distance1': 'float',
        'nearest_angle1': 'float',
        'nearest_distance2': 'float',
        'nearest_angle2': 'float',
        'reach': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.nearest_distance1 = kwargs.get('nearest_distance1', float())
        self.nearest_angle1 = kwargs.get('nearest_angle1', float())
        self.nearest_distance2 = kwargs.get('nearest_distance2', float())
        self.nearest_angle2 = kwargs.get('nearest_angle2', float())
        self.reach = kwargs.get('reach', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.nearest_distance1 != other.nearest_distance1:
            return False
        if self.nearest_angle1 != other.nearest_angle1:
            return False
        if self.nearest_distance2 != other.nearest_distance2:
            return False
        if self.nearest_angle2 != other.nearest_angle2:
            return False
        if self.reach != other.reach:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def nearest_distance1(self):
        """Message field 'nearest_distance1'."""
        return self._nearest_distance1

    @nearest_distance1.setter
    def nearest_distance1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'nearest_distance1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'nearest_distance1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._nearest_distance1 = value

    @builtins.property
    def nearest_angle1(self):
        """Message field 'nearest_angle1'."""
        return self._nearest_angle1

    @nearest_angle1.setter
    def nearest_angle1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'nearest_angle1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'nearest_angle1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._nearest_angle1 = value

    @builtins.property
    def nearest_distance2(self):
        """Message field 'nearest_distance2'."""
        return self._nearest_distance2

    @nearest_distance2.setter
    def nearest_distance2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'nearest_distance2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'nearest_distance2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._nearest_distance2 = value

    @builtins.property
    def nearest_angle2(self):
        """Message field 'nearest_angle2'."""
        return self._nearest_angle2

    @nearest_angle2.setter
    def nearest_angle2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'nearest_angle2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'nearest_angle2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._nearest_angle2 = value

    @builtins.property
    def reach(self):
        """Message field 'reach'."""
        return self._reach

    @reach.setter
    def reach(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reach' field must be of type 'bool'"
        self._reach = value
