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
      uint8_t vec_length;
      mrpt_msgs::NodeIDWithPose st_vec;
      mrpt_msgs::NodeIDWithPose * vec;

    NodeIDWithPose_vec():
      vec_length(0), vec(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = vec_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < vec_length; i++){
      offset += this->vec[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t vec_lengthT = *(inbuffer + offset++);
      if(vec_lengthT > vec_length)
        this->vec = (mrpt_msgs::NodeIDWithPose*)realloc(this->vec, vec_lengthT * sizeof(mrpt_msgs::NodeIDWithPose));
      offset += 3;
      vec_length = vec_lengthT;
      for( uint8_t i = 0; i < vec_length; i++){
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