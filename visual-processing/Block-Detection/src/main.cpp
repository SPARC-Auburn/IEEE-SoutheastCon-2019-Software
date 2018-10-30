#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <time.h> 

const int MIN_AREA = 300;

using namespace cv;
using namespace std;


int main() {
	cout << CV_VERSION << endl;
	//VideoCapture cap(0);
	cv::Mat image;
  	image = cv::imread("sample.jpeg" , CV_LOAD_IMAGE_COLOR);
	Mat image,hsv,threshed;
	double area;
	int sz;
	Scalar lowerThreshes[] = {Scalar(120, 87, 60),Scalar(80, 100, 75),Scalar(22, 130, 200),Scalar(40, 70, 80)};
	Scalar upperThreshes[] = {Scalar(180, 255, 255),Scalar(110, 255, 255),Scalar(55, 255, 255),Scalar(80, 255, 255)};
	Scalar colors[] = {Scalar(0,0,255),Scalar(255,0,0),Scalar(0,255,255),Scalar(0,255,0)};
	String labels[] = {"Red","Blue","Yellow","Green"};
	Mat kernel = getStructuringElement(MORPH_ELLIPSE,Size(5,5));
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	
	double seconds = time(NULL);
	int frames = 0;
	int answer;
	Mat temp; image.read(temp);
	Size resolution = temp.size();
	while(1){
		cap.read(image);
		cvtColor(image, hsv, COLOR_BGR2HSV);

		for(int index = 0; index < 4; index++){
			contours.clear();
			hierarchy.clear();
			inRange(hsv,lowerThreshes[index],upperThreshes[index],threshed);
			dilate(threshed,threshed,kernel);
			findContours(threshed,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
			sz = contours.size();
			for (int contourIdx = 0; contourIdx < sz; contourIdx++){
				area = contourArea(contours.at(contourIdx));
				if(area > MIN_AREA){
					drawContours(image,contours,contourIdx,colors[index],3);
				}
			}
		}
		frames += 1;
		putText(image,to_string((int)round(frames/(time(NULL)-seconds))),Point(0,resolution.height),FONT_HERSHEY_SIMPLEX,2,Scalar(0,0,0),2);
		imshow("test",image);
		answer = waitKey(1);
		if (answer == 'q'){
			cap.release();
			destroyAllWindows();
			return 0;
		}
		else if(answer == 'r'){
			frames = 0;
			cout << "Frame rate reset" << endl;
			seconds = time(NULL);
		}
		//inRange()


	}
	std::cout << "Hello Easy C++ project!" << std::endl;
}
