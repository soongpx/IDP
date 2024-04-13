// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:action/Detection.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__DETECTION__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/action/detail/detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_Goal_mode
{
public:
  Init_Detection_Goal_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::Detection_Goal mode(::my_robot_interfaces::action::Detection_Goal::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::Detection_Goal>()
{
  return my_robot_interfaces::action::builder::Init_Detection_Goal_mode();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_Result_target_yaw
{
public:
  explicit Init_Detection_Result_target_yaw(::my_robot_interfaces::action::Detection_Result & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::Detection_Result target_yaw(::my_robot_interfaces::action::Detection_Result::_target_yaw_type arg)
  {
    msg_.target_yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_Result msg_;
};

class Init_Detection_Result_target_pitch
{
public:
  explicit Init_Detection_Result_target_pitch(::my_robot_interfaces::action::Detection_Result & msg)
  : msg_(msg)
  {}
  Init_Detection_Result_target_yaw target_pitch(::my_robot_interfaces::action::Detection_Result::_target_pitch_type arg)
  {
    msg_.target_pitch = std::move(arg);
    return Init_Detection_Result_target_yaw(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_Result msg_;
};

class Init_Detection_Result_fruit_number
{
public:
  explicit Init_Detection_Result_fruit_number(::my_robot_interfaces::action::Detection_Result & msg)
  : msg_(msg)
  {}
  Init_Detection_Result_target_pitch fruit_number(::my_robot_interfaces::action::Detection_Result::_fruit_number_type arg)
  {
    msg_.fruit_number = std::move(arg);
    return Init_Detection_Result_target_pitch(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_Result msg_;
};

class Init_Detection_Result_fruit_depth
{
public:
  explicit Init_Detection_Result_fruit_depth(::my_robot_interfaces::action::Detection_Result & msg)
  : msg_(msg)
  {}
  Init_Detection_Result_fruit_number fruit_depth(::my_robot_interfaces::action::Detection_Result::_fruit_depth_type arg)
  {
    msg_.fruit_depth = std::move(arg);
    return Init_Detection_Result_fruit_number(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_Result msg_;
};

class Init_Detection_Result_detected
{
public:
  Init_Detection_Result_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_Result_fruit_depth detected(::my_robot_interfaces::action::Detection_Result::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_Detection_Result_fruit_depth(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::Detection_Result>()
{
  return my_robot_interfaces::action::builder::Init_Detection_Result_detected();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_Feedback_fruit_detected
{
public:
  Init_Detection_Feedback_fruit_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::Detection_Feedback fruit_detected(::my_robot_interfaces::action::Detection_Feedback::_fruit_detected_type arg)
  {
    msg_.fruit_detected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::Detection_Feedback>()
{
  return my_robot_interfaces::action::builder::Init_Detection_Feedback_fruit_detected();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_SendGoal_Request_goal
{
public:
  explicit Init_Detection_SendGoal_Request_goal(::my_robot_interfaces::action::Detection_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::Detection_SendGoal_Request goal(::my_robot_interfaces::action::Detection_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_SendGoal_Request msg_;
};

class Init_Detection_SendGoal_Request_goal_id
{
public:
  Init_Detection_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_SendGoal_Request_goal goal_id(::my_robot_interfaces::action::Detection_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Detection_SendGoal_Request_goal(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::Detection_SendGoal_Request>()
{
  return my_robot_interfaces::action::builder::Init_Detection_SendGoal_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_SendGoal_Response_stamp
{
public:
  explicit Init_Detection_SendGoal_Response_stamp(::my_robot_interfaces::action::Detection_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::Detection_SendGoal_Response stamp(::my_robot_interfaces::action::Detection_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_SendGoal_Response msg_;
};

class Init_Detection_SendGoal_Response_accepted
{
public:
  Init_Detection_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_SendGoal_Response_stamp accepted(::my_robot_interfaces::action::Detection_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Detection_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::Detection_SendGoal_Response>()
{
  return my_robot_interfaces::action::builder::Init_Detection_SendGoal_Response_accepted();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_GetResult_Request_goal_id
{
public:
  Init_Detection_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::Detection_GetResult_Request goal_id(::my_robot_interfaces::action::Detection_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::Detection_GetResult_Request>()
{
  return my_robot_interfaces::action::builder::Init_Detection_GetResult_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_GetResult_Response_result
{
public:
  explicit Init_Detection_GetResult_Response_result(::my_robot_interfaces::action::Detection_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::Detection_GetResult_Response result(::my_robot_interfaces::action::Detection_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_GetResult_Response msg_;
};

class Init_Detection_GetResult_Response_status
{
public:
  Init_Detection_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_GetResult_Response_result status(::my_robot_interfaces::action::Detection_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Detection_GetResult_Response_result(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::Detection_GetResult_Response>()
{
  return my_robot_interfaces::action::builder::Init_Detection_GetResult_Response_status();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_Detection_FeedbackMessage_feedback
{
public:
  explicit Init_Detection_FeedbackMessage_feedback(::my_robot_interfaces::action::Detection_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::Detection_FeedbackMessage feedback(::my_robot_interfaces::action::Detection_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_FeedbackMessage msg_;
};

class Init_Detection_FeedbackMessage_goal_id
{
public:
  Init_Detection_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detection_FeedbackMessage_feedback goal_id(::my_robot_interfaces::action::Detection_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Detection_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_robot_interfaces::action::Detection_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::Detection_FeedbackMessage>()
{
  return my_robot_interfaces::action::builder::Init_Detection_FeedbackMessage_goal_id();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__DETECTION__BUILDER_HPP_
