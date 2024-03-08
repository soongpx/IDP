// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/FruitDepth.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__FruitDepth __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__FruitDepth __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FruitDepth_
{
  using Type = FruitDepth_<ContainerAllocator>;

  explicit FruitDepth_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->depth = 0.0;
    }
  }

  explicit FruitDepth_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->depth = 0.0;
    }
  }

  // field types and members
  using _detected_type =
    bool;
  _detected_type detected;
  using _depth_type =
    double;
  _depth_type depth;

  // setters for named parameter idiom
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }
  Type & set__depth(
    const double & _arg)
  {
    this->depth = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::FruitDepth_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::FruitDepth_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::FruitDepth_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::FruitDepth_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::FruitDepth_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::FruitDepth_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::FruitDepth_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::FruitDepth_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::FruitDepth_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::FruitDepth_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__FruitDepth
    std::shared_ptr<my_robot_interfaces::msg::FruitDepth_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__FruitDepth
    std::shared_ptr<my_robot_interfaces::msg::FruitDepth_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FruitDepth_ & other) const
  {
    if (this->detected != other.detected) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    return true;
  }
  bool operator!=(const FruitDepth_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FruitDepth_

// alias to use template instance with default allocator
using FruitDepth =
  my_robot_interfaces::msg::FruitDepth_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__FRUIT_DEPTH__STRUCT_HPP_
