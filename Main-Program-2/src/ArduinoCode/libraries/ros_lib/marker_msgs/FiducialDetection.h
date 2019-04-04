#ifndef _ROS_marker_msgs_FiducialDetection_h
#define _ROS_marker_msgs_FiducialDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "marker_msgs/Fiducial.h"

namespace marker_msgs
{

  class FiducialDetection : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t camera_d_length;
      float st_camera_d;
      float * camera_d;
      float camera_k[9];
      const char* type;
      uint8_t fiducial_length;
      marker_msgs::Fiducial st_fiducial;
      marker_msgs::Fiducial * fiducial;

    FiducialDetection():
      header(),
      camera_d_length(0), camera_d(NULL),
      camera_k(),
      type(""),
      fiducial_length(0), fiducial(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = camera_d_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < camera_d_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->camera_d[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->camera_k[i]);
      }
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset++) = fiducial_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fiducial_length; i++){
      offset += this->fiducial[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t camera_d_lengthT = *(inbuffer + offset++);
      if(camera_d_lengthT > camera_d_length)
        this->camera_d = (float*)realloc(this->camera_d, camera_d_lengthT * sizeof(float));
      offset += 3;
      camera_d_length = camera_d_lengthT;
      for( uint8_t i = 0; i < camera_d_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_camera_d));
        memcpy( &(this->camera_d[i]), &(this->st_camera_d), sizeof(float));
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->camera_k[i]));
      }
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint8_t fiducial_lengthT = *(inbuffer + offset++);
      if(fiducial_lengthT > fiducial_length)
        this->fiducial = (marker_msgs::Fiducial*)realloc(this->fiducial, fiducial_lengthT * sizeof(marker_msgs::Fiducial));
      offset += 3;
      fiducial_length = fiducial_lengthT;
      for( uint8_t i = 0; i < fiducial_length; i++){
      offset += this->st_fiducial.deserialize(inbuffer + offset);
        memcpy( &(this->fiducial[i]), &(this->st_fiducial), sizeof(marker_msgs::Fiducial));
      }
     return offset;
    }

    const char * getType(){ return "marker_msgs/FiducialDetection"; };
    const char * getMD5(){ return "2ebb116fbde270de5551b0dc65e5f333"; };

  };

}
#endif