// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:msg/LidarScan.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__msg__LidarScan __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__msg__LidarScan __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LidarScan_
{
  using Type = LidarScan_<ContainerAllocator>;

  explicit LidarScan_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
    }
  }

  explicit LidarScan_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
    }
  }

  // field types and members
  using _detected_type =
    bool;
  _detected_type detected;
  using _angle_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _angle_type angle;
  using _range_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _range_type range;

  // setters for named parameter idiom
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }
  Type & set__angle(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__range(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->range = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::msg::LidarScan_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::msg::LidarScan_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::LidarScan_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::msg::LidarScan_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::LidarScan_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::LidarScan_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::msg::LidarScan_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::msg::LidarScan_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::LidarScan_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::msg::LidarScan_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__msg__LidarScan
    std::shared_ptr<my_robot_interfaces::msg::LidarScan_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__msg__LidarScan
    std::shared_ptr<my_robot_interfaces::msg::LidarScan_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LidarScan_ & other) const
  {
    if (this->detected != other.detected) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    return true;
  }
  bool operator!=(const LidarScan_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LidarScan_

// alias to use template instance with default allocator
using LidarScan =
  my_robot_interfaces::msg::LidarScan_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LIDAR_SCAN__STRUCT_HPP_
