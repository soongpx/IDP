// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__MotorCommand __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__MotorCommand __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCommand_
{
  using Type = MotorCommand_<ContainerAllocator>;

  explicit MotorCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_speed = 0;
      this->right_speed = 0;
      this->rotate_speed = 0;
      this->tilt_speed = 0;
      this->extend_speed = 0;
      this->vibrate_speed = 0;
      this->direction = 0;
    }
  }

  explicit MotorCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_speed = 0;
      this->right_speed = 0;
      this->rotate_speed = 0;
      this->tilt_speed = 0;
      this->extend_speed = 0;
      this->vibrate_speed = 0;
      this->direction = 0;
    }
  }

  // field types and members
  using _left_speed_type =
    uint8_t;
  _left_speed_type left_speed;
  using _right_speed_type =
    uint8_t;
  _right_speed_type right_speed;
  using _rotate_speed_type =
    uint8_t;
  _rotate_speed_type rotate_speed;
  using _tilt_speed_type =
    uint8_t;
  _tilt_speed_type tilt_speed;
  using _extend_speed_type =
    uint8_t;
  _extend_speed_type extend_speed;
  using _vibrate_speed_type =
    uint8_t;
  _vibrate_speed_type vibrate_speed;
  using _direction_type =
    uint8_t;
  _direction_type direction;

  // setters for named parameter idiom
  Type & set__left_speed(
    const uint8_t & _arg)
  {
    this->left_speed = _arg;
    return *this;
  }
  Type & set__right_speed(
    const uint8_t & _arg)
  {
    this->right_speed = _arg;
    return *this;
  }
  Type & set__rotate_speed(
    const uint8_t & _arg)
  {
    this->rotate_speed = _arg;
    return *this;
  }
  Type & set__tilt_speed(
    const uint8_t & _arg)
  {
    this->tilt_speed = _arg;
    return *this;
  }
  Type & set__extend_speed(
    const uint8_t & _arg)
  {
    this->extend_speed = _arg;
    return *this;
  }
  Type & set__vibrate_speed(
    const uint8_t & _arg)
  {
    this->vibrate_speed = _arg;
    return *this;
  }
  Type & set__direction(
    const uint8_t & _arg)
  {
    this->direction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::MotorCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::MotorCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::MotorCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::MotorCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::MotorCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::MotorCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::MotorCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::MotorCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::MotorCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::MotorCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__MotorCommand
    std::shared_ptr<my_robot_interfaces::msg::MotorCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__MotorCommand
    std::shared_ptr<my_robot_interfaces::msg::MotorCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCommand_ & other) const
  {
    if (this->left_speed != other.left_speed) {
      return false;
    }
    if (this->right_speed != other.right_speed) {
      return false;
    }
    if (this->rotate_speed != other.rotate_speed) {
      return false;
    }
    if (this->tilt_speed != other.tilt_speed) {
      return false;
    }
    if (this->extend_speed != other.extend_speed) {
      return false;
    }
    if (this->vibrate_speed != other.vibrate_speed) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCommand_

// alias to use template instance with default allocator
using MotorCommand =
  my_robot_interfaces::msg::MotorCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_
