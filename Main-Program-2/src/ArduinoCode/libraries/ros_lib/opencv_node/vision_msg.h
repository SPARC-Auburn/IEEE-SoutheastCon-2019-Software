#ifndef _ROS_opencv_node_vision_msg_h
#define _ROS_opencv_node_vision_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "opencv_node/object.h"

namespace opencv_node
{

  class vision_msg : public ros::Msg
  {
    public:
      uint8_t objects_length;
      opencv_node::object st_objects;
      opencv_node::object * objects;

    vision_msg():
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (opencv_node::object*)realloc(this->objects, objects_lengthT * sizeof(opencv_node::object));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(opencv_node::object));
      }
     return offset;
    }

    const char * getType(){ return "opencv_node/vision_msg"; };
    const char * getMD5(){ return "5abfddaa0c41b9448d210310355541e0"; };

  };

}
#endif