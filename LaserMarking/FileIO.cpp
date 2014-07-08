#include "stdafx.h"
#include "FileIO.h"

CFileIO::CFileIO(void)
{
}

double CFileIO::getBoardLength()
{
	return m_BoardLength;
}

double CFileIO::getBoardWidth()
{
	return m_BoardWidth;
}

double CFileIO::getBoardThickness()
{
	return m_BoardThickness;
}

int CFileIO::getIris()
{
	return m_Iris;
}

int CFileIO::getFocus()
{
	return m_Focus;
}

int CFileIO::getZoom()
{
	return m_Zoom;
}

bool CFileIO::IsInspection()
{
	return m_Inspection;
}
int CFileIO::getInspectZoom()
{
	return m_InspectZoom;
}

int CFileIO::getInspectLight()
{
	return m_InspectLight;
}

string CFileIO::getOCRFont()
{
	return m_OCRFont;
}
void CFileIO::passString(string line, _MarkInfo *tempData)
{
	size_t pos = 0;
	size_t now = 0;

	//Is Laser
	pos = line.find(",", pos+1);
	tempData->IsLaser = (line.substr(now, pos-now) == "True");
	now = pos+1;

	//Mark Name
	pos = line.find(",", pos+1);
	tempData->Name = line.substr(now, pos-now);
	now = pos+1;

	//Mark Content
	pos = line.find(",", pos+1);
	tempData->content = line.substr(now, pos-now);
	now = pos+1;

	//Distance to edge X
	pos = line.find(",", pos+1);
	tempData->edgeX = atof(line.substr(now, pos-now).c_str());
	now = pos+1;

	//Distance to edge Y
	pos = line.find(",", pos+1);
	tempData->edgeY = atof(line.substr(now, pos-now).c_str());
	now = pos+1;
	
	//Mark Length
	pos = line.find(",", pos+1);
	tempData->MarkLength = atof(line.substr(now, pos-now).c_str());
	now = pos+1;

	//Mark Width
	pos = line.find(",", pos+1);
	tempData->MarkWidth = atof(line.substr(now, pos-now).c_str());
	now = pos+1;

	//Mark Angle
	pos = line.find(",", pos+1);
	tempData->Angle = atof(line.substr(now, pos-now).c_str());
	now = pos+1;

	

	tempData->Step = 0;

}


int CFileIO::getThresh()
{
	return m_thresh;
}

int CFileIO::getScore()
{
	return m_score;
}

bool CFileIO::IsAutoMeasuring()
{
	return m_AutoMeasuring;
}

void CFileIO::getFile(string filename, vector<_MarkInfo> *Mark, vector<_MarkInfo> *Target)
{
	string line;
    filename = "PN/" + filename + ".pn";
	ifstream myfile (filename.c_str());
	int nowLine = 0;
	vector<_MarkInfo> tempMark, tempTarget;
	_MarkInfo tempData;
	string tempName;

	size_t pos = 0;
	size_t now = 0;
	
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{	
			getline (myfile,line);
			nowLine++;
			if( nowLine > 1 )
			{
				if( line.find_first_not_of(" ") != string::npos )
				{
					passString(line, &tempData);
					//tempString = tempData.Name;
					//tempName.assign(strlwr(tempData.Name.c_str()));
					if(tempData.Name == "fiducial")//FiducialMark
						tempTarget.push_back(tempData);
					else
						tempMark.push_back(tempData);
				}
			}
			else
			{
				pos = line.find(",",pos+1);
				m_BoardLength = atof(line.substr(now,pos-now).c_str());
				now=pos+1;

				pos = line.find(",",pos+1);
				m_BoardWidth = atof(line.substr(now,pos-now).c_str());
				now=pos+1;

			}
		}
		myfile.close();
	}
	else 
	{
		//System::Windows::Forms::MessageBox::Show("File isn't exist!!"); 
	}
	*Mark = tempMark;
	*Target = tempTarget;
}


void CFileIO::getCameraSetting(vector<cv::Point2i> *inputSetting)
{
	string line;
    string setting_filename = "camera_setting.txt";
	ifstream myfile (setting_filename.c_str());
	int nowLine = 0;
	string tempName;
	vector<cv::Point2i> tempSetting;
	cv::Point2i tempData;

	size_t pos = 0;
	size_t now = 0;
	
	if (myfile.is_open())
	{
		for( int i = 0; i < 16; i++)
		{
			getline (myfile,line);

			pos = line.find(",",pos+1);
			tempData.x = atoi(line.substr(now,pos-now).c_str());
			now=pos+1;

			pos = line.find(",",pos+1);
			tempData.y = atoi(line.substr(now,pos-now).c_str());
			now=pos+1;

			if( tempData.x < 1000 || tempData.x > 2400)
				tempData.x = 1000;

			if( tempData.y < 0 || tempData.y > 379)
				tempData.y = 0;

			tempSetting.push_back(tempData);

			pos = 0;
			now = 0;

		}
		myfile.close();
	}
	else
	{
		tempData.x = 1000;
		tempData.y = 0;
		for (int i = 0; i < 16; i++)
		{
			tempSetting.push_back(tempData);
		}
	}

	*inputSetting = tempSetting;

}