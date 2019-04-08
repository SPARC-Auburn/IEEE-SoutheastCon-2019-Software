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
	double t = (-height + CameraHeight) / dir.y;
	Point2d output;
	output.x = t * dir.x;
	output.y = t * dir.z;
	return output;
}
