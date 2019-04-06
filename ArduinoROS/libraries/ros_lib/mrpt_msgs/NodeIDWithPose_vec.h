#ifndef _ROS_mrpt_msgs_NodeIDWithPose_vec_h
#define _ROS_mrpt_msgs_NodeIDWithPose_vec_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mrpt_msgs/NodeIDWithPose.h"

namespace mrpt_msgs
{

  class NodeIDWithPose_vec : public ros::Msg
  {
    public:
      uint32_t vec_length;
      typedef mrpt_msgs::NodeIDWithPose _vec_type;
      _vec_type st_vec;
      _vec_type * vec;

    NodeIDWithPose_vec():
      vec_length(0), vec(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->vec_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vec_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vec_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vec_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vec_length);
      for( uint32_t i = 0; i < vec_length; i++){
      offset += this->vec[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t vec_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vec_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vec_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vec_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vec_length);
      if(vec_lengthT > vec_length)
        this->vec = (mrpt_msgs::NodeIDWithPose*)realloc(this->vec, vec_lengthT * sizeof(mrpt_msgs::NodeIDWithPose));
      vec_length = vec_lengthT;
      for( uint32_t i = 0; i < vec_length; i++){
      offset += this->st_vec.deserialize(inbuffer + offset);
        memcpy( &(this->vec[i]), &(this->st_vec), sizeof(mrpt_msgs::NodeIDWithPose));
      }
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/NodeIDWithPose_vec"; };
    const char * getMD5(){ return "f30000109eab9cc7bc6b44c3e86d9fac"; };

  };

}
#endif