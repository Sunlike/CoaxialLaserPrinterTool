#include "StdAfx.h"
#include "PlaneCorrection.h"

CPlaneCorrection::CPlaneCorrection(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			CCD_Calibration[i][j].x = (float)(2 - 1 * j);
			CCD_Calibration[i][j].y = (float)(-2 + 1 * i);
		}
	}
}

CPlaneCorrection::~CPlaneCorrection(void)
{
}

CPlaneCorrection::CPlaneCorrection(CMotorControl *X, CMotorControl *Y, CMotorControl *Z)
{
	Motor_X = X;
	Motor_Y = Y;
	Motor_Z = Z;
}

void CPlaneCorrection::createFile_MotorEncoder()
{
	for(int i = 0; i < 25; i++)
	{
		Motor_Y->AbsMotion(485-20*i);
		for( int j = 0; j < 25; j++)
		{
			Motor_X->AbsMotion(-505+20*j);
			if(Motor_X->InPosition() != 1 || Motor_Y->InPosition() != 1)
			{
				System::Windows::Forms::MessageBox::Show("馬達定位等後逾時!!");
				return;
			}
		}
	}

}

void CPlaneCorrection::getMotorEncoder(cv::Point2f *InputEncoder)
{
	for( int i = 0; i <= 24; i++)
	{
		for(int j = 0; j <= 25; j++)
		{
			MotorEncoder[i][j].x = InputEncoder->x;
			MotorEncoder[i][j].y = InputEncoder->y;
			InputEncoder++;
		}
	}
}

void CPlaneCorrection::getCCD25Holes(cv::Point2f *Input)
{
	for( int i = 0; i <= 4; i++)
	{
		for(int j = 0; j <= 4; j++)
		{
			CCD25Holes[i][j].x = Input->x;
			CCD25Holes[i][j].y = Input->y;
			Input++;
		}
	}
}

void CPlaneCorrection::getFile_PlaneCorrection()
{
	string line;
    string filename = "ALU.csv";
	ifstream myfile (filename.c_str());

	if (myfile.is_open())
	{

		for(int i = 0; i <= 24; i++)
		{
			for( int j = 0; j <= 25; j++)
			{
				size_t pos = 0;
				size_t now = 0;

				getline (myfile,line);

				pos = line.find(",", pos+1);
				now = pos+1;

				pos = line.find(",", pos+1);
				PlaneCoordinates[i][j].x = (float)atof(line.substr(now, pos-now).c_str());
				now = pos+1;

				pos = line.find(",", pos+1);
				PlaneCoordinates[i][j].y = (float)atof(line.substr(now, pos-now).c_str());
				now = pos+1;
			}
		}
	}
}

void CPlaneCorrection::getFile_MotorEncoder()
{
	string line;
    string filename = "MotorEncoder.csv";
	ifstream myfile (filename.c_str());

	if (myfile.is_open())
	{

		for(int i = 0; i <= 24; i++)
		{
			for( int j = 0; j <= 25; j++)
			{
				size_t pos = 0;
				size_t now = 0;

				getline (myfile,line);

				pos = line.find(",", pos+1);
				MotorEncoder[i][j].x = (float)atof(line.substr(now, pos-now).c_str());
				now = pos+1;

				pos = line.find(",", pos+1);
				MotorEncoder[i][j].y = (float)atof(line.substr(now, pos-now).c_str());
				now = pos+1;
			}
		}
	}
}

void CPlaneCorrection::getFile_CCD25Holes()
{
	string line;
    string filename = "CCD25Holes.csv";
	ifstream myfile (filename.c_str());

	if (myfile.is_open())
	{

		for(int i = 0; i <= 4; i++)
		{
			for( int j = 0; j <= 4; j++)
			{
				size_t pos = 0;
				size_t now = 0;

				getline (myfile,line);

				pos = line.find(",", pos+1);
				CCD25Holes[i][j].x = (float)atof(line.substr(now, pos-now).c_str());
				now = pos+1;

				pos = line.find(",", pos+1);
				CCD25Holes[i][j].y = (float)atof(line.substr(now, pos-now).c_str());
				now = pos+1;
			}
		}
	}
}
void CPlaneCorrection::writeMotorEncoder()
{
	ofstream outfile;
	outfile.open("MotorEncoder.csv",std::ios::trunc);

	for(int i = 0; i <= 24; i++)
	{
		for( int j = 0; j <= 25; j++)
		{
			outfile<<MotorEncoder[i][j].x<<","<<MotorEncoder[i][j].y<<endl;
		}
	}

	outfile.close();
}

void CPlaneCorrection::writeCCD25Holes()
{
	ofstream outfile;
	outfile.open("CCD25Holes.csv",std::ios::trunc);

	for(int i = 0; i <= 4; i++)
	{
		for( int j = 0; j <= 4; j++)
		{
			outfile<<CCD25Holes[i][j].x<<","<<CCD25Holes[i][j].y<<endl;
		}
	}

	outfile.close();
}

int CPlaneCorrection::RectangleMapping(cv::Point2f OrgLB,cv::Point2f OrgRB,cv::Point2f OrgRT,cv::Point2f OrgLT,cv::Point2f OrgPt,
                         cv::Point2f NewLB,cv::Point2f NewRB,cv::Point2f NewRT,cv::Point2f NewLT,cv::Point2f *NewPt)
{
	cv::Point2d   Org1,Org2,Org3,Org4;
    cv::Point2d    New1,New2,New3,New4;

    Org1.x = OrgLB.x;
    Org1.y = OrgLB.y;
    Org2.x = OrgRB.x;
    Org2.y = OrgRB.y;
    Org3.x = OrgRT.x;
    Org3.y = OrgRT.y;
    Org4.x = OrgLT.x;
    Org4.y = OrgLT.y;

    New1.x = NewLB.x;
    New1.y = NewLB.y;
    New2.x = NewRB.x;
    New2.y = NewRB.y;
    New3.x = NewRT.x;
    New3.y = NewRT.y;
    New4.x = NewLT.x;
    New4.y = NewLT.y;


    double    Alpha0=( Org1.x+Org2.x+Org3.x+Org4.x)/4;
    double    Alpha1=(-Org1.x+Org2.x+Org3.x-Org4.x)/4;
    double    Alpha2=(-Org1.x-Org2.x+Org3.x+Org4.x)/4;
    double    Alpha3=( Org1.x-Org2.x+Org3.x-Org4.x)/4;

    double    Beta0=( Org1.y+Org2.y+Org3.y+Org4.y)/4;
    double    Beta1=(-Org1.y+Org2.y+Org3.y-Org4.y)/4;
    double    Beta2=(-Org1.y-Org2.y+Org3.y+Org4.y)/4;
    double    Beta3=( Org1.y-Org2.y+Org3.y-Org4.y)/4;

    double    A=Beta2*Alpha3-Beta3*Alpha2;
    double    B=Beta0*Alpha3-OrgPt.y*Alpha3-Beta1*Alpha2+Beta2*Alpha1+Beta3*OrgPt.x-Beta3*Alpha0;
    double    C=Beta0*Alpha1+Beta1*OrgPt.x-Beta1*Alpha0-OrgPt.y*Alpha1;

    double    K;

    if(A > -0.00000001 && A < 0.00000001 )    A=0.000000001;


    double    k1 = (-B+sqrt(B*B-4*A*C))/(2*A);
    double    k2 = (-B-sqrt(B*B-4*A*C))/(2*A);

    if( k1 >= -4 && k1 <= 4 )        K = k1;
    else if( k2 >= -4 && k2 <= 4 )    K = k2;
    else    return    1;

    double    T = (OrgPt.x-Alpha0-Alpha2*K)/(Alpha1+Alpha3*K);

    double    N1 = (1-T-K+K*T)/4;
    double    N2 = (1+T-K-K*T)/4;
    double    N3 = (1+T+K+K*T)/4;
    double    N4 = (1-T+K-K*T)/4;


    NewPt->x = (float)(N1*New1.x+N2*New2.x+N3*New3.x+N4*New4.x);
    NewPt->y = (float)(N1*New1.y+N2*New2.y+N3*New3.y+N4*New4.y);

    return    0;

}



cv::Point2f CPlaneCorrection::returnCoordinate(cv::Point2f inputEncoder)
{
	int index_X, index_Y;
	cv::Point2f tempCoordinate;
	index_X = -1;

	for( int i = 0; i < 24; i++)
	{
		for( int j = 0; j < 25; j++)
		{
			if( MotorEncoder[i][j].x <= inputEncoder.x && (MotorEncoder[i][j].x + 110000) > inputEncoder.x &&
				MotorEncoder[i][j].y >= inputEncoder.y && (MotorEncoder[i][j].y - 110000) < inputEncoder.y)
			{
				index_X = j;
				index_Y = i;
			}
			else if( i == 0 && MotorEncoder[i][j].x < inputEncoder.x && 
				(MotorEncoder[i][j].x + 110000) > inputEncoder.x && MotorEncoder[i][j].y < inputEncoder.y)
			{
				index_X = j;
				index_Y = i;
			}
			else if( i == 23 && MotorEncoder[i+1][j].x < inputEncoder.x && 
				(MotorEncoder[i+1][j].x + 110000) > inputEncoder.x && MotorEncoder[i+1][j].y > inputEncoder.y) 
			{
				index_X = j;
				index_Y = i;
			}
			else if( j == 0 && MotorEncoder[i][j].y > inputEncoder.y && 
				(MotorEncoder[i][j].y - 110000) < inputEncoder.y && MotorEncoder[i][j].x > inputEncoder.x)
			{
				index_X = j;
				index_Y = i;
			}
			else if( j == 24 && MotorEncoder[i][j+1].y > inputEncoder.y && 
				(MotorEncoder[i][j+1].y - 110000) < inputEncoder.y && MotorEncoder[i][j+1].x < inputEncoder.x)
			{
				index_X = j;
				index_Y = i;
			}

		}
	}

	if( index_X == -1)
	{
		if( MotorEncoder[0][0].x > inputEncoder.x && MotorEncoder[0][0].y < inputEncoder.y)
		{
			index_X = 0;
			index_Y = 0;
		}
		else if( MotorEncoder[0][25].x < inputEncoder.x && MotorEncoder[0][25].y < inputEncoder.y)
		{
			index_X = 24;
			index_Y = 0;
		}
		else if( MotorEncoder[24][0].x > inputEncoder.x && MotorEncoder[24][0].y > inputEncoder.y)
		{
			index_X = 0;
			index_Y = 23;
		}
		else if( MotorEncoder[24][25].x < inputEncoder.x && MotorEncoder[24][25].y > inputEncoder.y)
		{
			index_X = 24;
			index_Y = 23;
		}
	}

	int temp;

	temp = RectangleMapping( MotorEncoder[index_Y+1][index_X], MotorEncoder[index_Y+1][index_X+1], MotorEncoder[index_Y][index_X+1], MotorEncoder[index_Y][index_X], inputEncoder,
		              PlaneCoordinates[index_Y+1][index_X], PlaneCoordinates[index_Y+1][index_X+1], PlaneCoordinates[index_Y][index_X+1], PlaneCoordinates[index_Y][index_X], &tempCoordinate);

	return tempCoordinate;	        

}

cv::Point2f CPlaneCorrection::returnMotorEncoder(cv::Point2f inputCorrdinate)
{
	int index_X, index_Y;
	cv::Point2f tempEncoder;
	index_X = -1;

	for( int i = 0; i < 24; i++)
	{
		for( int j = 0; j < 25; j++)
		{
			if( PlaneCoordinates[i][j].x <= inputCorrdinate.x && (PlaneCoordinates[i][j].x + 22) > inputCorrdinate.x &&
				PlaneCoordinates[i][j].y >= inputCorrdinate.y && (PlaneCoordinates[i][j].y - 22) < inputCorrdinate.y)
			{
				index_X = j;
				index_Y = i;
			}
			else if( i == 0 && PlaneCoordinates[i][j].x < inputCorrdinate.x && 
				(PlaneCoordinates[i][j].x + 22) > inputCorrdinate.x && PlaneCoordinates[i][j].y < inputCorrdinate.y)
			{
				index_X = j;
				index_Y = i;
			}
			else if( i == 23 && PlaneCoordinates[i+1][j].x < inputCorrdinate.x && 
				(PlaneCoordinates[i+1][j].x + 22) > inputCorrdinate.x && PlaneCoordinates[i+1][j].y > inputCorrdinate.y) 
			{
				index_X = j;
				index_Y = i;
			}
			else if( j == 0 && PlaneCoordinates[i][j].y > inputCorrdinate.y && 
				(PlaneCoordinates[i][j].y - 22) < inputCorrdinate.y && PlaneCoordinates[i][j].x > inputCorrdinate.x)
			{
				index_X = j;
				index_Y = i;
			}
			else if( j == 24 && PlaneCoordinates[i][j+1].y > inputCorrdinate.y && 
				(PlaneCoordinates[i][j+1].y - 22) < inputCorrdinate.y && PlaneCoordinates[i][j+1].x < inputCorrdinate.x)
			{
				index_X = j;
				index_Y = i;
			}

		}
	}

	if( index_X == -1)
	{
		if( PlaneCoordinates[0][0].x > inputCorrdinate.x && PlaneCoordinates[0][0].y < inputCorrdinate.y)
		{
			index_X = 0;
			index_Y = 0;
		}
		else if( PlaneCoordinates[0][25].x < inputCorrdinate.x && PlaneCoordinates[0][25].y < inputCorrdinate.y)
		{
			index_X = 24;
			index_Y = 0;
		}
		else if( PlaneCoordinates[24][0].x > inputCorrdinate.x && PlaneCoordinates[25][0].y > inputCorrdinate.y)
		{
			index_X = 0;
			index_Y = 23;
		}
		else if( PlaneCoordinates[24][25].x < inputCorrdinate.x && PlaneCoordinates[25][25].y > inputCorrdinate.y)
		{
			index_X = 24;
			index_Y = 23;
		}
	}

	RectangleMapping( PlaneCoordinates[index_Y+1][index_X], PlaneCoordinates[index_Y+1][index_X+1], PlaneCoordinates[index_Y][index_X+1], PlaneCoordinates[index_Y][index_X], inputCorrdinate,
		              MotorEncoder[index_Y+1][index_X], MotorEncoder[index_Y+1][index_X+1], MotorEncoder[index_Y][index_X+1], MotorEncoder[index_Y][index_X], &tempEncoder);

	return tempEncoder;	
}

cv::Point2f CPlaneCorrection::return25HolesCalibration(cv::Point2f inputCenter)
{
	int index_X, index_Y;
	cv::Point2f tempCoordinate;
	index_X = -1;

	for( int i = 0; i < 4; i++)
	{
		for( int j = 0; j < 4; j++)
		{
			if( CCD25Holes[i][j].x <= inputCenter.x && (CCD25Holes[i][j].x +65) > inputCenter.x &&
				CCD25Holes[i][j].y <= inputCenter.y && (CCD25Holes[i][j].y +65) > inputCenter.y)
			{
				index_X = j;
				index_Y = i;
			}
			else if( i == 0 && CCD25Holes[i][j].x < inputCenter.x && 
				(CCD25Holes[i][j].x + 65) > inputCenter.x && CCD25Holes[i][j].y > inputCenter.y)
			{
				index_X = j;
				index_Y = i;
			}
			else if( i == 3 && CCD25Holes[i+1][j].x < inputCenter.x && 
				(CCD25Holes[i+1][j].x + 65) > inputCenter.x && CCD25Holes[i+1][j].y < inputCenter.y) 
			{
				index_X = j;
				index_Y = i;
			}
			else if( j == 0 && CCD25Holes[i][j].y < inputCenter.y && 
				(CCD25Holes[i][j].y + 65) > inputCenter.y && CCD25Holes[i][j].x > inputCenter.x)
			{
				index_X = j;
				index_Y = i;
			}
			else if( j == 3 && CCD25Holes[i][j+1].y < inputCenter.y && 
				(CCD25Holes[i][j+1].y + 65) > inputCenter.y && CCD25Holes[i][j+1].x < inputCenter.x)
			{
				index_X = j;
				index_Y = i;
			}

		}
	}

	if( index_X == -1)
	{
		if( CCD25Holes[0][0].x > inputCenter.x && CCD25Holes[0][0].y > inputCenter.y)
		{
			index_X = 0;
			index_Y = 0;
		}
		else if( CCD25Holes[0][4].x < inputCenter.x && CCD25Holes[0][4].y > inputCenter.y)
		{
			index_X = 3;
			index_Y = 0;
		}
		else if( CCD25Holes[4][0].x > inputCenter.x && CCD25Holes[4][0].y < inputCenter.y)
		{
			index_X = 0;
			index_Y = 3;
		}
		else if( CCD25Holes[4][4].x < inputCenter.x && CCD25Holes[4][4].y < inputCenter.y)
		{
			index_X = 3;
			index_Y = 3;
		}
	}

	RectangleMapping( CCD25Holes[index_Y+1][index_X], CCD25Holes[index_Y+1][index_X+1], CCD25Holes[index_Y][index_X+1], CCD25Holes[index_Y][index_X], inputCenter,
		              CCD_Calibration[index_Y+1][index_X], CCD_Calibration[index_Y+1][index_X+1], CCD_Calibration[index_Y][index_X+1], CCD_Calibration[index_Y][index_X], &tempCoordinate);

	return tempCoordinate;
}


