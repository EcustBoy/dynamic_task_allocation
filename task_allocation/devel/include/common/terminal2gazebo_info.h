// Generated by gencpp from file common/terminal2gazebo_info.msg
// DO NOT EDIT!


#ifndef COMMON_MESSAGE_TERMINAL2GAZEBO_INFO_H
#define COMMON_MESSAGE_TERMINAL2GAZEBO_INFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace common
{
template <class ContainerAllocator>
struct terminal2gazebo_info_
{
  typedef terminal2gazebo_info_<ContainerAllocator> Type;

  terminal2gazebo_info_()
    : map_height_msg(0)
    , map_width_msg(0)
    , map_room_msg(0)  {
    }
  terminal2gazebo_info_(const ContainerAllocator& _alloc)
    : map_height_msg(0)
    , map_width_msg(0)
    , map_room_msg(0)  {
  (void)_alloc;
    }



   typedef int16_t _map_height_msg_type;
  _map_height_msg_type map_height_msg;

   typedef int16_t _map_width_msg_type;
  _map_width_msg_type map_width_msg;

   typedef int16_t _map_room_msg_type;
  _map_room_msg_type map_room_msg;




  typedef boost::shared_ptr< ::common::terminal2gazebo_info_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::common::terminal2gazebo_info_<ContainerAllocator> const> ConstPtr;

}; // struct terminal2gazebo_info_

typedef ::common::terminal2gazebo_info_<std::allocator<void> > terminal2gazebo_info;

typedef boost::shared_ptr< ::common::terminal2gazebo_info > terminal2gazebo_infoPtr;
typedef boost::shared_ptr< ::common::terminal2gazebo_info const> terminal2gazebo_infoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::common::terminal2gazebo_info_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::common::terminal2gazebo_info_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'common': ['/home/nubot8/dynamic_allocation/task_allocation/src/common/msgs']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::common::terminal2gazebo_info_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::common::terminal2gazebo_info_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common::terminal2gazebo_info_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common::terminal2gazebo_info_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common::terminal2gazebo_info_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common::terminal2gazebo_info_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::common::terminal2gazebo_info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f08900b20a86fa5aa1214f8fc88dcbd2";
  }

  static const char* value(const ::common::terminal2gazebo_info_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf08900b20a86fa5aULL;
  static const uint64_t static_value2 = 0xa1214f8fc88dcbd2ULL;
};

template<class ContainerAllocator>
struct DataType< ::common::terminal2gazebo_info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "common/terminal2gazebo_info";
  }

  static const char* value(const ::common::terminal2gazebo_info_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::common::terminal2gazebo_info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16  map_height_msg                                      \n\
int16  map_width_msg                                       \n\
int16  map_room_msg                                         \n\
";
  }

  static const char* value(const ::common::terminal2gazebo_info_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::common::terminal2gazebo_info_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.map_height_msg);
      stream.next(m.map_width_msg);
      stream.next(m.map_room_msg);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct terminal2gazebo_info_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::common::terminal2gazebo_info_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::common::terminal2gazebo_info_<ContainerAllocator>& v)
  {
    s << indent << "map_height_msg: ";
    Printer<int16_t>::stream(s, indent + "  ", v.map_height_msg);
    s << indent << "map_width_msg: ";
    Printer<int16_t>::stream(s, indent + "  ", v.map_width_msg);
    s << indent << "map_room_msg: ";
    Printer<int16_t>::stream(s, indent + "  ", v.map_room_msg);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMON_MESSAGE_TERMINAL2GAZEBO_INFO_H