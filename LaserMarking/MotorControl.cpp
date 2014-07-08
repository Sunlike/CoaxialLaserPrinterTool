#include "StdAfx.h"
#include "MotorControl.h"
   

CMotorControl::CMotorControl(void)
{
}

void CMotorControl::setParameter(unsigned short inputID)
{
	
	m_NodeID=inputID;
}

void CMotorControl::setVelProfile(double inputVel, double inputAcc, double inputJerk)
{
	m_Vel = inputVel;
	m_Acc = inputAcc;
	m_Jerk = inputJerk;

	long rtn = 0;
	//rtn = rtn + GT_PrflS(m_NodeID);
	rtn = rtn + GT_SetVel(m_NodeID, m_Vel);
	rtn = rtn + GT_SetAcc(m_NodeID, m_Acc);
	rtn = rtn + GT_SetJerk(m_NodeID, m_Jerk);
}

short CMotorControl::SON()
{
	short rtn = 0;
	rtn = rtn + GT_AlarmOff(m_NodeID);
	rtn = rtn + GT_CtrlMode(m_NodeID, 1);
	rtn = rtn + GT_StepDir(m_NodeID);
	rtn = rtn + GT_ClrSts(m_NodeID);
	rtn = rtn + GT_AxisOn(m_NodeID);
	return rtn;
}

short CMotorControl::SOFF()
{
	return 1;
}

short CMotorControl::SRELEASE()
{
	return 1;
}

long CMotorControl::AbsMotion(double Position)
{
	long rtn = 0;
	GT_ClrSts(m_NodeID);
	m_PlanPos = m_O + DisToPulse(Position);
	rtn = rtn + GT_SetPos(m_NodeID, m_PlanPos);
	rtn = rtn + GT_SetVel(m_NodeID, m_Vel);
	rtn = rtn + GT_SetAcc(m_NodeID, m_Acc);
	rtn = rtn + GT_SetJerk(m_NodeID, m_Jerk);
	rtn = rtn + GT_Update(m_NodeID);

	if(rtn == 0)
		return 1;
	else
		return 0;

	
}

short CMotorControl::AbsMotionPulse(int Position)
{
		return 1;
}

short  CMotorControl::RelMotion(double Distance)
{
	short rtn = 0;
	long pos;
	unsigned long status;

	GT_ClrSts(m_NodeID);
	rtn = rtn + GT_GetAtlPos(m_NodeID, &pos);
	m_PlanPos = pos + DisToPulse(Distance);
	rtn = rtn + GT_SetPos(m_NodeID, m_PlanPos);
	rtn = rtn + GT_SetVel(m_NodeID, m_Vel);
	rtn = rtn + GT_SetAcc(m_NodeID, m_Acc);
	rtn = rtn + GT_SetJerk(m_NodeID, m_Jerk);
	rtn = rtn + GT_Update(m_NodeID);

	if(rtn == 0)
		return 1;
	else
		return 0;
}

long CMotorControl::DisToPulse(double value)
{
	return (long)(value*1000);
}

void CMotorControl::getServoDI()
{
}

void CMotorControl::getServoDO()
{
}

int CMotorControl::returnCode(int codeID,int value)
{
	int code=0;
	for( int i=0;i<codeID;i++)
	{
		code=value%2;
		value=value/2;
	}
	return code;
}

int CMotorControl::returnDI(int codeID)
{

	return returnCode(codeID,m_DI);
}

int CMotorControl::returnDO(int codeID)
{

	return returnCode(codeID,m_DO);
}

int CMotorControl::InPosition()
{
	unsigned long status; 
	long pos;
	time_t t1,t2;
	t1=time(NULL);

	while(1)
	{
		t2=time(NULL);
		GT_ClrSts(m_NodeID);
		GT_GetSts(m_NodeID, &status);
		GT_GetAtlPos(m_NodeID,&pos);
		//temp=returnDO(2);
		if( !(status & 0x400)&& (pos-m_PlanPos) < 500 && (pos-m_PlanPos) > -500)
		{
			return 1;
		}
		else if( difftime(t2,t1)>5)
		{
			//MessageBoxA(NULL,"°¨¹F©w¦ìµ¥«á¹O®É!!", "Information", MB_OK);
			return -1;
		}
	}
}

void CMotorControl::setOriginal(long value)
{
	m_O=value;
}
long CMotorControl::getOriginal()
{
	return m_O;
}

short CMotorControl::goOriginal()
{
	short rtn = 0;
	m_PlanPos = 0;
	rtn = rtn + GT_SetPos(m_NodeID, m_PlanPos);
	rtn = rtn + GT_Update(m_NodeID);
	
	if(rtn == 0)
		return 1;
	else
		return 0;

}

long CMotorControl::goHomeMove()
{
	unsigned long status; 
	long pos=-1000000;	//©¹¥¿¦V³sÄò²¾°Ê1¤½¤Ø¡Aª½¨ì¼²¨ìHOME
	double vel_high=40;
	double vel_low=5;
	double acc = 4;

	GT_ClrSts(m_NodeID);  //²M¦^­ìŠ»…lƒ]†È 
	GT_SetPos(m_NodeID, pos); 
	GT_SetVel(m_NodeID,vel_high);  //°ª³t¬d§ä­ìŠ» 
	GT_SetAcc(m_NodeID,acc); 
	GT_Update(m_NodeID); 

	do 
	{ 
		GT_GetSts(m_NodeID,&status);  //ŒÝ¨ú¦^­ìŠ»…lƒ]†È 
		if(!(status&0x400)&&!(status&0x40)) 
			{  //¦^­ìŠ»…l¤w…î°±¤î 
				return -1;  //Home «H†A¤´µM•Ê¦³ àD„ú  
			} 
	}while(!(status&0x40));  

	GT_AbptStp(m_NodeID);

	GT_ClrSts(m_NodeID);  //²M¦^­ìŠ»…lƒ]†È 
	GT_CaptHome(m_NodeID);  //’â¦^­ìŠ»…l„¦¸mƒo­ìŠ»®·‰÷¤è¦¡ 
	GT_SetPos(m_NodeID, -pos); 
	GT_SetVel(m_NodeID,vel_high);  //°ª³t¬d§ä­ìŠ» 
	GT_SetAcc(m_NodeID,acc); 
	GT_Update(m_NodeID); 

	do 
	{ 
		if(status&0x40)
			GT_ClrSts(m_NodeID);
		GT_GetSts(m_NodeID,&status);  //ŒÝ¨ú¦^­ìŠ»…lƒ]†È 
		if(!(status&0x400)) 
			{  //¦^­ìŠ»…l¤w…î°±¤î 
				return -1;  //Home «H†A¤´µM•Ê¦³ àD„ú  
			} 
	}while(!(status&0x8));  //µ¥«Ý Home ®·‰÷  

	GT_SmthStp(m_NodeID);  //¥­·Æ°±¤î¦^­ìŠ»…l 

	do 
	{ 
		GT_GetSts(m_NodeID,&status); 
	}while(status&0x400);  //µ¥«Ý†bƒð§¹¦¨ 

	GT_GetCapt(m_NodeID,&pos);  //ŒÝ¨ú Home ®·‰÷¦ì¸m  
	GT_SetPos(m_NodeID,pos);    //§C³t†bƒð¨ì­ìŠ»®·‰÷¦ì¸m 
	GT_SetVel(m_NodeID,vel_low); 
	GT_Update(m_NodeID); 

	do 
	{ 
		GT_GetSts(m_NodeID,&status); 
	}while(status&0x400);  //µ¥«Ý†bƒð§¹¦¨ 

	/*GT_ClrSts(m_NodeID);  //²M°£ Home ®·‰÷àD„ú ‡á§Ó  
	GT_CaptIndex(m_NodeID);  //’â¦^­ìŠ»…l„¦¸mƒo Index ®·‰÷
	GT_SetPos(m_NodeID,pos-300000);  //¤Ï¦V²¾°Ê30¤½¤À¡A¥²¶·¦b³o30¤½¤À¤º§ä¨ìIndex
	GT_Update(m_NodeID); 

	do 
	{ 
	GT_GetSts(m_NodeID,&status); 
	if(!(status&0x400)) 
		{  //¦^­ìŠ»…l¤w…î°±¤î 
		return -1;  //Index «H†A¤´µM•Ê¦³ àD„ú  
		} 
	}while(!(status&0x8));  //µ¥«Ý Index «H†AàD„ú  

	GT_SmthStp(m_NodeID);  //¥­·Æ°±¤î¦^­ìŠ»…l 

	do 
	{ 
		GT_GetSts(m_NodeID,&status); 
	}while(status&0x400);  //µ¥«Ý†bƒð§¹¦¨ */

	GT_GetCapt(m_NodeID,&pos);  //ŒÝ¨ú Index ®·‰÷¦ì¸m  
	GT_SetPos(m_NodeID,pos);    //†bƒð¨ì Index ®·‰÷¦ì ¸m 
	long pos2=0;
	GT_GetAtlPos(m_NodeID,&pos2);			
	GT_SetAtlPos(m_NodeID,pos2-pos);//·s³]­pÂk¹s¤è¦¡

	return 1;
}

int CMotorControl::HomeReady()
{

	return 1;
}
int CMotorControl::InPosition_servo_cmd()
{
	
	return 1;
}
