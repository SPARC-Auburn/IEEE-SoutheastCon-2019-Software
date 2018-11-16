#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <time.h>
#include <math.h>

#include "CYdLidar.h"
#include "timer.h"
#include <iostream>
#include <string>
#include <signal.h>
#include <memory>

//#include <unistd.h>
using namespace std;
using namespace cv;
using namespace ydlidar;
CYdLidar laser;
static bool running = false;

static void Stop(int signo)
{
    printf("Received exit signal\n");
    running = true;
}

int main(int argc, char * argv[])
{
    // Get setup info
	printf(" YDLIDAR C++ TEST\n");
    std::string port;
    std::string baudrate;
    std::string intensity;
    //printf("Please enter the lidar port:");
    //std::cin>>port;
    //printf("Please enter the lidar baud rate:");
    //std::cin>>baudrate;

    //printf("Please enter the lidar intensity:");
    //std::cin>>intensity;

    // Initialize and Setup Sensor
    //const int baud = atoi(baudrate.c_str());
    //bool intensities = atoi(intensity.c_str()) ==0?false:true;

    signal(SIGINT, Stop);
    signal(SIGTERM, Stop);
    laser.setSerialPort("/dev/ttyUSB0");
    laser.setSerialBaudrate(115200);
    laser.setIntensities(0);
    laser.setMaxRange(16.0);
    laser.setMinRange(0.1);
    laser.setMaxAngle(180);
    laser.setMinAngle(-180);
    laser.setHeartBeat(false);
    laser.setReversion(false);
    laser.setFixedResolution(false);
    laser.setAutoReconnect(true);
    laser.setEnableDebug(false);

    pose_info laser_pose;
    laser_pose.x = 0;
    laser_pose.y = 0;
    laser_pose.phi = 0;
    laser.setSensorPose(laser_pose);

    laser.initialize();
    uint64_t pre_time;

    Mat image = Mat::zeros( 1000, 1000, CV_8UC3 );   
    ofstream myfile;

    while(!running){
	bool hardError;
        LaserScan scan;
        LaserScan syncscan;
        PointCloud pc;
        std::vector<gline> lines;

        if(laser.doProcessSimple(scan, syncscan, pc, lines, hardError )){
            for(int i =0; i < scan.ranges.size(); i++ ){
                float angle = scan.config.min_angle + i*scan.config.ang_increment;
                float dis = scan.ranges[i];
            }
            fprintf(stdout,"min_angle: %f \n",scan.config.min_angle);
            fprintf(stdout,"max_angle: %f \n",scan.config.max_angle);
            fprintf(stdout,"scan frequency: %f HZ\n",1000000000.0/scan.config.scan_time);
            fprintf(stdout,"scan frequency: %f HZ\n",1000000000.0/(scan.self_time_stamp - pre_time));
	        pre_time = scan.self_time_stamp;

            fprintf(stdout,"Scan received: %u ranges\n",(unsigned int)scan.ranges.size());
            fprintf(stdout, "fit line size: %u \n", (unsigned int)lines.size());
            fprintf(stdout, "points size: %u \n", (unsigned int)pc.points.size());
            image = Mat::zeros( 1000, 1000, CV_8UC3 ); 
            int maxRange = 4; // max distance allowed from lidar
            cv::circle(image, Point(500,500), 1, Scalar(220, 220, 220 ),  1, 8);
            cv::circle(image, Point(500,500), 499, Scalar(220, 220, 220),  1, 8);
	    myfile.open ("data.txt");
            for(std::vector<point_info>::const_iterator it = pc.points.begin(); it != pc.points.end(); it++) {
                //fprintf(stdout, "x: %f,  y: %f, z: %f\n", (*it).x, (*it).y, (*it).z); 
		myfile <<  (*it).x << "," << (*it).y << "\n";
                double distance = sqrt((((*it).x)*((*it).x))+(((*it).y)*((*it).y)));              
                if (distance <= maxRange && distance > 0){
                    int picx = (*it).x*125+500;
                    int picy = (*it).y*(-125)+500;
                    cv::circle(image, Point(picx,picy), 1, Scalar(0, 220, 0 ),  1, 8);
                }                
             }
	    myfile <<  "----\n";
	    myfile.close();
            imshow("Image",image);
            // Press  ESC on keyboard to exit
            char c=(char)waitKey(25);
            if(c==27)
                break;
            //for(std::vector<gline>::const_iterator it = lines.begin(); it != lines.end(); it++) {
             //   fprintf(stdout, "line length: %f,   line angle: %f\n", (*it).distance, (*it).angle*180/3.14159);  
            //}
            
            fflush(stdout);
		}

        {
            odom_info odom;
            odom.x = 0;
            odom.y = 0;
            odom.phi = 0;
            odom.stamp = getTime();
            laser.setSyncOdometry(odom);
        }
	}
    destroyAllWindows();
    laser.turnOff();
    laser.disconnecting();
    return 0;
}

