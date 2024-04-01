# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robot_interfaces:msg/FruitDepth.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FruitDepth(type):
    """Metaclass of message 'FruitDepth'."""

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
                'my_robot_interfaces.msg.FruitDepth')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fruit_depth
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fruit_depth
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fruit_depth
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fruit_depth
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fruit_depth

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FruitDepth(metaclass=Metaclass_FruitDepth):
    """Message class 'FruitDepth'."""

    __slots__ = [
        '_detected',
        '_palm_oil_num',
        '_fruit_depth',
        '_pitch_direction',
        '_yaw_direction',
        '_pitch',
        '_yaw',
    ]

    _fields_and_field_types = {
        'detected': 'boolean',
        'palm_oil_num': 'uint8',
        'fruit_depth': 'float',
        'pitch_direction': 'int8',
        'yaw_direction': 'int8',
        'pitch': 'float',
        'yaw': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.detected = kwargs.get('detected', bool())
        self.palm_oil_num = kwargs.get('palm_oil_num', int())
        self.fruit_depth = kwargs.get('fruit_depth', float())
        self.pitch_direction = kwargs.get('pitch_direction', int())
        self.yaw_direction = kwargs.get('yaw_direction', int())
        self.pitch = kwargs.get('pitch', float())
        self.yaw = kwargs.get('yaw', float())

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
        if self.detected != other.detected:
            return False
        if self.palm_oil_num != other.palm_oil_num:
            return False
        if self.fruit_depth != other.fruit_depth:
            return False
        if self.pitch_direction != other.pitch_direction:
            return False
        if self.yaw_direction != other.yaw_direction:
            return False
        if self.pitch != other.pitch:
            return False
        if self.yaw != other.yaw:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def detected(self):
        """Message field 'detected'."""
        return self._detected

    @detected.setter
    def detected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'detected' field must be of type 'bool'"
        self._detected = value

    @builtins.property
    def palm_oil_num(self):
        """Message field 'palm_oil_num'."""
        return self._palm_oil_num

    @palm_oil_num.setter
    def palm_oil_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'palm_oil_num' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'palm_oil_num' field must be an unsigned integer in [0, 255]"
        self._palm_oil_num = value

    @builtins.property
    def fruit_depth(self):
        """Message field 'fruit_depth'."""
        return self._fruit_depth

    @fruit_depth.setter
    def fruit_depth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'fruit_depth' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'fruit_depth' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._fruit_depth = value

    @builtins.property
    def pitch_direction(self):
        """Message field 'pitch_direction'."""
        return self._pitch_direction

    @pitch_direction.setter
    def pitch_direction(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pitch_direction' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'pitch_direction' field must be an integer in [-128, 127]"
        self._pitch_direction = value

    @builtins.property
    def yaw_direction(self):
        """Message field 'yaw_direction'."""
        return self._yaw_direction

    @yaw_direction.setter
    def yaw_direction(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'yaw_direction' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'yaw_direction' field must be an integer in [-128, 127]"
        self._yaw_direction = value

    @builtins.property
    def pitch(self):
        """Message field 'pitch'."""
        return self._pitch

    @pitch.setter
    def pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw = value
