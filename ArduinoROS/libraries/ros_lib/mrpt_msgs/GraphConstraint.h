#ifndef _ROS_mrpt_msgs_GraphConstraint_h
#define _ROS_mrpt_msgs_GraphConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovariance.h"

namespace mrpt_msgs
{

  class GraphConstraint : public ros::Msg
  {
    public:
      typedef uint64_t _nodeID_from_type;
      _nodeID_from_type nodeID_from;
      typedef uint64_t _nodeID_to_type;
      _nodeID_to_type nodeID_to;
      typedef geometry_msgs::PoseWithCovariance _constraint_type;
      _constraint_type constraint;

    GraphConstraint():
      nodeID_from(0),
      nodeID_to(0),
      constraint()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID_from;
      u_nodeID_from.real = this->nodeID_from;
      *(outbuffer + offset + 0) = (u_nodeID_from.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nodeID_from.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nodeID_from.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nodeID_from.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodeID_from);
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID_to;
      u_nodeID_to.real = this->nodeID_to;
      *(outbuffer + offset + 0) = (u_nodeID_to.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nodeID_to.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nodeID_to.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nodeID_to.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodeID_to);
      offset += this->constraint.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID_from;
      u_nodeID_from.base = 0;
      u_nodeID_from.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nodeID_from.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nodeID_from.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nodeID_from.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nodeID_from = u_nodeID_from.real;
      offset += sizeof(this->nodeID_from);
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID_to;
      u_nodeID_to.base = 0;
      u_nodeID_to.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nodeID_to.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nodeID_to.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nodeID_to.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nodeID_to = u_nodeID_to.real;
      offset += sizeof(this->nodeID_to);
      offset += this->constraint.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/GraphConstraint"; };
    const char * getMD5(){ return "27a8223828dcd501cdc97873eecdd09e"; };

  };

}
#endif