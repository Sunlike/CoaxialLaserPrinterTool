#include "stdafx.h"

using namespace System;
using namespace System::IO;

void MarshalString ( String ^ s, string& os );

int MotorError(int motorX, int motorY, int motorZ, int Language);

void MachineErrorMessage(String^ msg);