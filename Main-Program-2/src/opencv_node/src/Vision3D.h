#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

//This class handles various tasks relating to vision in 3D space.
//This class uses OpenCV's 3D coordinate system. A diagram can be found at docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html.

class Vision3D {
public:
	static constexpr double CornerHeight = .3;		//meters; constexpr instead of const because it allows in-class initialization
	static constexpr double AvgDebrisHeight = .05715;		//If we gain the ability to differentiate between cubes and spheres, this should be replaced with two values
	static constexpr double CameraHeight = .208;				//.195 on the new robot
	static constexpr double CameraAngle = 28.0 / 180.0 * 3.14159265;		//Angle the camera circuit board makes with the vertical. Started at 30 and was experimentally determined to be 28.

	//Found using OpenCV's calibrate.py. Units are in meters. Assumes a resolution of 640 x 480.
	static const cv::Matx33d cameraMatrix;

	static const cv::Matx<double, 1, 5> distortionCoefficients;

	static cv::Point2d getPosIfHeight(cv::Point2d imagePos, double height);			//Positive x of the return points out the front of the camera. Positive y points to the left of the camera.
	
	static constexpr double centerTempOffset = .048;		//Should be set to zero for competition
	static constexpr double centerHeight = .2545;
	static constexpr double centerWidth = (.245 + .228) / 2.0;
};