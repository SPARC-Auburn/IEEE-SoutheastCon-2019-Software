#ifndef _ROS_marker_msgs_MarkerStamped_h
#define _ROS_marker_msgs_MarkerStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "marker_msgs/Marker.h"

namespace marker_msgs
{

  class MarkerStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      marker_msgs::Marker marker;

    MarkerStamped():
      header(),
      marker()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->marker.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->marker.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "marker_msgs/MarkerStamped"; };
    const char * getMD5(){ return "4c1e18caf6e07b546965f552c7f69fcf"; };

  };

}
#endif