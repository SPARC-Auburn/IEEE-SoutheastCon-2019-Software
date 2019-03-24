; Auto-generated. Do not edit!


(cl:in-package opencv_node-msg)


;//! \htmlinclude vision_msg.msg.html

(cl:defclass <vision_msg> (roslisp-msg-protocol:ros-message)
  ((objects
    :reader objects
    :initarg :objects
    :type (cl:vector opencv_node-msg:object)
   :initform (cl:make-array 0 :element-type 'opencv_node-msg:object :initial-element (cl:make-instance 'opencv_node-msg:object))))
)

(cl:defclass vision_msg (<vision_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <vision_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'vision_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name opencv_node-msg:<vision_msg> is deprecated: use opencv_node-msg:vision_msg instead.")))

(cl:ensure-generic-function 'objects-val :lambda-list '(m))
(cl:defmethod objects-val ((m <vision_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader opencv_node-msg:objects-val is deprecated.  Use opencv_node-msg:objects instead.")
  (objects m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <vision_msg>) ostream)
  "Serializes a message object of type '<vision_msg>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'objects))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'objects))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <vision_msg>) istream)
  "Deserializes a message object of type '<vision_msg>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'objects) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'objects)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'opencv_node-msg:object))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
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
  "5abfddaa0c41b9448d210310355541e0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'vision_msg)))
  "Returns md5sum for a message object of type 'vision_msg"
  "5abfddaa0c41b9448d210310355541e0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<vision_msg>)))
  "Returns full string definition for message of type '<vision_msg>"
  (cl:format cl:nil "object[] objects~%================================================================================~%MSG: opencv_node/object~%uint32 x_position~%uint32 y_position~%uint32 width~%uint32 height~%float32 distance~%uint8 color_index~%uint8 object_type~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'vision_msg)))
  "Returns full string definition for message of type 'vision_msg"
  (cl:format cl:nil "object[] objects~%================================================================================~%MSG: opencv_node/object~%uint32 x_position~%uint32 y_position~%uint32 width~%uint32 height~%float32 distance~%uint8 color_index~%uint8 object_type~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <vision_msg>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'objects) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <vision_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'vision_msg
    (cl:cons ':objects (objects msg))
))
