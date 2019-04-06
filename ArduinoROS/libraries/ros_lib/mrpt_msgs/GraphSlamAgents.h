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
      uint32_t list_length;
      typedef mrpt_msgs::GraphSlamAgent _list_type;
      _list_type st_list;
      _list_type * list;

    GraphSlamAgents():
      list_length(0), list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->list_length);
      for( uint32_t i = 0; i < list_length; i++){
      offset += this->list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->list_length);
      if(list_lengthT > list_length)
        this->list = (mrpt_msgs::GraphSlamAgent*)realloc(this->list, list_lengthT * sizeof(mrpt_msgs::GraphSlamAgent));
      list_length = list_lengthT;
      for( uint32_t i = 0; i < list_length; i++){
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