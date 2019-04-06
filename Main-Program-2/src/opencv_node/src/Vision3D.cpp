#include "Vision3D.h"
#include <cmath>

#include "ros/ros.h"

using namespace std;
using namespace cv;

const cv::Matx33d Vision3D::cameraMatrix = {512.983, 0.0, 307.130,
		0, 513.019, 253.954,
		0, 0, 1};

Point2d Vision3D::getPosIfHeight(Point imagePos, double height) {
	Matx33d rotationMat = {1, 0, 0, 
				     0, cos(CameraAngle), sin(CameraAngle),
				     0, -sin(CameraAngle), cos(CameraAngle)};		 //Rotate clockwise about the x if the positive x axis is facing you
	Point3d dir = rotationMat * (cameraMatrix.inv() * Point3d(imagePos.x, imagePos.y, 1));
	if(dir.y <= 0.0) {
		
	}
	double t = (-height + CameraHeight) / dir.y;
	Point2d output;
	output.x = t * dir.x;
	output.y = t * dir.z;
	Point3d testResult = cameraMatrix.inv() * Point3d(imagePos.x, imagePos.y, 1);
	ROS_INFO("Before rotation: %f, %f, %f", testResult.x, testResult.y, testResult.z);
	ROS_INFO("Dir: %f, %f, %f", dir.x, dir.y, dir.z);
	ROS_INFO("Output: %f, %f", output.x, output.y);
	return output;
}
