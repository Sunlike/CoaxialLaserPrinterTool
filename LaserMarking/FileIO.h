#pragma once
#include "StdAfx.h"
#include "Marking.h"
#include <fstream>
#include <cv.h>

class CFileIO
{
public:
	CFileIO(void);
	void getFile(string filename, vector<_MarkInfo> *Mark, vector<_MarkInfo> *Target);
	void passString(string line, _MarkInfo *tempData);
	void getCameraSetting(vector<cv::Point2i> *inputSetting);
	double getBoardLength();
	double getBoardWidth();
	double getBoardThickness();
	int getZoom();
	int getIris();
	int getFocus();
	bool IsInspection();
	int getInspectZoom();
	int getInspectLight();
	int getThresh();
	int getScore();
	string getOCRFont();
	bool IsAutoMeasuring();
	

private:
	double m_BoardLength;
	double m_BoardWidth;
	double m_BoardThickness;
	int m_Zoom;
	int m_Iris;
	int m_Focus;
	bool m_Inspection;
	int m_InspectZoom;
	int m_InspectLight;
	int m_thresh;
	int m_score;
	string m_OCRFont;
	bool m_AutoMeasuring;
};
