#ifndef _ROS_fiducial_msgs_FiducialTransform_h
#define _ROS_fiducial_msgs_FiducialTransform_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"

namespace fiducial_msgs
{

  class FiducialTransform : public ros::Msg
  {
    public:
      int32_t fiducial_id;
      geometry_msgs::Transform transform;
      float image_error;
      float object_error;
      float fiducial_area;

    FiducialTransform():
      fiducial_id(0),
      transform(),
      image_error(0),
      object_error(0),
      fiducial_area(0)
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
      offset += this->transform.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->image_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->object_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->fiducial_area);
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
      offset += this->transform.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->image_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->object_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->fiducial_area));
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/FiducialTransform"; };
    const char * getMD5(){ return "9f77f4c92fda876d2249ffbc19859044"; };

  };

}
#endif