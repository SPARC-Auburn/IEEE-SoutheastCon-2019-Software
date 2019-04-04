#ifndef _ROS_marker_msgs_MarkerDetection_h
#define _ROS_marker_msgs_MarkerDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"
#include "marker_msgs/Marker.h"

namespace marker_msgs
{

  class MarkerDetection : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float distance_min;
      float distance_max;
      float distance_max_id;
      geometry_msgs::Quaternion view_direction;
      float fov_horizontal;
      float fov_vertical;
      const char* type;
      uint8_t markers_length;
      marker_msgs::Marker st_markers;
      marker_msgs::Marker * markers;

    MarkerDetection():
      header(),
      distance_min(0),
      distance_max(0),
      distance_max_id(0),
      view_direction(),
      fov_horizontal(0),
      fov_vertical(0),
      type(""),
      markers_length(0), markers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance_min;
      u_distance_min.real = this->distance_min;
      *(outbuffer + offset + 0) = (u_distance_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_min);
      union {
        float real;
        uint32_t base;
      } u_distance_max;
      u_distance_max.real = this->distance_max;
      *(outbuffer + offset + 0) = (u_distance_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_max);
      union {
        float real;
        uint32_t base;
      } u_distance_max_id;
      u_distance_max_id.real = this->distance_max_id;
      *(outbuffer + offset + 0) = (u_distance_max_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_max_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_max_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_max_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_max_id);
      offset += this->view_direction.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_fov_horizontal;
      u_fov_horizontal.real = this->fov_horizontal;
      *(outbuffer + offset + 0) = (u_fov_horizontal.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fov_horizontal.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fov_horizontal.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fov_horizontal.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fov_horizontal);
      union {
        float real;
        uint32_t base;
      } u_fov_vertical;
      u_fov_vertical.real = this->fov_vertical;
      *(outbuffer + offset + 0) = (u_fov_vertical.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fov_vertical.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fov_vertical.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fov_vertical.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fov_vertical);
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset++) = markers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance_min;
      u_distance_min.base = 0;
      u_distance_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_min = u_distance_min.real;
      offset += sizeof(this->distance_min);
      union {
        float real;
        uint32_t base;
      } u_distance_max;
      u_distance_max.base = 0;
      u_distance_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_max = u_distance_max.real;
      offset += sizeof(this->distance_max);
      union {
        float real;
        uint32_t base;
      } u_distance_max_id;
      u_distance_max_id.base = 0;
      u_distance_max_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_max_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_max_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_max_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_max_id = u_distance_max_id.real;
      offset += sizeof(this->distance_max_id);
      offset += this->view_direction.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_fov_horizontal;
      u_fov_horizontal.base = 0;
      u_fov_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fov_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fov_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fov_horizontal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fov_horizontal = u_fov_horizontal.real;
      offset += sizeof(this->fov_horizontal);
      union {
        float real;
        uint32_t base;
      } u_fov_vertical;
      u_fov_vertical.base = 0;
      u_fov_vertical.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fov_vertical.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fov_vertical.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fov_vertical.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fov_vertical = u_fov_vertical.real;
      offset += sizeof(this->fov_vertical);
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint8_t markers_lengthT = *(inbuffer + offset++);
      if(markers_lengthT > markers_length)
        this->markers = (marker_msgs::Marker*)realloc(this->markers, markers_lengthT * sizeof(marker_msgs::Marker));
      offset += 3;
      markers_length = markers_lengthT;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(marker_msgs::Marker));
      }
     return offset;
    }

    const char * getType(){ return "marker_msgs/MarkerDetection"; };
    const char * getMD5(){ return "b17d48b7aeec842456674ad3657d85fc"; };

  };

}
#endif