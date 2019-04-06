#ifndef _ROS_marker_msgs_Fiducial_h
#define _ROS_marker_msgs_Fiducial_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace marker_msgs
{

  class Fiducial : public ros::Msg
  {
    public:
      uint8_t ids_length;
      int32_t st_ids;
      int32_t * ids;
      uint8_t ids_confidence_length;
      float st_ids_confidence;
      float * ids_confidence;
      uint8_t object_points_length;
      geometry_msgs::Point st_object_points;
      geometry_msgs::Point * object_points;
      uint8_t image_points_length;
      geometry_msgs::Point st_image_points;
      geometry_msgs::Point * image_points;

    Fiducial():
      ids_length(0), ids(NULL),
      ids_confidence_length(0), ids_confidence(NULL),
      object_points_length(0), object_points(NULL),
      image_points_length(0), image_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_idsi;
      u_idsi.real = this->ids[i];
      *(outbuffer + offset + 0) = (u_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ids[i]);
      }
      *(outbuffer + offset++) = ids_confidence_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ids_confidence_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->ids_confidence[i]);
      }
      *(outbuffer + offset++) = object_points_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < object_points_length; i++){
      offset += this->object_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = image_points_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < image_points_length; i++){
      offset += this->image_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t ids_lengthT = *(inbuffer + offset++);
      if(ids_lengthT > ids_length)
        this->ids = (int32_t*)realloc(this->ids, ids_lengthT * sizeof(int32_t));
      offset += 3;
      ids_length = ids_lengthT;
      for( uint8_t i = 0; i < ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_ids;
      u_st_ids.base = 0;
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ids = u_st_ids.real;
      offset += sizeof(this->st_ids);
        memcpy( &(this->ids[i]), &(this->st_ids), sizeof(int32_t));
      }
      uint8_t ids_confidence_lengthT = *(inbuffer + offset++);
      if(ids_confidence_lengthT > ids_confidence_length)
        this->ids_confidence = (float*)realloc(this->ids_confidence, ids_confidence_lengthT * sizeof(float));
      offset += 3;
      ids_confidence_length = ids_confidence_lengthT;
      for( uint8_t i = 0; i < ids_confidence_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_ids_confidence));
        memcpy( &(this->ids_confidence[i]), &(this->st_ids_confidence), sizeof(float));
      }
      uint8_t object_points_lengthT = *(inbuffer + offset++);
      if(object_points_lengthT > object_points_length)
        this->object_points = (geometry_msgs::Point*)realloc(this->object_points, object_points_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      object_points_length = object_points_lengthT;
      for( uint8_t i = 0; i < object_points_length; i++){
      offset += this->st_object_points.deserialize(inbuffer + offset);
        memcpy( &(this->object_points[i]), &(this->st_object_points), sizeof(geometry_msgs::Point));
      }
      uint8_t image_points_lengthT = *(inbuffer + offset++);
      if(image_points_lengthT > image_points_length)
        this->image_points = (geometry_msgs::Point*)realloc(this->image_points, image_points_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      image_points_length = image_points_lengthT;
      for( uint8_t i = 0; i < image_points_length; i++){
      offset += this->st_image_points.deserialize(inbuffer + offset);
        memcpy( &(this->image_points[i]), &(this->st_image_points), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "marker_msgs/Fiducial"; };
    const char * getMD5(){ return "0771474f385b4ef416eeda4ba2143ce2"; };

  };

}
#endif