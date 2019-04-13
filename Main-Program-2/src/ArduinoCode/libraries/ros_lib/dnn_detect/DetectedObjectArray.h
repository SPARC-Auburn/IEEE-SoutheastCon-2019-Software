#ifndef _ROS_dnn_detect_DetectedObjectArray_h
#define _ROS_dnn_detect_DetectedObjectArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "dnn_detect/DetectedObject.h"

namespace dnn_detect
{

  class DetectedObjectArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t objects_length;
      dnn_detect::DetectedObject st_objects;
      dnn_detect::DetectedObject * objects;

    DetectedObjectArray():
      header(),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (dnn_detect::DetectedObject*)realloc(this->objects, objects_lengthT * sizeof(dnn_detect::DetectedObject));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(dnn_detect::DetectedObject));
      }
     return offset;
    }

    const char * getType(){ return "dnn_detect/DetectedObjectArray"; };
    const char * getMD5(){ return "9f3fc8c582e8193cee7e46550ce68ec9"; };

  };

}
#endif