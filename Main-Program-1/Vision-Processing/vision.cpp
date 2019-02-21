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
#define CORNER_MIN_W2H .1
#define CORNER_MAX_W2H .333
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
	
	enum class ObjectType {
		Debris,
		Corner,
		CenterFace,
		Unknown
	} type;

	DebrisObject(Rect boundingRect, int new_colorIndex, int new_angle, double new_distance, ObjectType typeIn)
	{
		center.x = boundingRect.x + boundingRect.width / 2;
		center.y = boundingRect.y + boundingRect.height / 2;
		width = boundingRect.width;
		height = boundingRect.height;
		colorIndex = new_colorIndex;
		angle = new_angle;
		distance = new_distance;
		type = typeIn;
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

	// Returns the angle to the largest debris object in view. If the colorIndex is not given, the largest object of any color will be found.
	int angle2LargestDebris(int colorIndex = -1)
	{
		if (VISION_DEBUG_TEXT)
			cout << "Number of objects = " << objectProperties.size() << endl;
		// ---- Find angle to largest debris in view ----
		int largestDebris = findLargestObject(colorIndex);
		if (largestDebris != -1)
		{
			if (VISION_DEBUG_IMAGE)
			{
				line(image, Point(image.cols / 2, image.rows), objectProperties[largestDebris].center, colors[objectProperties[largestDebris].colorIndex], 4, 8, 0); // draw line from bottom center of image to center of object
				line(image, Point(image.cols / 2, image.rows), Point(image.cols / 2, 0), Scalar(256, 256, 256), 4, 8, 0);
			}
			if (VISION_DEBUG_TEXT)
			{
				clock_t end = clock();
				double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
				double frequency = 1 / elapsed_secs;
				cout << "Elapsed Time = " << elapsed_secs << "s, Frequency = " << frequency << "Hz \n";
				cout << "Distance = " << objectProperties[largestDebris].distance << "\n";
			}
			displayImage("image window");
			return int(objectProperties[largestDebris].angle);
		}
		else // No objects found
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
		if (VISION_DEBUG_TEXT){
			begin = clock();
			cout << "getting picture..." << endl;
		}
		Camera.grab();
		Camera.retrieve(image);
		//Camera.retrieve(temp);
		//flip(temp, image, -1); // flip the image 180 degrees
		cvtColor(image, hsv, COLOR_BGR2HSV);
		resolution = image.size();
	}
	
	//Finds objects of all colors; assumes a picture has been taken
	void findObjects() {
		objectProperties.clear();
		for (int i = 0; i < 4; i++) {
			findObjectsOfColor(i);
		}
	}

	// Populates vector array of object's properties; previously "GetObjectProperties"
	void findObjectsOfColor(int index)
	{
		objectProperties.clear(); // needs removed when using findObjects()
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
				Rect boundRect = boundingRect(contours[i]);
				float r;
				Point2f cent;
				w2h = (double)boundRect.width / boundRect.height;					 // Find width to height ratio, 1.0 is square
				percentFilled = area / (double) boundRect.area(); // amount of rectangle consumed by contour
				// Determine shape
				DebrisObject::ObjectType objectType = DebrisObject::ObjectType::Unknown;
				if (percentFilled < DEBRIS_MIN_PERCENT_FILLED) {
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), Scalar(200, 200, 200), 4, 8, 0);
					continue;
				}
				else if (w2h < DEBRIS_MAX_W2H && w2h > DEBRIS_MIN_W2H) {
					objectType = DebrisObject::ObjectType::Debris;
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), colors[index], 4, 8, 0);
				}
				else if(w2h < CORNER_MAX_W2H && w2h > CORNER_MIN_W2H) {
					objectType = DebrisObject::ObjectType::Corner;
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), colors[index], 4, 8, 0);
				}
				else { // wrong size ratio
					if (VISION_DEBUG_IMAGE)
						rectangle(image, boundRect.tl(), boundRect.br(), Scalar(100, 100, 100), 4, 8, 0);
				}
				
				if(objectType != DebrisObject::ObjectType::Unknown) {
					angle = atan((double)(boundRect.x - image.cols / 2) / (double)(image.rows - boundRect.y)) * 180 / PI; // Find angle to center of object from centerline
					distance = (1/(double)boundRect.width) * DISTANCE_MULTIPLIER;
					objectProperties.push_back(DebrisObject(boundRect, index, angle, distance, objectType));
				}
			}
		}
	}
	
	// returns the index of the largest debris object; if no colorIndex is provided, it finds the largest object of any color. If no matching object is found, -1 is returned.
	int findLargestObject(int colorIndex = -1)
	{
		int largestArea = 0;
		int area = 0;
		int objectIndex = -1;
		for (int i = 0; i < objectProperties.size(); i++)
		{
			if(objectProperties[i].type != DebrisObject::ObjectType::Debris || (colorIndex != -1 && objectProperties[i].colorIndex != colorIndex))
				continue;
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
			if(objectProperties[i].type != DebrisObject::ObjectType::Debris)
				continue;
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
		
		if (VISION_DEBUG_TEXT)
			if (objectProperties.size() > 0)
				cout << "Out of " << objectProperties.size() << " objects, " << labels[mostOccurringIndex] << " are the most common.\n";
			else
				cout << "No objects detected\n";
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
	
	static constexpr double CornerHeight = .3;		//meters; constexpr instead of const because it allows in-class initialization
	static constexpr double AvgDebrisHeight = .05715;		//If we gain the ability to differentiate between cubes and spheres, this should be replaced with two values
	static constexpr double CameraHeight = .22225;
	static constexpr double CameraAngle = 25.0;		//Degrees; angle the camera circuit board makes with the vertical. Only an approximate value. 
};
}; // namespace IEEE_VISION
