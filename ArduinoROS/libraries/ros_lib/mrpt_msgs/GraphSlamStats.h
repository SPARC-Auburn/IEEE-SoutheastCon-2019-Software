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
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _nodes_total_type;
      _nodes_total_type nodes_total;
      typedef int32_t _edges_total_type;
      _edges_total_type edges_total;
      typedef int32_t _edges_ICP2D_type;
      _edges_ICP2D_type edges_ICP2D;
      typedef int32_t _edges_ICP3D_type;
      _edges_ICP3D_type edges_ICP3D;
      typedef int32_t _edges_odom_type;
      _edges_odom_type edges_odom;
      typedef int32_t _loop_closures_type;
      _loop_closures_type loop_closures;
      uint32_t slam_evaluation_metric_length;
      typedef float _slam_evaluation_metric_type;
      _slam_evaluation_metric_type st_slam_evaluation_metric;
      _slam_evaluation_metric_type * slam_evaluation_metric;

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
      *(outbuffer + offset + 0) = (this->slam_evaluation_metric_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->slam_evaluation_metric_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->slam_evaluation_metric_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->slam_evaluation_metric_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->slam_evaluation_metric_length);
      for( uint32_t i = 0; i < slam_evaluation_metric_length; i++){
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
      uint32_t slam_evaluation_metric_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      slam_evaluation_metric_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      slam_evaluation_metric_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      slam_evaluation_metric_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->slam_evaluation_metric_length);
      if(slam_evaluation_metric_lengthT > slam_evaluation_metric_length)
        this->slam_evaluation_metric = (float*)realloc(this->slam_evaluation_metric, slam_evaluation_metric_lengthT * sizeof(float));
      slam_evaluation_metric_length = slam_evaluation_metric_lengthT;
      for( uint32_t i = 0; i < slam_evaluation_metric_length; i++){
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