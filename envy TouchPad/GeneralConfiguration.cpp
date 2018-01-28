#include "stdafx.h"

#include "GeneralConfiguration.h"

using namespace Microsoft::Win32;
using namespace System;
using namespace System::Threading;

namespace envyTouchPad
{

bool GeneralConfiguration::isStartWithWindowsEnabled()
{
    return fIsStartWithWindowsEnabled;
}

void GeneralConfiguration::update(bool isStartWithWindowsEnabled)
{
    Monitor::Enter(this);
    try
    {
        fIsStartWithWindowsEnabled = isStartWithWindowsEnabled;
    }
    finally
    {
        Monitor::Exit(this);
    }
}

bool GeneralConfiguration::load()
{
    RegistryKey^ currentUserKey = Registry::CurrentUser;
    RegistryKey^ runKey = currentUserKey->OpenSubKey("Software")->OpenSubKey("Microsoft")->OpenSubKey("Windows")->OpenSubKey("CurrentVersion")->OpenSubKey("Run");

    String^ registeredExecutablePath = dynamic_cast<String^>(runKey->GetValue("envyTouchPad", "NOT_SET"));
    String^ executablePath = System::Windows::Forms::Application::ExecutablePath;

    Monitor::Enter(this);
    try
    {
        fIsStartWithWindowsEnabled = String::Equals(executablePath, registeredExecutablePath);
    }
    finally
    {
        Monitor::Exit(this);
    }

    return true;
}

bool GeneralConfiguration::save()
{
    RegistryKey^ currentUserKey = Registry::CurrentUser;
    RegistryKey^ runKey = currentUserKey->OpenSubKey("Software")->OpenSubKey("Microsoft")->OpenSubKey("Windows")->OpenSubKey("CurrentVersion")->OpenSubKey("Run", true);

    bool isStartWithWindowsEnabled = false;

    Monitor::Enter(this);
    try
    {
        isStartWithWindowsEnabled = fIsStartWithWindowsEnabled;
    }
    finally
    {
        Monitor::Exit(this);
    }

    if (isStartWithWindowsEnabled)
    {
        String^ executablePath = System::Windows::Forms::Application::ExecutablePath;
        runKey->SetValue("envyTouchPad", executablePath);
    }
    else
    {
        runKey->DeleteValue("envyTouchPad", false);
    }

    return true;
}

} // end namespace