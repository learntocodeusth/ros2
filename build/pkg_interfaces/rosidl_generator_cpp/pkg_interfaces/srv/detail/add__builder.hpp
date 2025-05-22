// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pkg_interfaces:srv/Add.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pkg_interfaces/srv/add.hpp"


#ifndef PKG_INTERFACES__SRV__DETAIL__ADD__BUILDER_HPP_
#define PKG_INTERFACES__SRV__DETAIL__ADD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pkg_interfaces/srv/detail/add__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pkg_interfaces
{

namespace srv
{

namespace builder
{

class Init_Add_Request_num2
{
public:
  explicit Init_Add_Request_num2(::pkg_interfaces::srv::Add_Request & msg)
  : msg_(msg)
  {}
  ::pkg_interfaces::srv::Add_Request num2(::pkg_interfaces::srv::Add_Request::_num2_type arg)
  {
    msg_.num2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pkg_interfaces::srv::Add_Request msg_;
};

class Init_Add_Request_num1
{
public:
  Init_Add_Request_num1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Add_Request_num2 num1(::pkg_interfaces::srv::Add_Request::_num1_type arg)
  {
    msg_.num1 = std::move(arg);
    return Init_Add_Request_num2(msg_);
  }

private:
  ::pkg_interfaces::srv::Add_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pkg_interfaces::srv::Add_Request>()
{
  return pkg_interfaces::srv::builder::Init_Add_Request_num1();
}

}  // namespace pkg_interfaces


namespace pkg_interfaces
{

namespace srv
{

namespace builder
{

class Init_Add_Response_sum
{
public:
  Init_Add_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pkg_interfaces::srv::Add_Response sum(::pkg_interfaces::srv::Add_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pkg_interfaces::srv::Add_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pkg_interfaces::srv::Add_Response>()
{
  return pkg_interfaces::srv::builder::Init_Add_Response_sum();
}

}  // namespace pkg_interfaces


namespace pkg_interfaces
{

namespace srv
{

namespace builder
{

class Init_Add_Event_response
{
public:
  explicit Init_Add_Event_response(::pkg_interfaces::srv::Add_Event & msg)
  : msg_(msg)
  {}
  ::pkg_interfaces::srv::Add_Event response(::pkg_interfaces::srv::Add_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pkg_interfaces::srv::Add_Event msg_;
};

class Init_Add_Event_request
{
public:
  explicit Init_Add_Event_request(::pkg_interfaces::srv::Add_Event & msg)
  : msg_(msg)
  {}
  Init_Add_Event_response request(::pkg_interfaces::srv::Add_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Add_Event_response(msg_);
  }

private:
  ::pkg_interfaces::srv::Add_Event msg_;
};

class Init_Add_Event_info
{
public:
  Init_Add_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Add_Event_request info(::pkg_interfaces::srv::Add_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Add_Event_request(msg_);
  }

private:
  ::pkg_interfaces::srv::Add_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pkg_interfaces::srv::Add_Event>()
{
  return pkg_interfaces::srv::builder::Init_Add_Event_info();
}

}  // namespace pkg_interfaces

#endif  // PKG_INTERFACES__SRV__DETAIL__ADD__BUILDER_HPP_
