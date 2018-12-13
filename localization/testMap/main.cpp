// basic file operations
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/geometry.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
namespace bg = boost::geometry;
namespace trans = bg::strategy::transform;
int main()
{
    double x,y;
    char q;
    typedef bg::model::point<double, 2, bg::cs::cartesian> point_t;
    typedef trans::rotate_transformer<bg::radian, double, 2, 2> rotator;
    typedef trans::translate_transformer<double,2,2> translater;
    //bg::model::polygon<point_t> polygon;
    /*bg::append(polygon.outer(), point_t(0.0, 0.0));
    bg::append(polygon.outer(), point_t(0.0, 5.0));
    bg::append(polygon.outer(), point_t(5.0, 5.0));
    bg::append(polygon.outer(), point_t(5.0, 0.0));
    bg::append(polygon.outer(), point_t(0.0, 0.0));*/
    bg::model::ring<point_t> hull;
    bg::model::multi_point<point_t> cloud;
    ifstream myfile;
    myfile.open ("data.txt");
    int qq;
    int sample = ('-' << 24) + ('-' << 16) + ('-' << 8) + '-';
    while(1){
        myfile.read((char*)&qq,4);
        if(qq == sample) break;
        myfile.seekg (-4, myfile.cur);
        myfile >> x;
        myfile.ignore(1);
        myfile >> y;
        myfile.ignore(1);   
        bg::append(cloud, point_t(x, y));
        //cout << x << " " << y << endl;
    }
    myfile.close();

    bg::convex_hull(cloud, hull);
    point_t centroid;
    bg::centroid(hull,centroid);
    bg::model::ring<point_t> transhull;
    translater translate(-centroid.get<0>(),-centroid.get<1>()); //center so rotation does no movement of the center of the field.
    boost::geometry::transform(hull, transhull, translate);
    
    bg::model::ring<point_t> rothull;
    double area = INFINITY,temp,angle;
    for(int i = 0; i < transhull.size()-1; i++){
        for(int j = i++; j < transhull.size(); j++){
            rotator rotate(atan((transhull[i].get<1>()-transhull[j].get<1>())/(transhull[i].get<0>()-transhull[j].get<0>())));
            boost::geometry::transform(transhull, rothull, rotate);
            bg::model::box<point_t> box;
            bg::envelope(rothull,box);
            temp = bg::area(box);
            if(temp < area){
                angle = atan((transhull[i].get<1>()-transhull[j].get<1>())/(transhull[i].get<0>()-transhull[j].get<0>()));
                area = temp;
            }
            rothull.clear();
        }
    }
    //just drawing the output from here on down
    rotator rotate(angle);
    boost::geometry::transform(transhull, rothull, rotate);

    Mat testimage = Mat::zeros(Size(1000,1000),CV_8UC3);
    for(int i = 0; i < rothull.size()-1; i++){
        int x1 = (int)(200*rothull[i].get<0>()+500), y1 = (int)(200*rothull[i].get<1>()+500);
        int x2 = (int)(200*rothull[i+1].get<0>()+500), y2 = (int)(200*rothull[i+1].get<1>()+500);
        //testimage.at<uchar>(y1,x1) = (uchar)255;
        line(testimage,Point(x1,y1),Point(x2,y2),Scalar(0,0,255));
    }
    {
        int x1 = (int)(200*rothull[0].get<0>()+500), y1 = (int)(200*rothull[0].get<1>()+500);
        int x2 = (int)(200*rothull[rothull.size()-1].get<0>()+500), y2 = (int)(200*rothull[rothull.size()-1].get<1>()+500);
        line(testimage,Point(x1,y1),Point(x2,y2),Scalar(0,0,255));
    }
    cout << angle*180*3.14 << " degrees" << endl; 
    cout << centroid.get<0>() << "," << centroid.get<1>() << endl;
    rectangle(testimage,Rect(-1.22*200+500,-1.22*200+500,2.44*200,2.44*200),Scalar(255,255,255),1);
    {
        RotatedRect rRect = RotatedRect(Point2f(500,500), Size2f(.23*200,.23*200), 45);
        Point2f vertices[4];
        rRect.points(vertices);
        for (int i = 0; i < 4; i++)
            line(testimage, vertices[i], vertices[(i+1)%4], Scalar(255,255,255));
    }
    {
        RotatedRect rRect = RotatedRect(Point2f(500-centroid.get<0>()*200,500+centroid.get<1>()*200), Size2f(.2286*200,.2286*200), angle*180*3.14);
        Point2f vertices[4];
        rRect.points(vertices);
        for (int i = 0; i < 4; i++)
            line(testimage, vertices[i], vertices[(i+1)%4], Scalar(0,255,255),2);
    }
    imwrite("final.png",testimage);
    
    return 0;
}