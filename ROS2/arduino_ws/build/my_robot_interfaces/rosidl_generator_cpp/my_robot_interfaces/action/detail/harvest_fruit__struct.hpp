// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:action/HarvestFruit.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__HARVEST_FRUIT__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__HARVEST_FRUIT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_Goal __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_Goal __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HarvestFruit_Goal_
{
  using Type = HarvestFruit_Goal_<ContainerAllocator>;

  explicit HarvestFruit_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->fruit_depth = 0.0f;
      this->target_pitch = 0.0f;
      this->target_yaw = 0.0f;
    }
  }

  explicit HarvestFruit_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->fruit_depth = 0.0f;
      this->target_pitch = 0.0f;
      this->target_yaw = 0.0f;
    }
  }

  // field types and members
  using _detected_type =
    bool;
  _detected_type detected;
  using _fruit_depth_type =
    float;
  _fruit_depth_type fruit_depth;
  using _target_pitch_type =
    float;
  _target_pitch_type target_pitch;
  using _target_yaw_type =
    float;
  _target_yaw_type target_yaw;

  // setters for named parameter idiom
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }
  Type & set__fruit_depth(
    const float & _arg)
  {
    this->fruit_depth = _arg;
    return *this;
  }
  Type & set__target_pitch(
    const float & _arg)
  {
    this->target_pitch = _arg;
    return *this;
  }
  Type & set__target_yaw(
    const float & _arg)
  {
    this->target_yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_Goal
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_Goal
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HarvestFruit_Goal_ & other) const
  {
    if (this->detected != other.detected) {
      return false;
    }
    if (this->fruit_depth != other.fruit_depth) {
      return false;
    }
    if (this->target_pitch != other.target_pitch) {
      return false;
    }
    if (this->target_yaw != other.target_yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const HarvestFruit_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HarvestFruit_Goal_

// alias to use template instance with default allocator
using HarvestFruit_Goal =
  my_robot_interfaces::action::HarvestFruit_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_robot_interfaces


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_Result __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_Result __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HarvestFruit_Result_
{
  using Type = HarvestFruit_Result_<ContainerAllocator>;

  explicit HarvestFruit_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->end = false;
    }
  }

  explicit HarvestFruit_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->end = false;
    }
  }

  // field types and members
  using _end_type =
    bool;
  _end_type end;

  // setters for named parameter idiom
  Type & set__end(
    const bool & _arg)
  {
    this->end = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_Result
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_Result
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HarvestFruit_Result_ & other) const
  {
    if (this->end != other.end) {
      return false;
    }
    return true;
  }
  bool operator!=(const HarvestFruit_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HarvestFruit_Result_

// alias to use template instance with default allocator
using HarvestFruit_Result =
  my_robot_interfaces::action::HarvestFruit_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_robot_interfaces


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_Feedback __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HarvestFruit_Feedback_
{
  using Type = HarvestFruit_Feedback_<ContainerAllocator>;

  explicit HarvestFruit_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rotate_speed = 0;
      this->tilt_speed = 0;
      this->extend_speed = 0;
      this->vibrate_speed = 0;
      this->direction = 0;
    }
  }

  explicit HarvestFruit_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rotate_speed = 0;
      this->tilt_speed = 0;
      this->extend_speed = 0;
      this->vibrate_speed = 0;
      this->direction = 0;
    }
  }

  // field types and members
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
    my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_Feedback
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_Feedback
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HarvestFruit_Feedback_ & other) const
  {
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
  bool operator!=(const HarvestFruit_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HarvestFruit_Feedback_

// alias to use template instance with default allocator
using HarvestFruit_Feedback =
  my_robot_interfaces::action::HarvestFruit_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_robot_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "my_robot_interfaces/action/detail/harvest_fruit__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_SendGoal_Request __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HarvestFruit_SendGoal_Request_
{
  using Type = HarvestFruit_SendGoal_Request_<ContainerAllocator>;

  explicit HarvestFruit_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit HarvestFruit_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const my_robot_interfaces::action::HarvestFruit_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_SendGoal_Request
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_SendGoal_Request
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HarvestFruit_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const HarvestFruit_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HarvestFruit_SendGoal_Request_

// alias to use template instance with default allocator
using HarvestFruit_SendGoal_Request =
  my_robot_interfaces::action::HarvestFruit_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_robot_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_SendGoal_Response __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HarvestFruit_SendGoal_Response_
{
  using Type = HarvestFruit_SendGoal_Response_<ContainerAllocator>;

  explicit HarvestFruit_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit HarvestFruit_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_SendGoal_Response
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_SendGoal_Response
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HarvestFruit_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const HarvestFruit_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HarvestFruit_SendGoal_Response_

// alias to use template instance with default allocator
using HarvestFruit_SendGoal_Response =
  my_robot_interfaces::action::HarvestFruit_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_robot_interfaces

namespace my_robot_interfaces
{

namespace action
{

struct HarvestFruit_SendGoal
{
  using Request = my_robot_interfaces::action::HarvestFruit_SendGoal_Request;
  using Response = my_robot_interfaces::action::HarvestFruit_SendGoal_Response;
};

}  // namespace action

}  // namespace my_robot_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_GetResult_Request __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HarvestFruit_GetResult_Request_
{
  using Type = HarvestFruit_GetResult_Request_<ContainerAllocator>;

  explicit HarvestFruit_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit HarvestFruit_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_GetResult_Request
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_GetResult_Request
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HarvestFruit_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const HarvestFruit_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HarvestFruit_GetResult_Request_

// alias to use template instance with default allocator
using HarvestFruit_GetResult_Request =
  my_robot_interfaces::action::HarvestFruit_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_robot_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "my_robot_interfaces/action/detail/harvest_fruit__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_GetResult_Response __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HarvestFruit_GetResult_Response_
{
  using Type = HarvestFruit_GetResult_Response_<ContainerAllocator>;

  explicit HarvestFruit_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit HarvestFruit_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const my_robot_interfaces::action::HarvestFruit_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_GetResult_Response
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_GetResult_Response
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HarvestFruit_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const HarvestFruit_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HarvestFruit_GetResult_Response_

// alias to use template instance with default allocator
using HarvestFruit_GetResult_Response =
  my_robot_interfaces::action::HarvestFruit_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_robot_interfaces

namespace my_robot_interfaces
{

namespace action
{

struct HarvestFruit_GetResult
{
  using Request = my_robot_interfaces::action::HarvestFruit_GetResult_Request;
  using Response = my_robot_interfaces::action::HarvestFruit_GetResult_Response;
};

}  // namespace action

}  // namespace my_robot_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "my_robot_interfaces/action/detail/harvest_fruit__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__action__HarvestFruit_FeedbackMessage __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct HarvestFruit_FeedbackMessage_
{
  using Type = HarvestFruit_FeedbackMessage_<ContainerAllocator>;

  explicit HarvestFruit_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit HarvestFruit_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const my_robot_interfaces::action::HarvestFruit_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_FeedbackMessage
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__action__HarvestFruit_FeedbackMessage
    std::shared_ptr<my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HarvestFruit_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const HarvestFruit_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HarvestFruit_FeedbackMessage_

// alias to use template instance with default allocator
using HarvestFruit_FeedbackMessage =
  my_robot_interfaces::action::HarvestFruit_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace my_robot_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace my_robot_interfaces
{

namespace action
{

struct HarvestFruit
{
  /// The goal message defined in the action definition.
  using Goal = my_robot_interfaces::action::HarvestFruit_Goal;
  /// The result message defined in the action definition.
  using Result = my_robot_interfaces::action::HarvestFruit_Result;
  /// The feedback message defined in the action definition.
  using Feedback = my_robot_interfaces::action::HarvestFruit_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = my_robot_interfaces::action::HarvestFruit_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = my_robot_interfaces::action::HarvestFruit_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = my_robot_interfaces::action::HarvestFruit_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct HarvestFruit HarvestFruit;

}  // namespace action

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__HARVEST_FRUIT__STRUCT_HPP_
