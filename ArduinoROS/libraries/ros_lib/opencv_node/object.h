#ifndef _ROS_opencv_node_object_h
#define _ROS_opencv_node_object_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace opencv_node
{

  class object : public ros::Msg
  {
    public:
      typedef uint32_t _x_position_type;
      _x_position_type x_position;
      typedef uint32_t _y_position_type;
      _y_position_type y_position;
      typedef uint32_t _width_type;
      _width_type width;
      typedef uint32_t _height_type;
      _height_type height;
      typedef float _distance_type;
      _distance_type distance;
      typedef uint8_t _color_index_type;
      _color_index_type color_index;
      typedef uint8_t _object_type_type;
      _object_type_type object_type;

    object():
      x_position(0),
      y_position(0),
      width(0),
      height(0),
      distance(0),
      color_index(0),
      object_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->x_position >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->x_position >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->x_position >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->x_position >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x_position);
      *(outbuffer + offset + 0) = (this->y_position >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->y_position >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->y_position >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->y_position >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y_position);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      *(outbuffer + offset + 0) = (this->color_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->color_index);
      *(outbuffer + offset + 0) = (this->object_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->object_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->x_position =  ((uint32_t) (*(inbuffer + offset)));
      this->x_position |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->x_position |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->x_position |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->x_position);
      this->y_position =  ((uint32_t) (*(inbuffer + offset)));
      this->y_position |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->y_position |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->y_position |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->y_position);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      this->color_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->color_index);
      this->object_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->object_type);
     return offset;
    }

    const char * getType(){ return "opencv_node/object"; };
    const char * getMD5(){ return "2ffacbbb937a845333e840b126fe6a12"; };

  };

}
#endif