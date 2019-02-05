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

const int MIN_AREA = 200;
const int MAX_AREA = 30000;
#define PI 3.14159265
#define VISION_DEBUG_IMAGE 1
#define VISION_DEBUG_TEXT 0
using namespace cv;
using namespace std;
namespace IEEE_VISION
{
struct DebrisObject
{
	int x;
	int y;
	int width;
	int height;
	int colorIndex;
	DebrisObject()
	{
		x = 0;
		y = 0;
		width = 0;
		height = 0;
		colorIndex = 0;
	}
	DebrisObject(int new_x, int new_y, int new_width, int new_height, int new_colorIndex)
	{
		x = new_x;
		y = new_y;
		width = new_width;
		height = new_height;
		colorIndex = new_colorIndex;
	}
	void printProperties()
	{
		cout << "X=" << x << " Y=" << y << " Width=" << width << " Height=" << height << " colorIndex=" << colorIndex << "\n";
	}
};
struct VisionHandle
{
	raspicam::RaspiCam_Cv Camera;
	Mat image, hsv, threshed;

  private:
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	Mat temp;
	Scalar lowerThreshes[4] = {Scalar(0, 100, 20), Scalar(95, 100, 20), Scalar(15, 100, 20), Scalar(45, 100, 20)};
	Scalar upperThreshes[4] = {Scalar(15, 255, 255), Scalar(110, 256, 256), Scalar(35, 256, 256), Scalar(60, 256, 256)};
	Scalar colors[4] = {Scalar(0, 0, 255), Scalar(255, 0, 0), Scalar(0, 255, 255), Scalar(0, 255, 0)};
	String labels[4] = {"Red", "Blue", "Yellow", "Green"};
	Mat kernel = getStructuringElement(MORPH_CROSS, Size(3, 3));
	Size resolution;
	vector<Rect> boundRect;
	vector<DebrisObject> objectProperties;

  public:
	VisionHandle()
	{
		Camera.set(CV_CPU_POPCNT, CV_8UC3);
		Camera.set(CAP_PROP_FRAME_WIDTH, 640);
		Camera.set(CAP_PROP_FRAME_HEIGHT, 480);
		if (!Camera.open())
		{
			cerr << "Error opening the camera" << endl;
			return;
		}
	}
	~VisionHandle()
	{
		Camera.release();
	}
	int proc()
	{
		double divided_result, angle;
		clock_t begin = clock();
		takePicture();
		//if(VISION_DEBUG_TEXT)
		//	cout << "converting picture" << endl;
		cvtColor(image, hsv, COLOR_BGR2HSV);
		resolution = image.size();
		objectProperties.clear();
		if (VISION_DEBUG_TEXT)
			cout << "getting properties" << endl;
		for (int iii = 0; iii < 4; iii++)
		{
			getObjectProperties(iii);
		}
		if (VISION_DEBUG_TEXT)
			cout << "Number of objects = " << objectProperties.size() << endl;

		// ---- Find angle to largest debris in view ----
		if (objectProperties.size() > 0)
		{
			int largestDebris = findLargestObject();
			if (VISION_DEBUG_IMAGE)
			{
				line(image, Point(image.cols / 2, image.rows), Point(objectProperties[largestDebris].x, objectProperties[largestDebris].y), colors[objectProperties[largestDebris].colorIndex], 4, 8, 0); // draw line from bottom center of image to center of object
				line(image, Point(image.cols / 2, image.rows), Point(image.cols / 2, 0), Scalar(256, 256, 256), 4, 8, 0);
			}

			divided_result = (float)(objectProperties[largestDebris].x - image.cols / 2) / (float)(image.rows - objectProperties[largestDebris].y);
			angle = atan(divided_result) * 180 / PI; // Find angle to center of object from centerline
			if (VISION_DEBUG_TEXT)
			{
				clock_t end = clock();
				double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
				double frequency = 1 / elapsed_secs;
				cout << "Elapsed Time = " << elapsed_secs << "s, Frequency = " << frequency << "Hz \n";
			}
			if (VISION_DEBUG_IMAGE)
			{
				//imwrite("Test.jpg",image);
				imshow("a", image); // Show our image inside it.
				waitKey(1);			// Wait for a keystroke in the window
			}
			return int(angle);
		}
		else if (VISION_DEBUG_TEXT)
		{
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			double frequency = 1 / elapsed_secs;
			cout << "Elapsed Time = " << elapsed_secs << "s, Frequency = " << frequency << "Hz \n";
			if (VISION_DEBUG_IMAGE)
			{
				//imwrite("Test.jpg",image);
				imshow("a", image); // Show our image inside it.
				waitKey(1);			// Wait for a keystroke in the window
			}
			return 0; //no object detected angle
		}
		else
		{
			if (VISION_DEBUG_IMAGE)
			{
				//imwrite("Test.jpg",image);
				imshow("a", image); // Show our image inside it.
				waitKey(1);			// Wait for a keystroke in the window
			}
			return 0;
		}
	}

	// Takes a picture, flips it, and saves it in image
	void takePicture()
	{
		if (VISION_DEBUG_TEXT)
			cout << "getting picture" << endl;
		Camera.grab();
		Camera.retrieve(temp);
		flip(temp, image, -1);
	}

	// Returns vector array of object's x,y,width,height, and color properties
	// for an image and colorIndex (0 Red, 1 Blue, 2 Yellow, 3 Green)
	void getObjectProperties(int index)
	{
		int numObjects = 0;
		double area, angle, w2h, percentFilled;
		// Generate contours
		contours.clear();
		hierarchy.clear();
		clock_t begin = clock();
		inRange(hsv, lowerThreshes[index], upperThreshes[index], threshed);
		dilate(threshed, threshed, kernel);
		findContours(threshed, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
		if (VISION_DEBUG_TEXT)
			cout << double(clock() - begin) / CLOCKS_PER_SEC << endl;

		// ---- Show window of select color ----
		if (index == 5)
		{
			namedWindow(labels[index], WINDOW_NORMAL); // Create a window for display.
			imshow(labels[index], threshed);		   // Show our image inside it.
			waitKey(1);
		}

		//if(VISION_DEBUG_TEXT)
		//	cout << "Number of contours: " << contours.size() << endl;
		// ---- Loop through each contour ----
		for (int i = 0; i < contours.size(); i++)
		{
			area = contourArea(contours[i]);
			if (area > MIN_AREA && area < MAX_AREA)
			{
				numObjects++;
				Rect boundRect = boundingRect(contours[i]);
				float r;
				Point2f cent;
				w2h = (double)boundRect.width / boundRect.height;					 // Find width to height ratio, 100 is square
				percentFilled = area / (double)(boundRect.width * boundRect.height); // amount of rectangle consumed by contour
				// Determine shape
				if (w2h > 1.50 || w2h < 0.75) // wrong size ratio
				{
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), Scalar(100, 100, 100), 4, 8, 0);
				}
				else if (percentFilled < 0.65)
				{
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), Scalar(200, 200, 200), 4, 8, 0);
				}
				else
				{
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), colors[index], 4, 8, 0);
					objectProperties.push_back(DebrisObject(int(boundRect.x + boundRect.width / 2), int(boundRect.y + boundRect.height / 2), int(boundRect.width), int(boundRect.height), index));
				}
			}
		}
	}
	// returns the index of the largest object
	int findLargestObject()
	{
		int largestArea = 0;
		int area = 0;
		int objectIndex = 0;
		for (int i = 0; i < objectProperties.size(); i++)
		{
			area = objectProperties[i].width * objectProperties[i].height;
			if (area >= largestArea)
			{
				largestArea = area;
				objectIndex = i;
			}
		}
		return objectIndex;
	}
};

}; // namespace IEEE_VISION
