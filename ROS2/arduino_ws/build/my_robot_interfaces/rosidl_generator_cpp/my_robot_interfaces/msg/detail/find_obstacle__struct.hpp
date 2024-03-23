// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/FindObstacle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__FindObstacle __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__FindObstacle __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FindObstacle_
{
  using Type = FindObstacle_<ContainerAllocator>;

  explicit FindObstacle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nearest_distance1 = 0.0f;
      this->nearest_angle1 = 0.0f;
      this->nearest_distance2 = 0.0f;
      this->nearest_angle2 = 0.0f;
      this->reach = false;
    }
  }

  explicit FindObstacle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nearest_distance1 = 0.0f;
      this->nearest_angle1 = 0.0f;
      this->nearest_distance2 = 0.0f;
      this->nearest_angle2 = 0.0f;
      this->reach = false;
    }
  }

  // field types and members
  using _nearest_distance1_type =
    float;
  _nearest_distance1_type nearest_distance1;
  using _nearest_angle1_type =
    float;
  _nearest_angle1_type nearest_angle1;
  using _nearest_distance2_type =
    float;
  _nearest_distance2_type nearest_distance2;
  using _nearest_angle2_type =
    float;
  _nearest_angle2_type nearest_angle2;
  using _reach_type =
    bool;
  _reach_type reach;

  // setters for named parameter idiom
  Type & set__nearest_distance1(
    const float & _arg)
  {
    this->nearest_distance1 = _arg;
    return *this;
  }
  Type & set__nearest_angle1(
    const float & _arg)
  {
    this->nearest_angle1 = _arg;
    return *this;
  }
  Type & set__nearest_distance2(
    const float & _arg)
  {
    this->nearest_distance2 = _arg;
    return *this;
  }
  Type & set__nearest_angle2(
    const float & _arg)
  {
    this->nearest_angle2 = _arg;
    return *this;
  }
  Type & set__reach(
    const bool & _arg)
  {
    this->reach = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::FindObstacle_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::FindObstacle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::FindObstacle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::FindObstacle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::FindObstacle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::FindObstacle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::FindObstacle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::FindObstacle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::FindObstacle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::FindObstacle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__FindObstacle
    std::shared_ptr<my_robot_interfaces::msg::FindObstacle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__FindObstacle
    std::shared_ptr<my_robot_interfaces::msg::FindObstacle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FindObstacle_ & other) const
  {
    if (this->nearest_distance1 != other.nearest_distance1) {
      return false;
    }
    if (this->nearest_angle1 != other.nearest_angle1) {
      return false;
    }
    if (this->nearest_distance2 != other.nearest_distance2) {
      return false;
    }
    if (this->nearest_angle2 != other.nearest_angle2) {
      return false;
    }
    if (this->reach != other.reach) {
      return false;
    }
    return true;
  }
  bool operator!=(const FindObstacle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FindObstacle_

// alias to use template instance with default allocator
using FindObstacle =
  my_robot_interfaces::msg::FindObstacle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__STRUCT_HPP_
