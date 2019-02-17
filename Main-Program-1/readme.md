# Track objects via Open CV and Raspberry Pi Camera and move robot towards debris

1. Install OpenCV on Raspberry Pi (2 or better): https://www.pyimagesearch.com/2017/09/04/raspbian-stretch-install-opencv-3-python-on-your-raspberry-pi/
1. Install Raspicam Library
    ```
    cd raspicam
    mkdir build
    cd build
    cmake ../
    make
    sudo make install
    sudo ldconfig
    cd ..
    cd ..
    ```
1. If using a Raspberry Pi Camera run (may need on reboot):
    ```
    sudo modprobe bcm2835-v4l2
    ```
1. Change directory to be in "Main-Program-1" folder.
1. Make "build" folder and open it in the terminal
    ```
    mkdir build
    cd build
    ```
1. Type the following commands to compile: 
    ```
    cmake ../
    make
    ```
1. Run program:
    ```
    ./MainProgram
    ```
1. To recompile and run again use
    ```
    cd build
    make
    ./MainProgram
    ```
