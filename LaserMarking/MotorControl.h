#pragma once
#include "stdafx.h"
#include "function.h"
#include "time.h"

class CMotorControl
{
public:
	CMotorControl(void);
	void setParameter(unsigned short inputID);
	short SON();
	short SOFF();
	short SRELEASE();
	long AbsMotion(double Position);
	short AbsMotionPulse(int Position);
	short AbsMotionZ(double Position);
	short RelMotion(double Distance);
	void setVelProfile(double inputVel, double inputAcc, double inputJerk);
	unsigned short setSpeedProfile(unsigned short SlotID, unsigned short MaxVel, unsigned short acc, unsigned short dec);
	short goOriginal();
	long goHomeMove();
	void getServoDI();
	void getServoDO();
	int returnDI(int codeID);
	int returnDO(int codeID);
	int InPosition();
	int InPosition_servo_cmd();
	int HomeReady();
	void setOriginal(long value);
	long getOriginal();
private:
	//AxSAMLIGHT_CLIENT_CTRL_OCXLib::AxScSamlightClientCtrl^  m_samlight;
	unsigned short m_NodeID;  //X=1; Y=2; Z=3
	long DisToPulse(double value);
	unsigned short m_DO;
	unsigned short m_DI;
	long m_O;
	long m_PlanPos;
	int returnCode(int codeID,int value);
	double m_Vel;
	double m_Acc;
	double m_Jerk;
};
