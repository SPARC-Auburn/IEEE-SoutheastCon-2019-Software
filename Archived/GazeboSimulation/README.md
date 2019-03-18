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

The Raspberry Pi runs best with Raspbian Linux.  If you are developing on another machine, we recommend using Ubuntu Linux as either a virtual machine.

### Vision Recognition

We are using Open CV (C++ variant) for image processing.

### Simulation

We are using [Gazebo](http://gazebosim.org/) to simulate the robot to test code, mechanical design, and algorithmic strategy.  We recommend using Ubuntu prefably on a desktop or laptop that is more powerful than a Raspberry Pi (prefably Intel Core i5 equivalent or better).

* Install Gazebo on Ubuntu: `curl -ssL http://get.gazebosim.org | sh`
* Edit .bashrc file: `nano ~/.bashrc`
* Add environmental variables to bottom of file (replace "username" with your username):
```
export GAZEBO_MODEL_PATH="${GAZEBO_MODEL_PATH}:/home/username/IEEE-SoutheastCon-2019/Electrical-Software/GazeboSimulation/models"
export GAZEBO_PLUGIN_PATH="${GAZEBO_PLUGIN_PATH}:/home/username/IEEE-SoutheastCon-2019/Electrical-Software/GazeboSimulation/plugins/build"
```
* Press CRTL + X and Enter to save the file.
* Change directory into repository.  For example: `cd ~/IEEE-SoutheastCon-2019/Electrical-Software/GazeboSimulation/`
* Type the following commands
```
mkdir plugins/build
cd plugins/build
cmake ../
make
```
* Change directory into world directory and start server:
```
cd ~/IEEE-SoutheastCon-2019/Electrical-Software/GazeboSimulation/world
gzserver --verbose world.sdf
```
* Open up another terminal (CRTL-ALT-T) and type: `gzclient --verbose`
