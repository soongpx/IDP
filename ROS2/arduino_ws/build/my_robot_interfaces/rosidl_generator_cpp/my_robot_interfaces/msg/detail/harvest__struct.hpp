// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/Harvest.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__Harvest __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__Harvest __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Harvest_
{
  using Type = Harvest_<ContainerAllocator>;

  explicit Harvest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->harvest_end = false;
    }
  }

  explicit Harvest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->harvest_end = false;
    }
  }

  // field types and members
  using _harvest_end_type =
    bool;
  _harvest_end_type harvest_end;

  // setters for named parameter idiom
  Type & set__harvest_end(
    const bool & _arg)
  {
    this->harvest_end = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::Harvest_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::Harvest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::Harvest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::Harvest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::Harvest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::Harvest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::Harvest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::Harvest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::Harvest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::Harvest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__Harvest
    std::shared_ptr<my_robot_interfaces::msg::Harvest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__Harvest
    std::shared_ptr<my_robot_interfaces::msg::Harvest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Harvest_ & other) const
  {
    if (this->harvest_end != other.harvest_end) {
      return false;
    }
    return true;
  }
  bool operator!=(const Harvest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Harvest_

// alias to use template instance with default allocator
using Harvest =
  my_robot_interfaces::msg::Harvest_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__HARVEST__STRUCT_HPP_
