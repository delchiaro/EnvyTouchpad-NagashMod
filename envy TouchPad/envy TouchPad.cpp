// envy TouchPad.cpp : main project file.

#include "stdafx.h"
#include "envyTouchPadApplicationContext.h"

using namespace envyTouchPad;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main context and run it
	Application::Run(gcnew envyTouchPadApplicationContext());
	return 0;
}
