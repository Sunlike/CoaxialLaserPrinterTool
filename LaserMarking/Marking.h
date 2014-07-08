#pragma once
#include "stdAfx.h"
#include "MotorControl.h"


typedef struct
{
	double x;
	double y;

}_pos;

typedef struct
{
	double Xu;
	double Xl;
	double Yu;
	double Yl;
}_FitRect;

typedef struct
{
	bool IsInspect;
	bool IsLaser;
	string Name;
	double edgeX;
	double edgeY;
	double Angle;
	double MarkLength;
	double MarkWidth;
	double MarkHeight;
	string content;
	int Step;
	int TextIndex;
	

}_MarkInfo;

class CMarking
{
public:
	CMarking(vector<_MarkInfo> inputMark, float input_X, float input_Y);
	void MarkingStep();  //判斷個別Mark在第幾個步驟打
	void StartMarking();
	int returnStep();    //回傳共幾個步驟
	vector<_MarkInfo> returnMarkInfo();  
	_pos returnMarkInfo(int Step, vector<_MarkInfo> *input);
	_pos returnMarkInfo(int Step, vector<_MarkInfo> *input, _FitRect *inputRect);
	_pos returnMarkCenter(int Step);
	void setBoardLength(double Length);
	double getBoardLength();
	void setBoardWidth(double Width);
	double getBoardWidth();
	_FitRect returnRect(_MarkInfo inputMark, double rotateAngle);

private:
	vector<_MarkInfo> m_Mark;
	int m_MarkStep;
	float m_Laser_RANGE_X;
	float m_Laser_RANGE_Y;
	double m_BoardLength;
	double m_BoardWidth;
};
