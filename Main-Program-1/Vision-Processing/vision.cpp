/*------------------------------------------------------------------------------
Filename:     vision.cpp
Project:      IEEE SoutheastCon Hardware Competition 2019
School:       Auburn University
Organization: Student Projects and Research Committee (SPARC)
Description:  Takes pictures on the Raspberry Pi Camera V2 and processes them
with OpenCV2 via color recognition.

Color Indices = Red(0), Blue(1), Yellow(2), Green(3)
------------------------------------------------------------------------------*/
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

// Constants
#define PI 3.14159265
#define MIN_AREA 200
#define MAX_AREA 30000
#define VISION_DEBUG_IMAGE 1
#define VISION_DEBUG_COLOR_IMAGE -1 // -1 to disable (0 red,1 blue,2 yellow,3 green)
#define VISION_DEBUG_TEXT 0
#define DEBRIS_MIN_W2H 0.75
#define DEBRIS_MAX_W2H 1.5
#define DEBRIS_MIN_PERCENT_FILLED 0.65
#define DISTANCE_MULTIPLIER 26.95

// Namespaces
using namespace cv;
using namespace std;
namespace IEEE_VISION
{
struct DebrisObject
{
	Point center;
	int width;
	int height;
	int colorIndex;
	int angle;
	double distance;

	DebrisObject(Rect boundingRect, int new_colorIndex, int new_angle, double new_distance)
	{
		center.x = boundingRect.x + boundingRect.width / 2;
		center.y = boundingRect.y + boundingRect.height / 2;
		width = boundingRect.width;
		height = boundingRect.height;
		colorIndex = new_colorIndex;
		angle = new_angle;
		distance = new_distance;
	}
	void printProperties()
	{
		cout << "X=" << center.x << " Y=" << center.y << " Width=" << width << " Height=" << height << " colorIndex=" << colorIndex 
		<< " angle=" << angle << " distance=" << distance << "\n";
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
	clock_t begin;
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
			throw std::runtime_error("Error opening the camera");
		}
	}
	~VisionHandle()
	{
		Camera.release();
	}

	// Returns the index of the most occurring debris color visible
	int indexDebrisColors()
	{
		takePicture();
		objectProperties.clear();
		for (int i = 0; i < 4; i++)
		{
			getObjectProperties(i);
		}
		int mostOccurringIndex = findMostOccuringColor();
		if (VISION_DEBUG_TEXT)
			if (objectProperties.size() > 0)
				cout << "Out of " << objectProperties.size() << " objects, " << labels[mostOccurringIndex] << " are the most common.\n";
			else
				cout << "No objects detected\n";
		//displayImage("image window");	
		return mostOccurringIndex;
	}

	// Returns the angle to the largest debris object in view
	int angle2LargestDebris(int colorIndex)
	{
		takePicture();
		objectProperties.clear();
		getObjectProperties(colorIndex);
		if (VISION_DEBUG_TEXT)
			cout << "Number of objects = " << objectProperties.size() << endl;
		// ---- Find angle to largest debris in view ----
		if (objectProperties.size() > 0)
		{
			int largestDebris = findLargestObject();
			if (VISION_DEBUG_IMAGE)
			{
				line(image, Point(image.cols / 2, image.rows), Point(objectProperties[largestDebris].center.x, objectProperties[largestDebris].center.y), colors[objectProperties[largestDebris].colorIndex], 4, 8, 0); // draw line from bottom center of image to center of object
				line(image, Point(image.cols / 2, image.rows), Point(image.cols / 2, 0), Scalar(256, 256, 256), 4, 8, 0);
			}
			if (VISION_DEBUG_TEXT)
			{
				clock_t end = clock();
				double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
				double frequency = 1 / elapsed_secs;
				cout << "Elapsed Time = " << elapsed_secs << "s, Frequency = " << frequency << "Hz \n";
			}
			displayImage("image window");
			cout << "Distance = " << objectProperties[largestDebris].distance << "\n";
			return int(objectProperties[largestDebris].angle);
		}
		else // No Objects found
		{
			if (VISION_DEBUG_TEXT){
				clock_t end = clock();
				double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
				double frequency = 1 / elapsed_secs;
				cout << "Elapsed Time = " << elapsed_secs << "s, Frequency = " << frequency << "Hz \n";
			}
			displayImage("image window");			
			return 0; //no object detected angle
		}
	}

	// Takes a picture, flips it, saves it in image, and converts it to HSV
	void takePicture()
	{
		if (VISION_DEBUG_TEXT)
			begin = clock();
			cout << "getting picture..." << endl;
		Camera.grab();
		Camera.retrieve(image);
		//Camera.retrieve(temp);
		//flip(temp, image, -1); // flip the image 180 degrees
		cvtColor(image, hsv, COLOR_BGR2HSV);
		resolution = image.size();
	}

	// Populates vector array of object's properties
	void getObjectProperties(int index)
	{
		int numObjects = 0;
		double area, angle, w2h, percentFilled, distance;
		// Generate contours
		contours.clear();
		hierarchy.clear();
		clock_t begin = clock();
		inRange(hsv, lowerThreshes[index], upperThreshes[index], threshed);
		dilate(threshed, threshed, kernel);
		findContours(threshed, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
		if (VISION_DEBUG_TEXT)
			cout << double(clock() - begin) / CLOCKS_PER_SEC << endl;		
		if (index == VISION_DEBUG_COLOR_IMAGE) // ---- Show window of select color ----
		{
			namedWindow(labels[index], WINDOW_NORMAL); // Create a window for display.
			imshow(labels[index], threshed);		   // Show our image inside it.
			waitKey(1);
		}
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
				w2h = (double)boundRect.width / boundRect.height;					 // Find width to height ratio, 1.0 is square
				percentFilled = area / (double)(boundRect.width * boundRect.height); // amount of rectangle consumed by contour
				// Determine shape
				if (w2h > DEBRIS_MAX_W2H || w2h < DEBRIS_MIN_W2H) // wrong size ratio
				{
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), Scalar(100, 100, 100), 4, 8, 0);
				}
				else if (percentFilled < DEBRIS_MIN_PERCENT_FILLED)
				{
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), Scalar(200, 200, 200), 4, 8, 0);
				}
				else
				{
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), colors[index], 4, 8, 0);
					angle = atan((double)(boundRect.x - image.cols / 2) / (double)(image.rows - boundRect.y)) * 180 / PI; // Find angle to center of object from centerline
					distance = (1/(double)boundRect.width) * DISTANCE_MULTIPLIER;
					objectProperties.push_back(DebrisObject(boundRect, index, angle, distance));
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

	int findMostOccuringColor()
	{
		int colorOccurrences[4] = {0,0,0,0};
		int index = 0;
		int mostOccurrences = 0;
		int mostOccurringIndex = 0;
		for (int i = 0; i < objectProperties.size(); i++)
		{
			index = objectProperties[i].colorIndex;
			if (index < 4)
			{
				colorOccurrences[index] += 1;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (colorOccurrences[i] > mostOccurrences)
			{
				mostOccurringIndex = i;
				mostOccurrences += 1;
			}
		}
		return mostOccurringIndex;
	}

	// displays image if enabled
	void displayImage(string label)
	{
		if (VISION_DEBUG_IMAGE)
			{
				//imwrite("Test.jpg",image);
				imshow(label, image); // Show our image inside it.
				waitKey(1);			// Wait for a keystroke in the window
			}
	}
};
}; // namespace IEEE_VISION
