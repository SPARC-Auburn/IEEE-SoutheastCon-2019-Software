#ifndef _ROS_fiducial_msgs_Fiducial_h
#define _ROS_fiducial_msgs_Fiducial_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fiducial_msgs
{

  class Fiducial : public ros::Msg
  {
    public:
      int32_t fiducial_id;
      int32_t direction;
      float x0;
      float y0;
      float x1;
      float y1;
      float x2;
      float y2;
      float x3;
      float y3;

    Fiducial():
      fiducial_id(0),
      direction(0),
      x0(0),
      y0(0),
      x1(0),
      y1(0),
      x2(0),
      y2(0),
      x3(0),
      y3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.real = this->fiducial_id;
      *(outbuffer + offset + 0) = (u_fiducial_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fiducial_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fiducial_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fiducial_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fiducial_id);
      union {
        int32_t real;
        uint32_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_direction.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_direction.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_direction.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->direction);
      offset += serializeAvrFloat64(outbuffer + offset, this->x0);
      offset += serializeAvrFloat64(outbuffer + offset, this->y0);
      offset += serializeAvrFloat64(outbuffer + offset, this->x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->y2);
      offset += serializeAvrFloat64(outbuffer + offset, this->x3);
      offset += serializeAvrFloat64(outbuffer + offset, this->y3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.base = 0;
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fiducial_id = u_fiducial_id.real;
      offset += sizeof(this->fiducial_id);
      union {
        int32_t real;
        uint32_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y3));
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/Fiducial"; };
    const char * getMD5(){ return "a0094064db6c7772c6b638a2dab17f42"; };

  };

}
#endif