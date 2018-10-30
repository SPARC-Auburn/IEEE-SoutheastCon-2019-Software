find_package(Protobuf REQUIRED)

set (msgs scoreinfo.proto)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${msgs})
add_library(scoreinfomsgs SHARED ${PROTO_SRCS})
target_link_libraries(scoreinfomsgs ${PROTOBUF_LIBRARY})
