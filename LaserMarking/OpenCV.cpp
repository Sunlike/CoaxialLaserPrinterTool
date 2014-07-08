#include "stdafx.h"
#include "OpenCV.h"

using namespace cv;

float Distance(cv::Point2f P1, cv::Point2f P2)
{
	return sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y));
}

float returnRatio(float length1, float length2)
{
	if( length1 > length2)
		return (length1/length2);
	else
		return (length2/length1);
}


int getCircle(cv::Point2f *center, float *radius, char *filename, int thresh, int MaxD)
{
	Mat src, src_gray;
	RNG rng(12345);
	src = imread(filename,1);
	cvtColor(src, src_gray, CV_BGR2GRAY);
	
	blur(src_gray, src_gray, cv::Size(4, 4));
	threshold(src_gray, src_gray, thresh, 255, 0);

	char* source_window = "Source";
	//namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	//namedWindow( "window", CV_WINDOW_AUTOSIZE );
	

	int threshold = 100;

	Mat canny_output;
	vector<vector<cv::Point> > contours;
	vector<vector<cv::Point> > rectangles;
	vector<Vec4i> hierarchy;
	/// Detect edges using canny
	Canny( src_gray, canny_output, threshold, threshold*2, 3 );
	/// Find contours
	findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );
	cvtColor(canny_output, canny_output, CV_GRAY2BGR);
	//imshow( "window", canny_output);
	/// Draw contours
	Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );

	
	vector<RotatedRect> minRect( contours.size() );

	float height, width, tempLength;
	double Ratio, tempRatio;
	cv::Point2f tempCenter;
	Ratio = 1.1;
	int rectIndex = -1;
	//float cx, cy, c_radius;

	for( unsigned int i = 0; i < contours.size(); i++ )
	{		
		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
		minRect[i] = minAreaRect( Mat(contours[i]) );
		Point2f rect_points[4]; 
		minRect[i].points( rect_points );

		for( int j = 0; j < 4; j++ )
			line( canny_output, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );

		height = Distance(rect_points[0], rect_points[1]);
		width = Distance(rect_points[1], rect_points[2]);
		tempRatio = returnRatio(height, width);

		if(height > width )
		 tempLength = width;
		else 
		 tempLength = height;
		tempCenter.x = (rect_points[0].x + rect_points[1].x + rect_points[2].x + rect_points[3].x)/4;
		tempCenter.y = (rect_points[0].y + rect_points[1].y + rect_points[2].y + rect_points[3].y)/4;

		if( tempRatio < Ratio && tempLength > 50 && tempLength < MaxD && tempCenter.x > 120 && tempCenter.x < 520 && tempCenter.y > 90 && tempCenter.y < 390/*&&  tempLength < 240*/) //當圓心在螢幕中央300*300的範圍，才會選取
		{
			Ratio = tempRatio;				 
			rectIndex = i;
			center->x = tempCenter.x;
			center->y = tempCenter.y;
			*radius = (height + width)/4;
		}
	}

	cvtColor(src_gray, src_gray, CV_GRAY2BGR);

	//imshow( source_window, canny_output);
	if(rectIndex != -1)
	{
		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );			 
		circle(src, cv::Point2f(center->x,center->y), (int)(*radius), color, 1, 8, 0);
		cv::imwrite("camera.bmp", src);
		//imshow( source_window, src_gray);
		return 1;
	}
	else
	{
		return 0;
	}

}

void CoordinateRotation( cv::Point2f input, cv::Point2f *output, double angle)
{
	output->x = (float)(input.x * cos(angle) - input.y * sin(angle)); 
	output->y = (float)(input.x * sin(angle) + input.y * cos(angle));
}	