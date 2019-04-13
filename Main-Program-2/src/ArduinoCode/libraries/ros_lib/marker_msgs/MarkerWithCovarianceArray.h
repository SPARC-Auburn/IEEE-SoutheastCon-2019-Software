#ifndef _ROS_marker_msgs_MarkerWithCovarianceArray_h
#define _ROS_marker_msgs_MarkerWithCovarianceArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "marker_msgs/MarkerWithCovariance.h"

namespace marker_msgs
{

  class MarkerWithCovarianceArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t markers_length;
      marker_msgs::MarkerWithCovariance st_markers;
      marker_msgs::MarkerWithCovariance * markers;

    MarkerWithCovarianceArray():
      header(),
      markers_length(0), markers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      uint8_t markers_lengthT = *(inbuffer + offset++);
      if(markers_lengthT > markers_length)
        this->markers = (marker_msgs::MarkerWithCovariance*)realloc(this->markers, markers_lengthT * sizeof(marker_msgs::MarkerWithCovariance));
      offset += 3;
      markers_length = markers_lengthT;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(marker_msgs::MarkerWithCovariance));
      }
     return offset;
    }

    const char * getType(){ return "marker_msgs/MarkerWithCovarianceArray"; };
    const char * getMD5(){ return "5b4524ee352826cec566891ecfc427c6"; };

  };

}
#endif