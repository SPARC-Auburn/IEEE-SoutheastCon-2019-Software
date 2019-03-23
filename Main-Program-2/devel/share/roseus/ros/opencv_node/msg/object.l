;; Auto-generated. Do not edit!


(when (boundp 'opencv_node::object)
  (if (not (find-package "OPENCV_NODE"))
    (make-package "OPENCV_NODE"))
  (shadow 'object (find-package "OPENCV_NODE")))
(unless (find-package "OPENCV_NODE::OBJECT")
  (make-package "OPENCV_NODE::OBJECT"))

(in-package "ROS")
;;//! \htmlinclude object.msg.html


(defclass opencv_node::object
  :super ros::object
  :slots (_x_position _y_position _width _height _distance _color_index _object_type ))

(defmethod opencv_node::object
  (:init
   (&key
    ((:x_position __x_position) 0)
    ((:y_position __y_position) 0)
    ((:width __width) 0)
    ((:height __height) 0)
    ((:distance __distance) 0.0)
    ((:color_index __color_index) 0)
    ((:object_type __object_type) 0)
    )
   (send-super :init)
   (setq _x_position (round __x_position))
   (setq _y_position (round __y_position))
   (setq _width (round __width))
   (setq _height (round __height))
   (setq _distance (float __distance))
   (setq _color_index (round __color_index))
   (setq _object_type (round __object_type))
   self)
  (:x_position
   (&optional __x_position)
   (if __x_position (setq _x_position __x_position)) _x_position)
  (:y_position
   (&optional __y_position)
   (if __y_position (setq _y_position __y_position)) _y_position)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:color_index
   (&optional __color_index)
   (if __color_index (setq _color_index __color_index)) _color_index)
  (:object_type
   (&optional __object_type)
   (if __object_type (setq _object_type __object_type)) _object_type)
  (:serialization-length
   ()
   (+
    ;; uint32 _x_position
    4
    ;; uint32 _y_position
    4
    ;; uint32 _width
    4
    ;; uint32 _height
    4
    ;; float32 _distance
    4
    ;; uint8 _color_index
    1
    ;; uint8 _object_type
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _x_position
       (write-long _x_position s)
     ;; uint32 _y_position
       (write-long _y_position s)
     ;; uint32 _width
       (write-long _width s)
     ;; uint32 _height
       (write-long _height s)
     ;; float32 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _color_index
       (write-byte _color_index s)
     ;; uint8 _object_type
       (write-byte _object_type s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _x_position
     (setq _x_position (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _y_position
     (setq _y_position (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _width
     (setq _width (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _height
     (setq _height (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _distance
     (setq _distance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _color_index
     (setq _color_index (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _object_type
     (setq _object_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get opencv_node::object :md5sum-) "2ffacbbb937a845333e840b126fe6a12")
(setf (get opencv_node::object :datatype-) "opencv_node/object")
(setf (get opencv_node::object :definition-)
      "uint32 x_position
uint32 y_position
uint32 width
uint32 height
float32 distance
uint8 color_index
uint8 object_type

")



(provide :opencv_node/object "2ffacbbb937a845333e840b126fe6a12")


