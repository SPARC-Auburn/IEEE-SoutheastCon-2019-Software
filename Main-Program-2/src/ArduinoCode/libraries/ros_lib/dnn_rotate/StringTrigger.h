#ifndef _ROS_SERVICE_StringTrigger_h
#define _ROS_SERVICE_StringTrigger_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dnn_rotate
{

static const char STRINGTRIGGER[] = "dnn_rotate/StringTrigger";

  class StringTriggerRequest : public ros::Msg
  {
    public:
      const char* object;

    StringTriggerRequest():
      object("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_object = strlen(this->object);
      memcpy(outbuffer + offset, &length_object, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object, length_object);
      offset += length_object;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_object;
      memcpy(&length_object, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object-1]=0;
      this->object = (char *)(inbuffer + offset-1);
      offset += length_object;
     return offset;
    }

    const char * getType(){ return STRINGTRIGGER; };
    const char * getMD5(){ return "d32a80a49357522333ff3e758d0474bf"; };

  };

  class StringTriggerResponse : public ros::Msg
  {
    public:
      const char* response;

    StringTriggerResponse():
      response("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_response = strlen(this->response);
      memcpy(outbuffer + offset, &length_response, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->response, length_response);
      offset += length_response;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_response;
      memcpy(&length_response, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response-1]=0;
      this->response = (char *)(inbuffer + offset-1);
      offset += length_response;
     return offset;
    }

    const char * getType(){ return STRINGTRIGGER; };
    const char * getMD5(){ return "6de314e2dc76fbff2b6244a6ad70b68d"; };

  };

  class StringTrigger {
    public:
    typedef StringTriggerRequest Request;
    typedef StringTriggerResponse Response;
  };

}
#endif
