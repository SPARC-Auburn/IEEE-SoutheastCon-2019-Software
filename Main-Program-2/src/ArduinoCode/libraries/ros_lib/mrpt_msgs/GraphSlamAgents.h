#ifndef _ROS_mrpt_msgs_GraphSlamAgents_h
#define _ROS_mrpt_msgs_GraphSlamAgents_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mrpt_msgs/GraphSlamAgent.h"

namespace mrpt_msgs
{

  class GraphSlamAgents : public ros::Msg
  {
    public:
      uint8_t list_length;
      mrpt_msgs::GraphSlamAgent st_list;
      mrpt_msgs::GraphSlamAgent * list;

    GraphSlamAgents():
      list_length(0), list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < list_length; i++){
      offset += this->list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t list_lengthT = *(inbuffer + offset++);
      if(list_lengthT > list_length)
        this->list = (mrpt_msgs::GraphSlamAgent*)realloc(this->list, list_lengthT * sizeof(mrpt_msgs::GraphSlamAgent));
      offset += 3;
      list_length = list_lengthT;
      for( uint8_t i = 0; i < list_length; i++){
      offset += this->st_list.deserialize(inbuffer + offset);
        memcpy( &(this->list[i]), &(this->st_list), sizeof(mrpt_msgs::GraphSlamAgent));
      }
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/GraphSlamAgents"; };
    const char * getMD5(){ return "ac3446e50a170e19b88734cb8e7206bb"; };

  };

}
#endif