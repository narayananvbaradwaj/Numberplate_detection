#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    Mat img,imgc;
    img = imread(argv[1], 0);
	int i, j;
	Mat element = getStructuringElement( MORPH_ELLIPSE, Size( 3, 3 ));
    erode( imgtemp, imgerode, element);
    namedWindow( "Display window", -1 );
    Canny(img, imgc, 70, 210, 3);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( imgc, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    Mat drawing = Mat::zeros( img.size(), CV_8UC3 );
    
    for(i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( 103, 224, 50 );
        drawContours( drawing, contours, i, color, 1, 8, hierarchy, 0, Point() );
    }     
    imshow(" Display window", drawing);
    waitKey(0);                        
    destroyAllWindows();
    return 0;
}
