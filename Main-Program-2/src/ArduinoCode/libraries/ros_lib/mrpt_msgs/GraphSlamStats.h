#ifndef _ROS_mrpt_msgs_GraphSlamStats_h
#define _ROS_mrpt_msgs_GraphSlamStats_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mrpt_msgs
{

  class GraphSlamStats : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t nodes_total;
      int32_t edges_total;
      int32_t edges_ICP2D;
      int32_t edges_ICP3D;
      int32_t edges_odom;
      int32_t loop_closures;
      uint8_t slam_evaluation_metric_length;
      float st_slam_evaluation_metric;
      float * slam_evaluation_metric;

    GraphSlamStats():
      header(),
      nodes_total(0),
      edges_total(0),
      edges_ICP2D(0),
      edges_ICP3D(0),
      edges_odom(0),
      loop_closures(0),
      slam_evaluation_metric_length(0), slam_evaluation_metric(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_nodes_total;
      u_nodes_total.real = this->nodes_total;
      *(outbuffer + offset + 0) = (u_nodes_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nodes_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nodes_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nodes_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodes_total);
      union {
        int32_t real;
        uint32_t base;
      } u_edges_total;
      u_edges_total.real = this->edges_total;
      *(outbuffer + offset + 0) = (u_edges_total.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_edges_total.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_edges_total.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_edges_total.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->edges_total);
      union {
        int32_t real;
        uint32_t base;
      } u_edges_ICP2D;
      u_edges_ICP2D.real = this->edges_ICP2D;
      *(outbuffer + offset + 0) = (u_edges_ICP2D.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_edges_ICP2D.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_edges_ICP2D.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_edges_ICP2D.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->edges_ICP2D);
      union {
        int32_t real;
        uint32_t base;
      } u_edges_ICP3D;
      u_edges_ICP3D.real = this->edges_ICP3D;
      *(outbuffer + offset + 0) = (u_edges_ICP3D.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_edges_ICP3D.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_edges_ICP3D.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_edges_ICP3D.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->edges_ICP3D);
      union {
        int32_t real;
        uint32_t base;
      } u_edges_odom;
      u_edges_odom.real = this->edges_odom;
      *(outbuffer + offset + 0) = (u_edges_odom.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_edges_odom.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_edges_odom.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_edges_odom.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->edges_odom);
      union {
        int32_t real;
        uint32_t base;
      } u_loop_closures;
      u_loop_closures.real = this->loop_closures;
      *(outbuffer + offset + 0) = (u_loop_closures.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_loop_closures.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_loop_closures.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_loop_closures.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loop_closures);
      *(outbuffer + offset++) = slam_evaluation_metric_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < slam_evaluation_metric_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->slam_evaluation_metric[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_nodes_total;
      u_nodes_total.base = 0;
      u_nodes_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nodes_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nodes_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nodes_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nodes_total = u_nodes_total.real;
      offset += sizeof(this->nodes_total);
      union {
        int32_t real;
        uint32_t base;
      } u_edges_total;
      u_edges_total.base = 0;
      u_edges_total.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_edges_total.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_edges_total.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_edges_total.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->edges_total = u_edges_total.real;
      offset += sizeof(this->edges_total);
      union {
        int32_t real;
        uint32_t base;
      } u_edges_ICP2D;
      u_edges_ICP2D.base = 0;
      u_edges_ICP2D.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_edges_ICP2D.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_edges_ICP2D.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_edges_ICP2D.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->edges_ICP2D = u_edges_ICP2D.real;
      offset += sizeof(this->edges_ICP2D);
      union {
        int32_t real;
        uint32_t base;
      } u_edges_ICP3D;
      u_edges_ICP3D.base = 0;
      u_edges_ICP3D.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_edges_ICP3D.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_edges_ICP3D.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_edges_ICP3D.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->edges_ICP3D = u_edges_ICP3D.real;
      offset += sizeof(this->edges_ICP3D);
      union {
        int32_t real;
        uint32_t base;
      } u_edges_odom;
      u_edges_odom.base = 0;
      u_edges_odom.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_edges_odom.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_edges_odom.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_edges_odom.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->edges_odom = u_edges_odom.real;
      offset += sizeof(this->edges_odom);
      union {
        int32_t real;
        uint32_t base;
      } u_loop_closures;
      u_loop_closures.base = 0;
      u_loop_closures.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_loop_closures.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_loop_closures.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_loop_closures.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->loop_closures = u_loop_closures.real;
      offset += sizeof(this->loop_closures);
      uint8_t slam_evaluation_metric_lengthT = *(inbuffer + offset++);
      if(slam_evaluation_metric_lengthT > slam_evaluation_metric_length)
        this->slam_evaluation_metric = (float*)realloc(this->slam_evaluation_metric, slam_evaluation_metric_lengthT * sizeof(float));
      offset += 3;
      slam_evaluation_metric_length = slam_evaluation_metric_lengthT;
      for( uint8_t i = 0; i < slam_evaluation_metric_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_slam_evaluation_metric));
        memcpy( &(this->slam_evaluation_metric[i]), &(this->st_slam_evaluation_metric), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/GraphSlamStats"; };
    const char * getMD5(){ return "eacf2f0450892c9d53ce9dcaa0385298"; };

  };

}
#endif