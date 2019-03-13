# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "opencv_node: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iopencv_node:/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Iopencv_node:/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(opencv_node_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg" NAME_WE)
add_custom_target(_opencv_node_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "opencv_node" "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(opencv_node
  "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_node
)

### Generating Services

### Generating Module File
_generate_module_cpp(opencv_node
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_node
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(opencv_node_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(opencv_node_generate_messages opencv_node_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg" NAME_WE)
add_dependencies(opencv_node_generate_messages_cpp _opencv_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_node_gencpp)
add_dependencies(opencv_node_gencpp opencv_node_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_node_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(opencv_node
  "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/opencv_node
)

### Generating Services

### Generating Module File
_generate_module_eus(opencv_node
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/opencv_node
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(opencv_node_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(opencv_node_generate_messages opencv_node_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg" NAME_WE)
add_dependencies(opencv_node_generate_messages_eus _opencv_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_node_geneus)
add_dependencies(opencv_node_geneus opencv_node_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_node_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(opencv_node
  "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_node
)

### Generating Services

### Generating Module File
_generate_module_lisp(opencv_node
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_node
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(opencv_node_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(opencv_node_generate_messages opencv_node_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg" NAME_WE)
add_dependencies(opencv_node_generate_messages_lisp _opencv_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_node_genlisp)
add_dependencies(opencv_node_genlisp opencv_node_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_node_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(opencv_node
  "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/opencv_node
)

### Generating Services

### Generating Module File
_generate_module_nodejs(opencv_node
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/opencv_node
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(opencv_node_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(opencv_node_generate_messages opencv_node_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg" NAME_WE)
add_dependencies(opencv_node_generate_messages_nodejs _opencv_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_node_gennodejs)
add_dependencies(opencv_node_gennodejs opencv_node_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_node_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(opencv_node
  "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node
)

### Generating Services

### Generating Module File
_generate_module_py(opencv_node
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(opencv_node_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(opencv_node_generate_messages opencv_node_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/matthew/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/msg/vision_msg.msg" NAME_WE)
add_dependencies(opencv_node_generate_messages_py _opencv_node_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(opencv_node_genpy)
add_dependencies(opencv_node_genpy opencv_node_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS opencv_node_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/opencv_node
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(opencv_node_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET opencv_node_generate_messages_cpp)
  add_dependencies(opencv_node_generate_messages_cpp opencv_node_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/opencv_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/opencv_node
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(opencv_node_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET opencv_node_generate_messages_eus)
  add_dependencies(opencv_node_generate_messages_eus opencv_node_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/opencv_node
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(opencv_node_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET opencv_node_generate_messages_lisp)
  add_dependencies(opencv_node_generate_messages_lisp opencv_node_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/opencv_node)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/opencv_node
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(opencv_node_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET opencv_node_generate_messages_nodejs)
  add_dependencies(opencv_node_generate_messages_nodejs opencv_node_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/opencv_node
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(opencv_node_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET opencv_node_generate_messages_py)
  add_dependencies(opencv_node_generate_messages_py opencv_node_generate_messages_py)
endif()
