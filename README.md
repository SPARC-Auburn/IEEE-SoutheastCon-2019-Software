# Electrical-Software Documentation

Electrical software development focused on writing software to simulate and run the robot.

## Contributing Guide

### Working with Git Repository (Using Git Bash or Linux Bash)

* Change directory into desired location for repository.  For example `cd ~`
* Clone repository `git clone https://gitlab.com/SPARC-Auburn/IEEE-SoutheastCon-2019.git`
* Type in username and password if required
* Make desired changes and add all files with `git add -A`
* Commit the changes with a brief descriptive message of what changed `git commit -m "Describe your commit briefly here"`
* Push your changes to the server `git push`
* If other people have committed since your latest push, pull the latest update from the server `git pull`

### Programming Language and IDE

The programming language we are choosing for this project is C++.  It is very popular for robotics applications due to its very defined syntax and speed as compared to Python.

### Operating System

We are using a version of the Debian Linux operating system Ubuntu 16.04, called Lubuntu.  The image from Ubiquity Robotics has a precompiled version of Robot Operating System (ROS).  If you are developing on another machine, we recommend using Ubuntu Linux.

### Vision Recognition

We are using Open CV (C++ variant) for image processing.  We are running OpenCV version 3.3.0.  You can check your version by running `pkg-config --modversion opencv`.  Install OpenCV on Raspberry Pi (2 or better): https://www.pyimagesearch.com/2017/09/04/raspbian-stretch-install-opencv-3-python-on-your-raspberry-pi/.  The camera being used is the Raspi-Camera V2.1.

### Control Software Suite

For the overall systems control software, we are using a framework called Robot Operating System (ROS).  We are using ROS  Kinetic 1.12.14.  Check your version with 
```
rosversion -d
rosversion roscpp
```

### Programs

* [Main-Program-1](Main-Program-1): The demo program for E-Day 2019 Demonstration.  This program uses OpenCV to extrapolate information of the debris objects.  It uses this information to turn towards the largest object and drive towards it.  Once it reaches it, it then turns right and goes towards the next object.  This configuration does not utilize ROS or localization.

*[Main-Program-2](Main-Program-2): This program is the next developmental step for the software utilizing full ROS with localization.