#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
 
using namespace cv;
using namespace std;
 
int main()
{
  Mat src, gray;
  src = imread( "index.jpeg", 1 ); 
  resize(src,src,Size(500,450));
  cvtColor( src, gray, CV_BGR2GRAY );
 
  GaussianBlur( gray, gray, Size(9, 9), 2, 2 );
 
  vector<Vec3f> c;
 
  HoughCircles( gray, c, CV_HOUGH_GRADIENT, 2, 3, 175, 30, 10, 13 );
 
  for( size_t i = 0; i < c.size(); i++ )
  {
      Point ce(cvRound(c[i][0]), cvRound(c[i][1]));
      int r = cvRound(c[i][2]);     
      circle( src, ce, 3, Scalar(0,255,0), -1, 8, 0 );     
      circle( src, ce, r, Scalar(0,0,255), 3, 8, 0 );
      cout << "ce : " << ce << "\nr : " << r << endl;
    }
 
  namedWindow( "Output", CV_WINDOW_AUTOSIZE );
  imshow( "Output", src );
 
  waitKey(0);
  return 0;
}