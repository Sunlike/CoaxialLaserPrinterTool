#include "StdAfx.h"
#include "Marking.h"

CMarking::CMarking(vector<_MarkInfo> inputMark, float input_X, float input_Y)
{
	int size = inputMark.size();

	for(int i = 0; i < size; i++)
	{
		if(inputMark[i].IsLaser)
			m_Mark.push_back(inputMark[i]);
	}
	//m_Mark = inputMark;
	m_Laser_RANGE_X = input_X;
	m_Laser_RANGE_Y = input_Y;
}

void CMarking::MarkingStep()
{
	vector<_FitRect> MarkRect;
	_FitRect tempRect;
	_pos tempPos;
	for( unsigned int i = 0; i < m_Mark.size(); i++)
	{
		tempRect.Xl = 9999;
		tempRect.Xu = -9999;
		tempRect.Yl = 9999;
		tempRect.Yu = -9999;

		double tempX = (m_Mark[i].MarkLength) / 2;
		double tempY = (m_Mark[i].MarkWidth) / 2;

		//Left-Lower
		tempPos.x = m_Mark[i].edgeX + ( (-tempX) * cos(m_Mark[i].Angle * PI / 180) - (-tempY) * sin(m_Mark[i].Angle * PI / 180));
		tempPos.y = m_Mark[i].edgeY + ((-tempX) * sin(m_Mark[i].Angle * PI / 180) + (-tempY) * cos(m_Mark[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Right-Lower
		tempPos.x = m_Mark[i].edgeX + ( (tempX) * cos(m_Mark[i].Angle * PI / 180) - (-tempY) * sin(m_Mark[i].Angle * PI / 180));
		tempPos.y = m_Mark[i].edgeY + ((tempX) * sin(m_Mark[i].Angle * PI / 180) + (-tempY) * cos(m_Mark[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Left-Upper
		tempPos.x = m_Mark[i].edgeX + ( (-tempX) * cos(m_Mark[i].Angle * PI / 180) - (tempY) * sin(m_Mark[i].Angle * PI / 180));
		tempPos.y = m_Mark[i].edgeY + ((-tempX) * sin(m_Mark[i].Angle * PI / 180) + (tempY) * cos(m_Mark[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Right-Upper
		tempPos.x = m_Mark[i].edgeX + ( (tempX) * cos(m_Mark[i].Angle * PI / 180) - (tempY) * sin(m_Mark[i].Angle * PI / 180));
		tempPos.y = m_Mark[i].edgeY + ((tempX) * sin(m_Mark[i].Angle * PI / 180) + (tempY) * cos(m_Mark[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;


		MarkRect.push_back(tempRect);
	}
	_MarkInfo temp;
	if( m_Mark.size() > 2)
	{
		for( unsigned int i=0; i<(m_Mark.size()-2);i++)
		{
			for(unsigned int j=0 ; j < (m_Mark.size()-i-1); j++)
			{
				if( MarkRect[j].Xl > MarkRect[j+1].Xl)
				{
					temp = m_Mark[j];
					m_Mark[j] = m_Mark[j+1];
					m_Mark[j+1] = temp;

					tempRect = MarkRect[j];
					MarkRect[j] = MarkRect[j+1];
					MarkRect[j+1] = tempRect;

				}
			}
		}
	}
	else if( m_Mark.size() == 2)
	{
		if( m_Mark[0].edgeX > m_Mark[1].edgeX)
		{
			temp = m_Mark[0];
			m_Mark[0] = m_Mark[1];
			m_Mark[1] = temp;

			tempRect = MarkRect[0];
			MarkRect[0] = MarkRect[1];
			MarkRect[1] = tempRect;
		}
	}

	m_MarkStep=1;

	for (unsigned int i = 0; i < m_Mark.size(); i++)
	{
		if( m_Mark[i].Step == 0)
		{
			m_Mark[i].Step=m_MarkStep;
			unsigned int j=i+1;
			double Yu, Yl, tYu, tYl;
			Yu = MarkRect[i].Yu;
			Yl = MarkRect[i].Yl;
			/*-----判斷是否有其他Mark可同時打*/
			while (j < m_Mark.size() && (MarkRect[i].Xu - MarkRect[i].Xl) < m_Laser_RANGE_X && (MarkRect[i].Yu - MarkRect[i].Yl) < m_Laser_RANGE_Y)
			{
				if( m_Mark[j].Step == 0)
				{
					if(MarkRect[j].Yu > Yu)
						tYu = MarkRect[j].Yu;
					else
						tYu=Yu;

					if( MarkRect[j].Yl < Yl)
						tYl = MarkRect[j].Yl;
					else
						tYl=Yl;

					if( (MarkRect[j].Xu - MarkRect[i].Xl) < m_Laser_RANGE_X && (tYu - tYl) < m_Laser_RANGE_Y)
					{
						m_Mark[j].Step = m_MarkStep;
						Yu=tYu;
						Yl=tYl;
					}
					else if( (MarkRect[j].Xl - MarkRect[i].Xl) > m_Laser_RANGE_X)
					{
						break;
					}
				}
				j++;
			}
			m_MarkStep++;
		}
	}
	m_MarkStep--;
}

void CMarking::StartMarking()
{
	
}

int CMarking::returnStep()
{
	return m_MarkStep;
}

vector<_MarkInfo> CMarking::returnMarkInfo()
{
	return m_Mark;
}

_pos CMarking::returnMarkInfo(int Step, vector<_MarkInfo> *input)
{
	vector<_MarkInfo> tempMarkInfo;
	vector<_FitRect> MarkRect;
	_FitRect tempRect;
	for( unsigned int i = 0; i < m_Mark.size(); i++)
	{
		if( m_Mark[i].Step == Step)
			tempMarkInfo.push_back(m_Mark[i]);
	}
	*input = tempMarkInfo;

	_pos tempPos;
	for( unsigned int i = 0; i < tempMarkInfo.size(); i++)
	{
		tempRect.Xl = 9999;
		tempRect.Xu = -9999;
		tempRect.Yl = 9999;
		tempRect.Yu = -9999;

		double tempX = (tempMarkInfo[i].MarkLength) / 2;
		double tempY = (tempMarkInfo[i].MarkWidth) / 2;

		//Left-Lower
		tempPos.x = tempMarkInfo[i].edgeX + ( (-tempX) * cos(tempMarkInfo[i].Angle * PI / 180) - (-tempY) * sin(tempMarkInfo[i].Angle * PI / 180));
		tempPos.y = tempMarkInfo[i].edgeY + ((-tempX) * sin(tempMarkInfo[i].Angle * PI / 180) + (-tempY) * cos(tempMarkInfo[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Right-Lower
		tempPos.x = tempMarkInfo[i].edgeX + ( (tempX) * cos(tempMarkInfo[i].Angle * PI / 180) - (-tempY) * sin(tempMarkInfo[i].Angle * PI / 180));
		tempPos.y = tempMarkInfo[i].edgeY + ((tempX) * sin(tempMarkInfo[i].Angle * PI / 180) + (-tempY) * cos(tempMarkInfo[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Left-Upper
		tempPos.x = tempMarkInfo[i].edgeX + ( (-tempX) * cos(tempMarkInfo[i].Angle * PI / 180) - (tempY) * sin(tempMarkInfo[i].Angle * PI / 180));
		tempPos.y = tempMarkInfo[i].edgeY + ((-tempX) * sin(tempMarkInfo[i].Angle * PI / 180) + (tempY) * cos(tempMarkInfo[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Right-Upper
		tempPos.x = tempMarkInfo[i].edgeX + ( (tempX) * cos(tempMarkInfo[i].Angle * PI / 180) - (tempY) * sin(tempMarkInfo[i].Angle * PI / 180));
		tempPos.y = tempMarkInfo[i].edgeY + ((tempX) * sin(tempMarkInfo[i].Angle * PI / 180) + (tempY) * cos(tempMarkInfo[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;


		MarkRect.push_back(tempRect);
	}
	_pos Center;

	/*double uLimit, lLimit;
	uLimit = -9999;
	lLimit = 9999;*/

	tempRect.Xl = 9999;
	tempRect.Xu = -9999;
	tempRect.Yl = 9999;
	tempRect.Yu = -9999;
	for( unsigned int i = 0; i < tempMarkInfo.size(); i++)
	{
		if( MarkRect[i].Xl < tempRect.Xl)
			tempRect.Xl = MarkRect[i].Xl;

		if( MarkRect[i].Xu > tempRect.Xu)
			tempRect.Xu = MarkRect[i].Xu;

		if( MarkRect[i].Yl < tempRect.Yl)
			tempRect.Yl = MarkRect[i].Yl;

		if( MarkRect[i].Yu > tempRect.Yu)
			tempRect.Yu = MarkRect[i].Yu;
	}

	Center.x = (tempRect.Xl + tempRect.Xu)/2;

	Center.y = (tempRect.Yl + tempRect.Yu)/2;

	return Center;
}

_pos CMarking::returnMarkInfo(int Step, vector<_MarkInfo> *input, _FitRect *inputRect)
{
	vector<_MarkInfo> tempMarkInfo;
	vector<_FitRect> MarkRect;
	_FitRect tempRect;
	for( unsigned int i = 0; i < m_Mark.size(); i++)
	{
		if( m_Mark[i].Step == Step)
			tempMarkInfo.push_back(m_Mark[i]);
	}
	*input = tempMarkInfo;

	_pos tempPos;
	for( unsigned int i = 0; i < tempMarkInfo.size(); i++)
	{
		tempRect.Xl = 9999;
		tempRect.Xu = -9999;
		tempRect.Yl = 9999;
		tempRect.Yu = -9999;

		double tempX = (tempMarkInfo[i].MarkLength) / 2;
		double tempY = (tempMarkInfo[i].MarkWidth) / 2;

		//Left-Lower
		tempPos.x = tempMarkInfo[i].edgeX + ( (-tempX) * cos(tempMarkInfo[i].Angle * PI / 180) - (-tempY) * sin(tempMarkInfo[i].Angle * PI / 180));
		tempPos.y = tempMarkInfo[i].edgeY + ((-tempX) * sin(tempMarkInfo[i].Angle * PI / 180) + (-tempY) * cos(tempMarkInfo[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Right-Lower
		tempPos.x = tempMarkInfo[i].edgeX + ( (tempX) * cos(tempMarkInfo[i].Angle * PI / 180) - (-tempY) * sin(tempMarkInfo[i].Angle * PI / 180));
		tempPos.y = tempMarkInfo[i].edgeY + ((tempX) * sin(tempMarkInfo[i].Angle * PI / 180) + (-tempY) * cos(tempMarkInfo[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Left-Upper
		tempPos.x = tempMarkInfo[i].edgeX + ( (-tempX) * cos(tempMarkInfo[i].Angle * PI / 180) - (tempY) * sin(tempMarkInfo[i].Angle * PI / 180));
		tempPos.y = tempMarkInfo[i].edgeY + ((-tempX) * sin(tempMarkInfo[i].Angle * PI / 180) + (tempY) * cos(tempMarkInfo[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;

		//Right-Upper
		tempPos.x = tempMarkInfo[i].edgeX + ( (tempX) * cos(tempMarkInfo[i].Angle * PI / 180) - (tempY) * sin(tempMarkInfo[i].Angle * PI / 180));
		tempPos.y = tempMarkInfo[i].edgeY + ((tempX) * sin(tempMarkInfo[i].Angle * PI / 180) + (tempY) * cos(tempMarkInfo[i].Angle * PI / 180));
		if( tempPos.x < tempRect.Xl)
			tempRect.Xl = tempPos.x;
		if( tempPos.x > tempRect.Xu)
			tempRect.Xu = tempPos.x;
		if( tempPos.y < tempRect.Yl)
			tempRect.Yl = tempPos.y;
		if( tempPos.y > tempRect.Yu)
			tempRect.Yu = tempPos.y;


		MarkRect.push_back(tempRect);
	}
	_pos Center;

	/*double uLimit, lLimit;
	uLimit = -9999;
	lLimit = 9999;*/

	tempRect.Xl = 9999;
	tempRect.Xu = -9999;
	tempRect.Yl = 9999;
	tempRect.Yu = -9999;
	for( unsigned int i = 0; i < tempMarkInfo.size(); i++)
	{
		if( MarkRect[i].Xl < tempRect.Xl)
			tempRect.Xl = MarkRect[i].Xl;

		if( MarkRect[i].Xu > tempRect.Xu)
			tempRect.Xu = MarkRect[i].Xu;

		if( MarkRect[i].Yl < tempRect.Yl)
			tempRect.Yl = MarkRect[i].Yl;

		if( MarkRect[i].Yu > tempRect.Yu)
			tempRect.Yu = MarkRect[i].Yu;
	}

	*inputRect = tempRect;

	Center.x = (tempRect.Xl + tempRect.Xu)/2;

	Center.y = (tempRect.Yl + tempRect.Yu)/2;

	return Center;
}
void CMarking::setBoardLength(double Length)
{
	m_BoardLength = Length;
}

double CMarking::getBoardLength()
{
	return m_BoardLength;
}
void CMarking::setBoardWidth(double Width)
{
	m_BoardWidth = Width;
}

double CMarking::getBoardWidth()
{
	return m_BoardWidth;
}
_FitRect CMarking::returnRect(_MarkInfo inputMark, double rotateAngle)
{
	_FitRect tempRect;
	_pos tempPos;
	double tempAngle = inputMark.Angle * PI / 180 + rotateAngle;

	tempRect.Xl = 9999;
	tempRect.Xu = -9999;
	tempRect.Yl = 9999;
	tempRect.Yu = -9999;

	double tempX = (inputMark.MarkLength) / 2;
	double tempY = (inputMark.MarkWidth) / 2;

	//Left-Lower
	tempPos.x = inputMark.edgeX + ( (-tempX) * cos(tempAngle) - (-tempY) * sin(tempAngle));
	tempPos.y = inputMark.edgeY + ((-tempX) * sin(tempAngle) + (-tempY) * cos(tempAngle));
	if( tempPos.x < tempRect.Xl)
		tempRect.Xl = tempPos.x;
	if( tempPos.x > tempRect.Xu)
		tempRect.Xu = tempPos.x;
	if( tempPos.y < tempRect.Yl)
		tempRect.Yl = tempPos.y;
	if( tempPos.y > tempRect.Yu)
		tempRect.Yu = tempPos.y;

	//Right-Lower
	tempPos.x = inputMark.edgeX + ( (tempX) * cos(tempAngle) - (-tempY) * sin(tempAngle));
	tempPos.y = inputMark.edgeY + ((tempX) * sin(tempAngle) + (-tempY) * cos(tempAngle));
	if( tempPos.x < tempRect.Xl)
		tempRect.Xl = tempPos.x;
	if( tempPos.x > tempRect.Xu)
		tempRect.Xu = tempPos.x;
	if( tempPos.y < tempRect.Yl)
		tempRect.Yl = tempPos.y;
	if( tempPos.y > tempRect.Yu)
		tempRect.Yu = tempPos.y;

	//Left-Upper
	tempPos.x = inputMark.edgeX + ( (-tempX) * cos(tempAngle) - (tempY) * sin(tempAngle));
	tempPos.y = inputMark.edgeY + ((-tempX) * sin(tempAngle) + (tempY) * cos(tempAngle));
	if( tempPos.x < tempRect.Xl)
		tempRect.Xl = tempPos.x;
	if( tempPos.x > tempRect.Xu)
		tempRect.Xu = tempPos.x;
	if( tempPos.y < tempRect.Yl)
		tempRect.Yl = tempPos.y;
	if( tempPos.y > tempRect.Yu)
		tempRect.Yu = tempPos.y;

	//Right-Upper
	tempPos.x = inputMark.edgeX + ( (tempX) * cos(tempAngle) - (tempY) * sin(tempAngle));
	tempPos.y = inputMark.edgeY + ((tempX) * sin(tempAngle) + (tempY) * cos(tempAngle));
	if( tempPos.x < tempRect.Xl)
		tempRect.Xl = tempPos.x;
	if( tempPos.x > tempRect.Xu)
		tempRect.Xu = tempPos.x;
	if( tempPos.y < tempRect.Yl)
		tempRect.Yl = tempPos.y;
	if( tempPos.y > tempRect.Yu)
		tempRect.Yu = tempPos.y;

	return tempRect;
}
