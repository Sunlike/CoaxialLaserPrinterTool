#include "stdafx.h"
#include <cv.h>
#include "cxcore.h"
#include "highgui.h"

float Distance(cv::Point2f P1, cv::Point2f P2);
float returnRatio(int length1, int length2);
int getCircle(cv::Point2f *center, float *radius, char *filename, int thresh, int MaxD);
void CoordinateRotation( cv::Point2f input, cv::Point2f *output, double angle);