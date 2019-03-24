
(cl:in-package :asdf)

(defsystem "opencv_node-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "object" :depends-on ("_package_object"))
    (:file "_package_object" :depends-on ("_package"))
    (:file "object" :depends-on ("_package_object"))
    (:file "_package_object" :depends-on ("_package"))
    (:file "vision_msg" :depends-on ("_package_vision_msg"))
    (:file "_package_vision_msg" :depends-on ("_package"))
    (:file "vision_msg" :depends-on ("_package_vision_msg"))
    (:file "_package_vision_msg" :depends-on ("_package"))
  ))