#ifndef _ROS_mrpt_msgs_NetworkOfPoses_h
#define _ROS_mrpt_msgs_NetworkOfPoses_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mrpt_msgs/NodeIDWithPose_vec.h"
#include "mrpt_msgs/GraphConstraint.h"

namespace mrpt_msgs
{

  class NetworkOfPoses : public ros::Msg
  {
    public:
      uint64_t root;
      mrpt_msgs::NodeIDWithPose_vec nodes;
      uint8_t constraints_length;
      mrpt_msgs::GraphConstraint st_constraints;
      mrpt_msgs::GraphConstraint * constraints;

    NetworkOfPoses():
      root(0),
      nodes(),
      constraints_length(0), constraints(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_root;
      u_root.real = this->root;
      *(outbuffer + offset + 0) = (u_root.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_root.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_root.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_root.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->root);
      offset += this->nodes.serialize(outbuffer + offset);
      *(outbuffer + offset++) = constraints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < constraints_length; i++){
      offset += this->constraints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_root;
      u_root.base = 0;
      u_root.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_root.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_root.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_root.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->root = u_root.real;
      offset += sizeof(this->root);
      offset += this->nodes.deserialize(inbuffer + offset);
      uint8_t constraints_lengthT = *(inbuffer + offset++);
      if(constraints_lengthT > constraints_length)
        this->constraints = (mrpt_msgs::GraphConstraint*)realloc(this->constraints, constraints_lengthT * sizeof(mrpt_msgs::GraphConstraint));
      offset += 3;
      constraints_length = constraints_lengthT;
      for( uint8_t i = 0; i < constraints_length; i++){
      offset += this->st_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->constraints[i]), &(this->st_constraints), sizeof(mrpt_msgs::GraphConstraint));
      }
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/NetworkOfPoses"; };
    const char * getMD5(){ return "2f7e17a78e81d376b3e999d635df4228"; };

  };

}
#endif