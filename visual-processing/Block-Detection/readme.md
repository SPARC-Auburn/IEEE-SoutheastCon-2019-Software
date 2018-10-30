# Track objects via Open CV and Raspberry Pi Camera

1. Install OpenCV on Raspberry Pi (2 or better): https://www.pyimagesearch.com/2017/09/04/raspbian-stretch-install-opencv-3-python-on-your-raspberry-pi/
1. Change directory to be in "Block-Detection" folder.
1. Type the following commands to setup environment: 
    ```
    source ~/.profile
    workon cv
    ```
1. If using a Raspberry Pi Camera:
    ```
    sudo modprobe bcm2835-v4l2
    ```
1. Run python program:
    ```
    python color-tracking.py
    ```
