; Auto-generated. Do not edit!


(cl:in-package opencv_node-msg)


;//! \htmlinclude vision_msg.msg.html

(cl:defclass <vision_msg> (roslisp-msg-protocol:ros-message)
  ((x_position
    :reader x_position
    :initarg :x_position
    :type cl:integer
    :initform 0)
   (y_position
    :reader y_position
    :initarg :y_position
    :type cl:integer
    :initform 0)
   (width
    :reader width
    :initarg :width
    :type cl:integer
    :initform 0)
   (height
    :reader height
    :initarg :height
    :type cl:integer
    :initform 0)
   (distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0)
   (color_index
    :reader color_index
    :initarg :color_index
    :type cl:fixnum
    :initform 0)
   (object_type
    :reader object_type
    :initarg :object_type
    :type cl:fixnum
    :initform 0))
)

(cl:defclass vision_msg (<vision_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <vision_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'vision_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name opencv_node-msg:<vision_msg> is deprecated: use opencv_node-msg:vision_msg instead.")))

(cl:ensure-generic-function 'x_position-val :lambda-list '(m))
(cl:defmethod x_position-val ((m <vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_node-msg:x_position-val is deprecated.  Use opencv_node-msg:x_position instead.")
  (x_position m))

(cl:ensure-generic-function 'y_position-val :lambda-list '(m))
(cl:defmethod y_position-val ((m <vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_node-msg:y_position-val is deprecated.  Use opencv_node-msg:y_position instead.")
  (y_position m))

(cl:ensure-generic-function 'width-val :lambda-list '(m))
(cl:defmethod width-val ((m <vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_node-msg:width-val is deprecated.  Use opencv_node-msg:width instead.")
  (width m))

(cl:ensure-generic-function 'height-val :lambda-list '(m))
(cl:defmethod height-val ((m <vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_node-msg:height-val is deprecated.  Use opencv_node-msg:height instead.")
  (height m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_node-msg:distance-val is deprecated.  Use opencv_node-msg:distance instead.")
  (distance m))

(cl:ensure-generic-function 'color_index-val :lambda-list '(m))
(cl:defmethod color_index-val ((m <vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_node-msg:color_index-val is deprecated.  Use opencv_node-msg:color_index instead.")
  (color_index m))

(cl:ensure-generic-function 'object_type-val :lambda-list '(m))
(cl:defmethod object_type-val ((m <vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_node-msg:object_type-val is deprecated.  Use opencv_node-msg:object_type instead.")
  (object_type m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <vision_msg>) ostream)
  "Serializes a message object of type '<vision_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'x_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'x_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'x_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'x_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'y_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'y_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'y_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'y_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'height)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'color_index)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'object_type)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <vision_msg>) istream)
  "Deserializes a message object of type '<vision_msg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'x_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'x_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'x_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'x_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'y_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'y_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'y_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'y_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'color_index)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'object_type)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<vision_msg>)))
  "Returns string type for a message object of type '<vision_msg>"
  "opencv_node/vision_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'vision_msg)))
  "Returns string type for a message object of type 'vision_msg"
  "opencv_node/vision_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<vision_msg>)))
  "Returns md5sum for a message object of type '<vision_msg>"
  "2ffacbbb937a845333e840b126fe6a12")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'vision_msg)))
  "Returns md5sum for a message object of type 'vision_msg"
  "2ffacbbb937a845333e840b126fe6a12")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<vision_msg>)))
  "Returns full string definition for message of type '<vision_msg>"
  (cl:format cl:nil "uint32 x_position~%uint32 y_position~%uint32 width~%uint32 height~%float32 distance~%uint8 color_index~%uint8 object_type~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'vision_msg)))
  "Returns full string definition for message of type 'vision_msg"
  (cl:format cl:nil "uint32 x_position~%uint32 y_position~%uint32 width~%uint32 height~%float32 distance~%uint8 color_index~%uint8 object_type~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <vision_msg>))
  (cl:+ 0
     4
     4
     4
     4
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <vision_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'vision_msg
    (cl:cons ':x_position (x_position msg))
    (cl:cons ':y_position (y_position msg))
    (cl:cons ':width (width msg))
    (cl:cons ':height (height msg))
    (cl:cons ':distance (distance msg))
    (cl:cons ':color_index (color_index msg))
    (cl:cons ':object_type (object_type msg))
))
