;; Auto-generated. Do not edit!


(when (boundp 'opencv_node::vision_msg)
  (if (not (find-package "OPENCV_NODE"))
    (make-package "OPENCV_NODE"))
  (shadow 'vision_msg (find-package "OPENCV_NODE")))
(unless (find-package "OPENCV_NODE::VISION_MSG")
  (make-package "OPENCV_NODE::VISION_MSG"))

(in-package "ROS")
;;//! \htmlinclude vision_msg.msg.html


(defclass opencv_node::vision_msg
  :super ros::object
  :slots (_objects ))

(defmethod opencv_node::vision_msg
  (:init
   (&key
    ((:objects __objects) (let (r) (dotimes (i 0) (push (instance opencv_node::object :init) r)) r))
    )
   (send-super :init)
   (setq _objects __objects)
   self)
  (:objects
   (&rest __objects)
   (if (keywordp (car __objects))
       (send* _objects __objects)
     (progn
       (if __objects (setq _objects (car __objects)))
       _objects)))
  (:serialization-length
   ()
   (+
    ;; opencv_node/object[] _objects
    (apply #'+ (send-all _objects :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; opencv_node/object[] _objects
     (write-long (length _objects) s)
     (dolist (elem _objects)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; opencv_node/object[] _objects
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _objects (let (r) (dotimes (i n) (push (instance opencv_node::object :init) r)) r))
     (dolist (elem- _objects)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get opencv_node::vision_msg :md5sum-) "5abfddaa0c41b9448d210310355541e0")
(setf (get opencv_node::vision_msg :datatype-) "opencv_node/vision_msg")
(setf (get opencv_node::vision_msg :definition-)
      "object[] objects
================================================================================
MSG: opencv_node/object
uint32 x_position
uint32 y_position
uint32 width
uint32 height
float32 distance
uint8 color_index
uint8 object_type

")



(provide :opencv_node/vision_msg "5abfddaa0c41b9448d210310355541e0")


