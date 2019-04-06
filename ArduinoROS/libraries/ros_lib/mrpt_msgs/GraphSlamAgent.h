#ifndef _ROS_mrpt_msgs_GraphSlamAgent_h
#define _ROS_mrpt_msgs_GraphSlamAgent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Time.h"

namespace mrpt_msgs
{

  class GraphSlamAgent : public ros::Msg
  {
    public:
      typedef std_msgs::String _name_type;
      _name_type name;
      typedef std_msgs::String _hostname_type;
      _hostname_type hostname;
      typedef std_msgs::String _ip_addr_type;
      _ip_addr_type ip_addr;
      typedef uint16_t _port_type;
      _port_type port;
      typedef std_msgs::Bool _is_online_type;
      _is_online_type is_online;
      typedef std_msgs::Time _last_seen_time_type;
      _last_seen_time_type last_seen_time;
      typedef std_msgs::String _topic_namespace_type;
      _topic_namespace_type topic_namespace;
      typedef int32_t _agent_ID_type;
      _agent_ID_type agent_ID;

    GraphSlamAgent():
      name(),
      hostname(),
      ip_addr(),
      port(0),
      is_online(),
      last_seen_time(),
      topic_namespace(),
      agent_ID(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->name.serialize(outbuffer + offset);
      offset += this->hostname.serialize(outbuffer + offset);
      offset += this->ip_addr.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->port >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->port >> (8 * 1)) & 0xFF;
      offset += sizeof(this->port);
      offset += this->is_online.serialize(outbuffer + offset);
      offset += this->last_seen_time.serialize(outbuffer + offset);
      offset += this->topic_namespace.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_agent_ID;
      u_agent_ID.real = this->agent_ID;
      *(outbuffer + offset + 0) = (u_agent_ID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_agent_ID.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_agent_ID.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_agent_ID.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->agent_ID);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->name.deserialize(inbuffer + offset);
      offset += this->hostname.deserialize(inbuffer + offset);
      offset += this->ip_addr.deserialize(inbuffer + offset);
      this->port =  ((uint16_t) (*(inbuffer + offset)));
      this->port |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->port);
      offset += this->is_online.deserialize(inbuffer + offset);
      offset += this->last_seen_time.deserialize(inbuffer + offset);
      offset += this->topic_namespace.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_agent_ID;
      u_agent_ID.base = 0;
      u_agent_ID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_agent_ID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_agent_ID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_agent_ID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->agent_ID = u_agent_ID.real;
      offset += sizeof(this->agent_ID);
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/GraphSlamAgent"; };
    const char * getMD5(){ return "6f5305e3be2b2f63220c0183a8af1288"; };

  };

}
#endif