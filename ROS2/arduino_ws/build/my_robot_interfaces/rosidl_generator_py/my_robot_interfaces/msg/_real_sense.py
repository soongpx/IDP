# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robot_interfaces:msg/RealSense.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'red'
# Member 'green'
# Member 'blue'
# Member 'depth'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RealSense(type):
    """Metaclass of message 'RealSense'."""

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
                'my_robot_interfaces.msg.RealSense')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__real_sense
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__real_sense
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__real_sense
            cls._TYPE_SUPPORT = module.type_support_msg__msg__real_sense
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__real_sense

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RealSense(metaclass=Metaclass_RealSense):
    """Message class 'RealSense'."""

    __slots__ = [
        '_red',
        '_green',
        '_blue',
        '_depth',
        '_pitch',
    ]

    _fields_and_field_types = {
        'red': 'sequence<uint8>',
        'green': 'sequence<uint8>',
        'blue': 'sequence<uint8>',
        'depth': 'sequence<uint32>',
        'pitch': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.red = array.array('B', kwargs.get('red', []))
        self.green = array.array('B', kwargs.get('green', []))
        self.blue = array.array('B', kwargs.get('blue', []))
        self.depth = array.array('I', kwargs.get('depth', []))
        self.pitch = kwargs.get('pitch', float())

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
        if self.red != other.red:
            return False
        if self.green != other.green:
            return False
        if self.blue != other.blue:
            return False
        if self.depth != other.depth:
            return False
        if self.pitch != other.pitch:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def red(self):
        """Message field 'red'."""
        return self._red

    @red.setter
    def red(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'red' array.array() must have the type code of 'B'"
            self._red = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'red' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._red = array.array('B', value)

    @builtins.property
    def green(self):
        """Message field 'green'."""
        return self._green

    @green.setter
    def green(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'green' array.array() must have the type code of 'B'"
            self._green = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'green' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._green = array.array('B', value)

    @builtins.property
    def blue(self):
        """Message field 'blue'."""
        return self._blue

    @blue.setter
    def blue(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'blue' array.array() must have the type code of 'B'"
            self._blue = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'blue' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._blue = array.array('B', value)

    @builtins.property
    def depth(self):
        """Message field 'depth'."""
        return self._depth

    @depth.setter
    def depth(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'depth' array.array() must have the type code of 'I'"
            self._depth = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 4294967296 for val in value)), \
                "The 'depth' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._depth = array.array('I', value)

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
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pitch' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pitch = value
