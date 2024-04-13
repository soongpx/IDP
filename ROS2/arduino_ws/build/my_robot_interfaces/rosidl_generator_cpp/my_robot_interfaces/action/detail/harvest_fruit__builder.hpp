// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:action/HarvestFruit.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__HARVEST_FRUIT__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__HARVEST_FRUIT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/action/detail/harvest_fruit__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_HarvestFruit_Goal_target_yaw
{
public:
  explicit Init_HarvestFruit_Goal_target_yaw(::my_robot_interfaces::action::HarvestFruit_Goal & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::HarvestFruit_Goal target_yaw(::my_robot_interfaces::action::HarvestFruit_Goal::_target_yaw_type arg)
  {
    msg_.target_yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Goal msg_;
};

class Init_HarvestFruit_Goal_target_pitch
{
public:
  explicit Init_HarvestFruit_Goal_target_pitch(::my_robot_interfaces::action::HarvestFruit_Goal & msg)
  : msg_(msg)
  {}
  Init_HarvestFruit_Goal_target_yaw target_pitch(::my_robot_interfaces::action::HarvestFruit_Goal::_target_pitch_type arg)
  {
    msg_.target_pitch = std::move(arg);
    return Init_HarvestFruit_Goal_target_yaw(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Goal msg_;
};

class Init_HarvestFruit_Goal_fruit_depth
{
public:
  explicit Init_HarvestFruit_Goal_fruit_depth(::my_robot_interfaces::action::HarvestFruit_Goal & msg)
  : msg_(msg)
  {}
  Init_HarvestFruit_Goal_target_pitch fruit_depth(::my_robot_interfaces::action::HarvestFruit_Goal::_fruit_depth_type arg)
  {
    msg_.fruit_depth = std::move(arg);
    return Init_HarvestFruit_Goal_target_pitch(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Goal msg_;
};

class Init_HarvestFruit_Goal_detected
{
public:
  Init_HarvestFruit_Goal_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HarvestFruit_Goal_fruit_depth detected(::my_robot_interfaces::action::HarvestFruit_Goal::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_HarvestFruit_Goal_fruit_depth(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::HarvestFruit_Goal>()
{
  return my_robot_interfaces::action::builder::Init_HarvestFruit_Goal_detected();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_HarvestFruit_Result_end
{
public:
  Init_HarvestFruit_Result_end()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::HarvestFruit_Result end(::my_robot_interfaces::action::HarvestFruit_Result::_end_type arg)
  {
    msg_.end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::HarvestFruit_Result>()
{
  return my_robot_interfaces::action::builder::Init_HarvestFruit_Result_end();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_HarvestFruit_Feedback_direction
{
public:
  explicit Init_HarvestFruit_Feedback_direction(::my_robot_interfaces::action::HarvestFruit_Feedback & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::HarvestFruit_Feedback direction(::my_robot_interfaces::action::HarvestFruit_Feedback::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Feedback msg_;
};

class Init_HarvestFruit_Feedback_vibrate_speed
{
public:
  explicit Init_HarvestFruit_Feedback_vibrate_speed(::my_robot_interfaces::action::HarvestFruit_Feedback & msg)
  : msg_(msg)
  {}
  Init_HarvestFruit_Feedback_direction vibrate_speed(::my_robot_interfaces::action::HarvestFruit_Feedback::_vibrate_speed_type arg)
  {
    msg_.vibrate_speed = std::move(arg);
    return Init_HarvestFruit_Feedback_direction(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Feedback msg_;
};

class Init_HarvestFruit_Feedback_extend_speed
{
public:
  explicit Init_HarvestFruit_Feedback_extend_speed(::my_robot_interfaces::action::HarvestFruit_Feedback & msg)
  : msg_(msg)
  {}
  Init_HarvestFruit_Feedback_vibrate_speed extend_speed(::my_robot_interfaces::action::HarvestFruit_Feedback::_extend_speed_type arg)
  {
    msg_.extend_speed = std::move(arg);
    return Init_HarvestFruit_Feedback_vibrate_speed(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Feedback msg_;
};

class Init_HarvestFruit_Feedback_tilt_speed
{
public:
  explicit Init_HarvestFruit_Feedback_tilt_speed(::my_robot_interfaces::action::HarvestFruit_Feedback & msg)
  : msg_(msg)
  {}
  Init_HarvestFruit_Feedback_extend_speed tilt_speed(::my_robot_interfaces::action::HarvestFruit_Feedback::_tilt_speed_type arg)
  {
    msg_.tilt_speed = std::move(arg);
    return Init_HarvestFruit_Feedback_extend_speed(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Feedback msg_;
};

class Init_HarvestFruit_Feedback_rotate_speed
{
public:
  Init_HarvestFruit_Feedback_rotate_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HarvestFruit_Feedback_tilt_speed rotate_speed(::my_robot_interfaces::action::HarvestFruit_Feedback::_rotate_speed_type arg)
  {
    msg_.rotate_speed = std::move(arg);
    return Init_HarvestFruit_Feedback_tilt_speed(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::HarvestFruit_Feedback>()
{
  return my_robot_interfaces::action::builder::Init_HarvestFruit_Feedback_rotate_speed();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_HarvestFruit_SendGoal_Request_goal
{
public:
  explicit Init_HarvestFruit_SendGoal_Request_goal(::my_robot_interfaces::action::HarvestFruit_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::HarvestFruit_SendGoal_Request goal(::my_robot_interfaces::action::HarvestFruit_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_SendGoal_Request msg_;
};

class Init_HarvestFruit_SendGoal_Request_goal_id
{
public:
  Init_HarvestFruit_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HarvestFruit_SendGoal_Request_goal goal_id(::my_robot_interfaces::action::HarvestFruit_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HarvestFruit_SendGoal_Request_goal(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::HarvestFruit_SendGoal_Request>()
{
  return my_robot_interfaces::action::builder::Init_HarvestFruit_SendGoal_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_HarvestFruit_SendGoal_Response_stamp
{
public:
  explicit Init_HarvestFruit_SendGoal_Response_stamp(::my_robot_interfaces::action::HarvestFruit_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::HarvestFruit_SendGoal_Response stamp(::my_robot_interfaces::action::HarvestFruit_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_SendGoal_Response msg_;
};

class Init_HarvestFruit_SendGoal_Response_accepted
{
public:
  Init_HarvestFruit_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HarvestFruit_SendGoal_Response_stamp accepted(::my_robot_interfaces::action::HarvestFruit_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_HarvestFruit_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::HarvestFruit_SendGoal_Response>()
{
  return my_robot_interfaces::action::builder::Init_HarvestFruit_SendGoal_Response_accepted();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_HarvestFruit_GetResult_Request_goal_id
{
public:
  Init_HarvestFruit_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::HarvestFruit_GetResult_Request goal_id(::my_robot_interfaces::action::HarvestFruit_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::HarvestFruit_GetResult_Request>()
{
  return my_robot_interfaces::action::builder::Init_HarvestFruit_GetResult_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_HarvestFruit_GetResult_Response_result
{
public:
  explicit Init_HarvestFruit_GetResult_Response_result(::my_robot_interfaces::action::HarvestFruit_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::HarvestFruit_GetResult_Response result(::my_robot_interfaces::action::HarvestFruit_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_GetResult_Response msg_;
};

class Init_HarvestFruit_GetResult_Response_status
{
public:
  Init_HarvestFruit_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HarvestFruit_GetResult_Response_result status(::my_robot_interfaces::action::HarvestFruit_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_HarvestFruit_GetResult_Response_result(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::HarvestFruit_GetResult_Response>()
{
  return my_robot_interfaces::action::builder::Init_HarvestFruit_GetResult_Response_status();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_HarvestFruit_FeedbackMessage_feedback
{
public:
  explicit Init_HarvestFruit_FeedbackMessage_feedback(::my_robot_interfaces::action::HarvestFruit_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::HarvestFruit_FeedbackMessage feedback(::my_robot_interfaces::action::HarvestFruit_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_FeedbackMessage msg_;
};

class Init_HarvestFruit_FeedbackMessage_goal_id
{
public:
  Init_HarvestFruit_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HarvestFruit_FeedbackMessage_feedback goal_id(::my_robot_interfaces::action::HarvestFruit_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HarvestFruit_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_robot_interfaces::action::HarvestFruit_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::HarvestFruit_FeedbackMessage>()
{
  return my_robot_interfaces::action::builder::Init_HarvestFruit_FeedbackMessage_goal_id();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__HARVEST_FRUIT__BUILDER_HPP_
