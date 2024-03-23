// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/FindObstacle.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/find_obstacle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_FindObstacle_reach
{
public:
  explicit Init_FindObstacle_reach(::my_robot_interfaces::msg::FindObstacle & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::FindObstacle reach(::my_robot_interfaces::msg::FindObstacle::_reach_type arg)
  {
    msg_.reach = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::FindObstacle msg_;
};

class Init_FindObstacle_nearest_angle2
{
public:
  explicit Init_FindObstacle_nearest_angle2(::my_robot_interfaces::msg::FindObstacle & msg)
  : msg_(msg)
  {}
  Init_FindObstacle_reach nearest_angle2(::my_robot_interfaces::msg::FindObstacle::_nearest_angle2_type arg)
  {
    msg_.nearest_angle2 = std::move(arg);
    return Init_FindObstacle_reach(msg_);
  }

private:
  ::my_robot_interfaces::msg::FindObstacle msg_;
};

class Init_FindObstacle_nearest_distance2
{
public:
  explicit Init_FindObstacle_nearest_distance2(::my_robot_interfaces::msg::FindObstacle & msg)
  : msg_(msg)
  {}
  Init_FindObstacle_nearest_angle2 nearest_distance2(::my_robot_interfaces::msg::FindObstacle::_nearest_distance2_type arg)
  {
    msg_.nearest_distance2 = std::move(arg);
    return Init_FindObstacle_nearest_angle2(msg_);
  }

private:
  ::my_robot_interfaces::msg::FindObstacle msg_;
};

class Init_FindObstacle_nearest_angle1
{
public:
  explicit Init_FindObstacle_nearest_angle1(::my_robot_interfaces::msg::FindObstacle & msg)
  : msg_(msg)
  {}
  Init_FindObstacle_nearest_distance2 nearest_angle1(::my_robot_interfaces::msg::FindObstacle::_nearest_angle1_type arg)
  {
    msg_.nearest_angle1 = std::move(arg);
    return Init_FindObstacle_nearest_distance2(msg_);
  }

private:
  ::my_robot_interfaces::msg::FindObstacle msg_;
};

class Init_FindObstacle_nearest_distance1
{
public:
  Init_FindObstacle_nearest_distance1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FindObstacle_nearest_angle1 nearest_distance1(::my_robot_interfaces::msg::FindObstacle::_nearest_distance1_type arg)
  {
    msg_.nearest_distance1 = std::move(arg);
    return Init_FindObstacle_nearest_angle1(msg_);
  }

private:
  ::my_robot_interfaces::msg::FindObstacle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::FindObstacle>()
{
  return my_robot_interfaces::msg::builder::Init_FindObstacle_nearest_distance1();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__FIND_OBSTACLE__BUILDER_HPP_
