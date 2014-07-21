// stdafx.h : 可在此標頭檔中包含標準的系統 Include 檔，
// 或是經常使用卻很少變更的
// 專案專用 Include 檔案
#pragma once
//#include <algorithm>
#include <string>
#include <windows.h>
#include   <stdio.h>
#include <math.h>
#include <vector>
#include "time.h"
#include "GEP.H"					// Static load: Step 1/2
#pragma comment(lib, "gep.lib")		// Static load: Step 2/2

// TODO: 在此參考您的程式所需要的其他標頭

using namespace std;

#define ComPort 3
#define Com_PLC 3
#define NoldID_PLC 9
#define pitch_X 20
#define pitch_Y 20
#define pitch_Z 10
#define motorID_X 1
#define motorID_Y 2
#define motorID_Z 3

#define scComSAMLightClientCtrlOutlineIndexMinX 0
#define scComSAMLightClientCtrlOutlineIndexMinY 1
#define scComSAMLightClientCtrlOutlineIndexMinZ 2
#define scComSAMLightClientCtrlOutlineIndexMaxX 3
#define scComSAMLightClientCtrlOutlineIndexMaxY 4
#define scComSAMLightClientCtrlOutlineIndexMaxZ 5

#define Laser_RANGE_X 30
#define Laser_RANGE_Y 30

//error code
#define MotorIsNotInPosition 10
#define X_axisFail 11
#define Y_axisFail 12
#define Z_axisFail 13
#define XY_axisFail 14
#define XZ_axisFail 15
#define YZ_axisFail 16
#define XYZ_axisFail 17
#define NoFiduicalMark 20
#define FiduicalMarkFail 21
#define TheLaserPowerDoesNotOpen 30
#define TheLaserControlSoftwareDoesNotOpen 31

#define PI 3.14159265

#define CCDPortNo 3

#define scComSAMLightClientCtrlDoubleValueTypeScannerXPos 12
#define scComSAMLightClientCtrlDoubleValueTypeScannerYPos 13
#define scComSAMLightClientCtrlDoubleValueTypeScannerZPos 14


#define scComSAMLightClientCtrlLongValueTypeMotionAxis 17
#define scComSAMLightClientCtrlLongValueTypeMotionWaitForEnd 18
#define scComSAMLightClientCtrlLongValueTypeMotionMoving 19
#define scComSAMLightClientCtrlDoubleValueTypeMotionAxisPosition 38
#define scComSAMLightClientCtrlDoubleValueTypeMotionAxisPositionRelative 40
#define scComSAMLightClientCtrlDoubleValueTypeMotionAxisSpeed 42
#define scComSAMLightClientCtrlDoubleValueTypeHorizontalSplittingValue 52
#define scComSAMLightClientCtrlDoubleValueTypeVerticalSplittingValue 53
#define scComSAMLightClientCtrlExecCommandResplitJob 13
#define scComSAMLightClientCtrlExecCommandMotionStopMove 14
#define scComSAMLightClientCtrlExecCommandMotionGo 16
#define GSpeed 200

#define MarkD 160
