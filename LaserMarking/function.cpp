#include "stdafx.h"
#include "function.h"

void MarshalString ( String ^ s, string& os ) {
   using namespace Runtime::InteropServices;
   const char* chars = 
     (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}

int MotorError(int motorX, int motorY, int motorZ, int Language)
{
	string errorMsg;
	errorMsg = "";
	if( motorX == 0 || motorY == 0 ||motorZ == 0)
	{
		if(motorX == 0)
		{
			errorMsg = "X";					
		}

		if(motorY == 0)
		{
			errorMsg = errorMsg + " Y";
		}

		if(motorZ == 0)
		{
			errorMsg = errorMsg + " Z";
		}
		if(Language == 1)
		{
			errorMsg = errorMsg + "-axis error. Please remove the PCB.";
		}
		else
		{
			errorMsg = errorMsg + "軸異常，請取出電路板。";
		}

		//_XYTable_PLC_PC_set_ALM_LV2( 3, 0, 1);
		String^ temp = gcnew String(errorMsg.c_str());
		System::Windows::Forms::MessageBox::Show(temp); 
		
		MachineErrorMessage(temp);
		//MessageBox::Show(errorMsg);
		//_XYTable_PLC_PC_set_ALM_LV2( 3, 0, 0);

		return 0;
	}
	return 1;
}

void MachineErrorMessage(String^ msg)
{
	String^ fileName;
	String^ status;
	DateTime nowTime;
	nowTime = DateTime::Now;
	status = nowTime.ToString("G")+","+msg;
	fileName = "errorlist"+nowTime.ToString("yyyyMMdd");
	FileStream^ fs=gcnew FileStream(fileName, FileMode::Append);
	StreamWriter^ sw=gcnew StreamWriter(fs);
	sw->WriteLine(status);
	sw->Flush();

	sw->Close();
	fs->Close();
}
