#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <raspicam/raspicam_cv.h>
#include <time.h>
#include <ctime>
#include <math.h>

const int MIN_AREA = 4000;
const int MAX_AREA = 100000;
#define PI 3.14159265
#define VISION_DEBUG_IMAGE 0
#define VISION_DEBUG_TEXT 1
using namespace cv;
using namespace std;
namespace IEEE_VISION{
	struct VisionHandle{
		raspicam::RaspiCam_Cv Camera;
		Mat image,hsv,threshed;
		private:
			vector<vector<Point>> contours;
			vector<Vec4i> hierarchy;
			Mat temp;
			Scalar lowerThreshes[] = {Scalar(0, 100, 20), Scalar(95, 100, 20), Scalar(15, 100, 20), Scalar(45, 100, 20)};
			Scalar upperThreshes[] = {Scalar(15, 255, 255), Scalar(110, 256, 256), Scalar(35, 256, 256), Scalar(60, 256, 256)};
			Scalar colors[] = {Scalar(0, 0, 255), Scalar(255, 0, 0), Scalar(0, 255, 255), Scalar(0, 255, 0)};
			String labels[] = {"Red", "Blue", "Yellow", "Green"};
			Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
			Size resolution;
			vector<vector<Point>> contours_poly;
			vector<Rect> boundRect;
			vector<Point2f> center;
			vector<float> radius;
			vector<DebrisObject> objectProperties;
		public:
		VisionHandle(){
			Camera.set( CV_CPU_POPCNT, CV_8UC3);
			if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return;}
			Camera.grab();
		}
		~VisionHandle(){
			Camera.release();
		}
		int proc(){
			clock_t begin = clock();
			takePicture();
			cvtColor(image, hsv, COLOR_BGR2HSV);
			resolution = image.size();
			objectProperties.clear();
			for(int i = 0; i < 4; i++){
				getObjectProperties(i);
			}
			if(VISION_DEBUG_TEXT)
			cout << "Number of objects = " << objectProperties.size() << endl;
			// Find angle to largest debris in view
			if (debris.size()>0){
				
				int largestDebris = findLargestObject(debris);
				if(VISION_DEBUG_IMAGE){
					line(image, Point(image.cols/2,image.rows), Point(debris[largestDebris].x,debris[largestDebris].y), colors[debris[largestDebris].colorIndex], 4, 8, 0); // draw line from bottom center of image to center of object	
					line(image, Point(image.cols/2,image.rows), Point(image.cols/2,0), Scalar(256, 256, 256), 4, 8, 0);
				}
				//namedWindow("Display window", WINDOW_NORMAL); // Create a window for display.
				//imshow("Display window", image);			  // Show our image inside it.
				//waitKey(1);									  // Wait for a keystroke in the window
				divided_result = (float)(debris[largestDebris].x - image.cols/2)/(float)(image.rows - debris[largestDebris].y);
				angle = atan(divided_result)* 180 / PI; // Find angle to center of object from centerline
				if(VISION_DEBUG_TEXT){
					clock_t end = clock();
					double elapsed_secs = double(end-begin)/ CLOCKS_PER_SEC;
					double frequency = 1/elapsed_secs;
					cout << "Elapsed Time = " << elapsed_secs << "s, Frequency = " << frequency << "Hz \n";
				}	
				return int(angle);
			}
			else if(VISION_DEBUG_TEXT){
				clock_t end = clock();
				double elapsed_secs = double(end-begin)/ CLOCKS_PER_SEC;
				double frequency = 1/elapsed_secs;
				cout << "Elapsed Time = " << elapsed_secs << "s, Frequency = " << frequency << "Hz \n";	
				return 0; //no object detected angle
			}	
		}
		void takePicture(){
			Camera.retrieve(temp);
			flip(temp,image,-1);
		}
		// Returns vector array of object's x,y,width,height, and color properties 
		// for an image and colorIndex (0 Red, 1 Blue, 2 Yellow, 3 Green) 
		void getObjectProperties(const int &index){	
			int numObjects = 0;
			double area, angle, w2h, percentFilled;
			// Generate contours
			contours.clear();
			hierarchy.clear();
			inRange(hsv, lowerThreshes[index], upperThreshes[index], threshed);
			dilate(threshed, threshed, kernel);
			findContours(threshed, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

			// Show window of each color
			//namedWindow(labels[index], WINDOW_NORMAL); // Create a window for display.
			//imshow(labels[index], threshed);			  // Show our image inside it.
			//waitKey(1);		
			// Declare variables
			contours_poly.clear();
			contours_poly.reserve(contours.size());
			boundRect.clear();
			boundRect.reserve(contours.size());
			center.clear();
			center.reserve(contours.size());
			radius.clear();
			radius.reserve(contours.size());
			objectProperties.reserve(objectProperties.size()+contours.size());
			
			// Loop through each contour
			for (int i = 0; i < contours.size(); i++)
			{
				area = contourArea(contours[i]);
				if (area > MIN_AREA)
				{
					numObjects++;
					approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);  // Find best rectangle
					boundRect[i] = boundingRect(Mat(contours_poly[i]));
					minEnclosingCircle((Mat)contours_poly[i], center[i], radius[i]); // Find best circle
					//drawContours(image, contours_poly, i, colors[index], 1, 8, vector<Vec4i>(), 0, Point());  // draw contour around object
					//putText(image, to_string(numObjects), boundRect[i].tl(), FONT_HERSHEY_PLAIN, 8, colors[index], 3, true); // mark object number
					//angle = atan((center[i].x - image.cols/2)/(image.rows - center[i].y))* 180 / PI; // Find angle to center of object from centerline
					w2h = (double)boundRect[i].size().width/boundRect[i].size().height; // Find width to height ratio, 100 is square
					percentFilled = area/(double)(boundRect[i].size().width*boundRect[i].size().height); // amount of rectangle consumed by contour

					// Determine shape
					if (w2h > 1.50 || w2h < 0.75) // wrong size ratio
					{
						if(VISION_DEBUG_IMAGE)
						rectangle(image, boundRect[i].tl(), boundRect[i].br(), Scalar(100, 100, 100), 4, 8, 0);
						//cout << setprecision(2) << numObjects << ". " << setprecision(4) << labels[index] << " W2H Error! \t@ " << center[i] << "\t" << setprecision(3) << " \tw/ width " << boundRect[i].size().width << " \tand height " << boundRect[i].size().height << "\t w2h ratio " << w2h << "\n";
					}
					else if (percentFilled < 0.65)
					{
						if(VISION_DEBUG_IMAGE)
						rectangle(image, boundRect[i].tl(), boundRect[i].br(), Scalar(200, 200, 200), 4, 8, 0);
						//cout << setprecision(2) << numObjects << ". " << setprecision(4) << labels[index] << " Fill Error! \t@ " << center[i] << "\t" << setprecision(3) << " \tw/ width " << boundRect[i].size().width << " \tand height " << boundRect[i].size().height << "\t percent filled " << percentFilled << "\n";
					}
					else if (radius[i] * 1.80 > boundRect[i].size().width) // must be block
					{					
						if(VISION_DEBUG_IMAGE)
						rectangle(image, boundRect[i].tl(), boundRect[i].br(), colors[index], 4, 8, 0);
						//cout << setprecision(2) << numObjects << ". " << setprecision(4) << labels[index] << " blck \t@ " << center[i] << "\t" << setprecision(3) << angle  << " degrees" << " \tw/ width " << boundRect[i].size().width << " \tand height " << boundRect[i].size().height << "\n";
						objectProperties.push_back(DebrisObject(int(center[i].x),int(center[i].y),int(boundRect[i].size().width),int(boundRect[i].size().height),index));
						//if (boundRect[i].size().width > largestWidth){
						//	largestWidth = boundRect[i].size().width;
						//	largestWidthAngle = angle;
						//	line(image, Point(image.cols/2,image.rows), center[i], colors[index], 4, 8, 0); // draw line from bottom center of image to center of object
						//}
					}
					else // must be ball
					{
						if(VISION_DEBUG_IMAGE)
						circle(image, center[i], (int)radius[i], colors[index], 4, 8, 0);
						//cout << setprecision(2) << numObjects << ". " << setprecision(4) << labels[index] << " ball \t@ " << center[i] << "\t" << setprecision(3)  << angle << " degrees" << " \tw/ radius " << radius[i] << "\n";
						objectProperties.push_back(DebrisObject(int(center[i].x),int(center[i].y),int(boundRect[i].size().width),int(boundRect[i].size().height),index));
						//if (boundRect[i].size().width > largestWidth){
						//	largestWidth = boundRect[i].size().width;
						//	largestWidthAngle = angle;
						//	line(image, Point(image.cols/2,image.rows), center[i], colors[index], 4, 8, 0); // draw line from bottom center of image to center of object
						//}
					}
					
				}
				
			}
		}
		// returns the index of the largest object
		int findLargestObject(vector<DebrisObject> objects){
			int largestArea = 0;
			int area = 0;
			int objectIndex = 0;
			for (int i = 0; i < objects.size(); i++){
				area = objects[i].width*objects[i].height;
				if (area >= largestArea){
					largestArea = area;
					objectIndex = i;
				}
			}
			return objectIndex;
		}
		struct DebrisObject{
			int x;
			int y;
			int width;
			int height;
			int colorIndex;	
			DebrisObject(){
				x = 0;
				y = 0;
				width = 0;
				height = 0;
				colorIndex = 0;
			}	
			DebrisObject(int new_x, int new_y, int new_width, int new_height, int new_colorIndex){
				x = new_x;
				y = new_y;
				width = new_width;
				height = new_height;
				colorIndex = new_colorIndex;
			}	
			void printProperties(){
				cout << "X="<<x<<" Y="<<y<<" Width="<<width<<" Height="<<height<<" colorIndex="<<colorIndex<<"\n"; 
			}
		};
	};


};