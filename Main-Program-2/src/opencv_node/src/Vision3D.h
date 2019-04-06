#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

//This class handles various tasks relating to vision in 3D space.
//This class uses OpenCV's 3D coordinate system. A diagram can be found at docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html.

class Vision3D {
public:
	static constexpr double CornerHeight = .3;		//meters; constexpr instead of const because it allows in-class initialization
	static constexpr double AvgDebrisHeight = .05715;		//If we gain the ability to differentiate between cubes and spheres, this should be replaced with two values
	static constexpr double CameraHeight = .22225;
	static constexpr double CameraAngle = 30.0 / 180.0 * 3.14159265;		//Degrees; angle the camera circuit board makes with the vertical.

	//Found using OpenCV's calibrate.py. Units are in meters.
	static const cv::Matx33d cameraMatrix;

	static cv::Point2d getPosIfHeight(cv::Point imagePos, double height);
};