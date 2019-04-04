#ifndef _ROS_fiducial_msgs_FiducialMapEntryArray_h
#define _ROS_fiducial_msgs_FiducialMapEntryArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fiducial_msgs/FiducialMapEntry.h"

namespace fiducial_msgs
{

  class FiducialMapEntryArray : public ros::Msg
  {
    public:
      uint8_t fiducials_length;
      fiducial_msgs::FiducialMapEntry st_fiducials;
      fiducial_msgs::FiducialMapEntry * fiducials;

    FiducialMapEntryArray():
      fiducials_length(0), fiducials(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = fiducials_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fiducials_length; i++){
      offset += this->fiducials[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t fiducials_lengthT = *(inbuffer + offset++);
      if(fiducials_lengthT > fiducials_length)
        this->fiducials = (fiducial_msgs::FiducialMapEntry*)realloc(this->fiducials, fiducials_lengthT * sizeof(fiducial_msgs::FiducialMapEntry));
      offset += 3;
      fiducials_length = fiducials_lengthT;
      for( uint8_t i = 0; i < fiducials_length; i++){
      offset += this->st_fiducials.deserialize(inbuffer + offset);
        memcpy( &(this->fiducials[i]), &(this->st_fiducials), sizeof(fiducial_msgs::FiducialMapEntry));
      }
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/FiducialMapEntryArray"; };
    const char * getMD5(){ return "f3d7e1cb2717bda61be54acdb77f4f79"; };

  };

}
#endif