#ifndef _ROS_mrpt_msgs_NodeIDWithLaserScan_h
#define _ROS_mrpt_msgs_NodeIDWithLaserScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/LaserScan.h"

namespace mrpt_msgs
{

  class NodeIDWithLaserScan : public ros::Msg
  {
    public:
      uint64_t nodeID;
      sensor_msgs::LaserScan scan;

    NodeIDWithLaserScan():
      nodeID(0),
      scan()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID;
      u_nodeID.real = this->nodeID;
      *(outbuffer + offset + 0) = (u_nodeID.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nodeID.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nodeID.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nodeID.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodeID);
      offset += this->scan.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_nodeID;
      u_nodeID.base = 0;
      u_nodeID.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nodeID.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nodeID.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nodeID.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nodeID = u_nodeID.real;
      offset += sizeof(this->nodeID);
      offset += this->scan.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/NodeIDWithLaserScan"; };
    const char * getMD5(){ return "135d436b647c8470f71b2c97722a4352"; };

  };

}
#endif