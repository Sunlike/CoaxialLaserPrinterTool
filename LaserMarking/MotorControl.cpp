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
			//MessageBoxA(NULL,"馬達定位等後逾時!!", "Information", MB_OK);
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
	long pos=-1000000;	//往正向連續移動1公尺，直到撞到HOME
	double vel_high=40;
	double vel_low=5;
	double acc = 4;

	GT_ClrSts(m_NodeID);  //清回原���l�]�� 
	GT_SetPos(m_NodeID, pos); 
	GT_SetVel(m_NodeID,vel_high);  //高速查找原�� 
	GT_SetAcc(m_NodeID,acc); 
	GT_Update(m_NodeID); 

	do 
	{ 
		GT_GetSts(m_NodeID,&status);  //�搢�回原���l�]�� 
		if(!(status&0x400)&&!(status&0x40)) 
			{  //回原���l已�謚惜� 
				return -1;  //Home 信�A仍然�呇� 触��  
			} 
	}while(!(status&0x40));  

	GT_AbptStp(m_NodeID);

	GT_ClrSts(m_NodeID);  //清回原���l�]�� 
	GT_CaptHome(m_NodeID);  //�潀^原���l�次m�o原�赫��髐閬� 
	GT_SetPos(m_NodeID, -pos); 
	GT_SetVel(m_NodeID,vel_high);  //高速查找原�� 
	GT_SetAcc(m_NodeID,acc); 
	GT_Update(m_NodeID); 

	do 
	{ 
		if(status&0x40)
			GT_ClrSts(m_NodeID);
		GT_GetSts(m_NodeID,&status);  //�搢�回原���l�]�� 
		if(!(status&0x400)) 
			{  //回原���l已�謚惜� 
				return -1;  //Home 信�A仍然�呇� 触��  
			} 
	}while(!(status&0x8));  //等待 Home 捕��  

	GT_SmthStp(m_NodeID);  //平滑停止回原���l 

	do 
	{ 
		GT_GetSts(m_NodeID,&status); 
	}while(status&0x400);  //等待�b�藃髡� 

	GT_GetCapt(m_NodeID,&pos);  //�搢� Home 捕�鬫鼽m  
	GT_SetPos(m_NodeID,pos);    //低速�b�藂鴙��赫��鬫鼽m 
	GT_SetVel(m_NodeID,vel_low); 
	GT_Update(m_NodeID); 

	do 
	{ 
		GT_GetSts(m_NodeID,&status); 
	}while(status&0x400);  //等待�b�藃髡� 

	/*GT_ClrSts(m_NodeID);  //清除 Home 捕�欑D�� �嵺�  
	GT_CaptIndex(m_NodeID);  //�潀^原���l�次m�o Index 捕��
	GT_SetPos(m_NodeID,pos-300000);  //反向移動30公分，必須在這30公分內找到Index
	GT_Update(m_NodeID); 

	do 
	{ 
	GT_GetSts(m_NodeID,&status); 
	if(!(status&0x400)) 
		{  //回原���l已�謚惜� 
		return -1;  //Index 信�A仍然�呇� 触��  
		} 
	}while(!(status&0x8));  //等待 Index 信�A触��  

	GT_SmthStp(m_NodeID);  //平滑停止回原���l 

	do 
	{ 
		GT_GetSts(m_NodeID,&status); 
	}while(status&0x400);  //等待�b�藃髡� */

	GT_GetCapt(m_NodeID,&pos);  //�搢� Index 捕�鬫鼽m  
	GT_SetPos(m_NodeID,pos);    //�b�藂� Index 捕�鬫� 置 
	long pos2=0;
	GT_GetAtlPos(m_NodeID,&pos2);			
	GT_SetAtlPos(m_NodeID,pos2-pos);//新設計歸零方式

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
