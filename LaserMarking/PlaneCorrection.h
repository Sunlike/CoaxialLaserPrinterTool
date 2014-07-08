#pragma once
#include "MotorControl.h"
#include "OpenCV.h"
#include <fstream>

class CPlaneCorrection
{
public:
	CPlaneCorrection(void);
	~CPlaneCorrection(void);
	CPlaneCorrection(CMotorControl *X, CMotorControl *Y, CMotorControl *Z);
	void getFile_PlaneCorrection();
	void getFile_MotorEncoder();
	void getFile_CCD25Holes();
	void getMotorEncoder(cv::Point2f *InputEncoder);
	void getCCD25Holes(cv::Point2f *Input);
	void createFile_MotorEncoder();
	void writeMotorEncoder();
	void writeCCD25Holes();
	int RectangleMapping(cv::Point2f OrgLB,cv::Point2f OrgRB,cv::Point2f OrgRT,cv::Point2f OrgLT,cv::Point2f OrgPt,
                         cv::Point2f NewLB,cv::Point2f NewRB,cv::Point2f NewRT,cv::Point2f NewLT,cv::Point2f *NewPt);
	cv::Point2f returnCoordinate(cv::Point2f inputEncoder);
	cv::Point2f returnMotorEncoder(cv::Point2f inputCorrdinate);
	cv::Point2f return25HolesCalibration(cv::Point2f inputCenter);

private:
	cv::Point2f PlaneCoordinates[26][26];
	cv::Point2f MotorEncoder[26][26];
	cv::Point2f CCD25Holes[5][5];
	cv::Point2f CCD_Calibration[5][5];
	CMotorControl *Motor_X;
	CMotorControl *Motor_Y;
	CMotorControl *Motor_Z;
};
