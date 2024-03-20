# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robot_interfaces:msg/MotorCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MotorCommand(type):
    """Metaclass of message 'MotorCommand'."""

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
                'my_robot_interfaces.msg.MotorCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MotorCommand(metaclass=Metaclass_MotorCommand):
    """Message class 'MotorCommand'."""

    __slots__ = [
        '_left_speed',
        '_right_speed',
        '_rotate_speed',
        '_tilt_speed',
        '_extend_speed',
        '_vibrate_speed',
        '_direction',
    ]

    _fields_and_field_types = {
        'left_speed': 'int32',
        'right_speed': 'int32',
        'rotate_speed': 'int32',
        'tilt_speed': 'int32',
        'extend_speed': 'int32',
        'vibrate_speed': 'int32',
        'direction': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.left_speed = kwargs.get('left_speed', int())
        self.right_speed = kwargs.get('right_speed', int())
        self.rotate_speed = kwargs.get('rotate_speed', int())
        self.tilt_speed = kwargs.get('tilt_speed', int())
        self.extend_speed = kwargs.get('extend_speed', int())
        self.vibrate_speed = kwargs.get('vibrate_speed', int())
        self.direction = kwargs.get('direction', int())

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
        if self.left_speed != other.left_speed:
            return False
        if self.right_speed != other.right_speed:
            return False
        if self.rotate_speed != other.rotate_speed:
            return False
        if self.tilt_speed != other.tilt_speed:
            return False
        if self.extend_speed != other.extend_speed:
            return False
        if self.vibrate_speed != other.vibrate_speed:
            return False
        if self.direction != other.direction:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def left_speed(self):
        """Message field 'left_speed'."""
        return self._left_speed

    @left_speed.setter
    def left_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'left_speed' field must be an integer in [-2147483648, 2147483647]"
        self._left_speed = value

    @builtins.property
    def right_speed(self):
        """Message field 'right_speed'."""
        return self._right_speed

    @right_speed.setter
    def right_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'right_speed' field must be an integer in [-2147483648, 2147483647]"
        self._right_speed = value

    @builtins.property
    def rotate_speed(self):
        """Message field 'rotate_speed'."""
        return self._rotate_speed

    @rotate_speed.setter
    def rotate_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rotate_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rotate_speed' field must be an integer in [-2147483648, 2147483647]"
        self._rotate_speed = value

    @builtins.property
    def tilt_speed(self):
        """Message field 'tilt_speed'."""
        return self._tilt_speed

    @tilt_speed.setter
    def tilt_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tilt_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'tilt_speed' field must be an integer in [-2147483648, 2147483647]"
        self._tilt_speed = value

    @builtins.property
    def extend_speed(self):
        """Message field 'extend_speed'."""
        return self._extend_speed

    @extend_speed.setter
    def extend_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'extend_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'extend_speed' field must be an integer in [-2147483648, 2147483647]"
        self._extend_speed = value

    @builtins.property
    def vibrate_speed(self):
        """Message field 'vibrate_speed'."""
        return self._vibrate_speed

    @vibrate_speed.setter
    def vibrate_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vibrate_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'vibrate_speed' field must be an integer in [-2147483648, 2147483647]"
        self._vibrate_speed = value

    @builtins.property
    def direction(self):
        """Message field 'direction'."""
        return self._direction

    @direction.setter
    def direction(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'direction' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'direction' field must be an integer in [-2147483648, 2147483647]"
        self._direction = value
