#ifndef _ROS_mrpt_msgs_NodeIDWithPose_h
#define _ROS_mrpt_msgs_NodeIDWithPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/String.h"

namespace mrpt_msgs
{

  class NodeIDWithPose : public ros::Msg
  {
    public:
      uint64_t nodeID;
      geometry_msgs::Pose pose;
      std_msgs::String str_ID;
      uint64_t nodeID_loc;

    NodeIDWithPose():
      nodeID(0),
      pose(),
      str_ID(),
      nodeID_loc(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID;
      u_nodeID.real = this->nodeID;
      *(outbuffer + offset + 0) = (u_nodeID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nodeID.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nodeID.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nodeID.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodeID);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->str_ID.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID_loc;
      u_nodeID_loc.real = this->nodeID_loc;
      *(outbuffer + offset + 0) = (u_nodeID_loc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nodeID_loc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nodeID_loc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nodeID_loc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodeID_loc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID;
      u_nodeID.base = 0;
      u_nodeID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nodeID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nodeID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nodeID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nodeID = u_nodeID.real;
      offset += sizeof(this->nodeID);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->str_ID.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID_loc;
      u_nodeID_loc.base = 0;
      u_nodeID_loc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nodeID_loc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nodeID_loc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nodeID_loc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nodeID_loc = u_nodeID_loc.real;
      offset += sizeof(this->nodeID_loc);
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/NodeIDWithPose"; };
    const char * getMD5(){ return "87c8db37a689c10a5c5dc1aa39838320"; };

  };

}
#endif