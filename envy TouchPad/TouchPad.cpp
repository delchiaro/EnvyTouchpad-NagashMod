#include "stdafx.h"

#include "TouchPad.h"

using namespace System;
using namespace Microsoft::Win32;

namespace
{
    long getValue(ISynDevice* device, SynDeviceProperty deviceProperty)
	{
		long value;
		device->GetProperty(deviceProperty, &value);

		return value;
	}

	void setValue(ISynDevice* device, SynDeviceProperty deviceProperty, long value)
	{
		device->SetProperty(deviceProperty, value);
	}

} // end anonymous namespace

namespace envyTouchPad
{

TouchPad::TouchPad()
{
    fIsAcquired = false;
    fIsInitialized = false;
    fAPI = NULL;
    fDevice = NULL;

    HRESULT result = SynCreateAPI(&fAPI);

    if (fAPI)
    {
        // Find a TouchPad.
        long lHandle = -1;
        if (!fAPI->FindDevice(SE_ConnectionAny, SE_DeviceTouchPad, &lHandle))
        {
            if (SYN_OK == fAPI->CreateDevice(lHandle, &fDevice))
            {
                fIsInitialized = !!fDevice;
            }
        }
    }
}

TouchPad::~TouchPad()
{
}

bool TouchPad::isInitialized()
{
    return fIsInitialized;
}

bool TouchPad::isSetup(System::Text::StringBuilder^ errorMessageBuilder)
{
    if (!fIsInitialized)
    {
        return false;
    }
    	
    if (!getValue(fDevice, SP_IsMultiFingerCapable))
	{
        RegistryKey^ localMachineKey = Registry::LocalMachine;
        RegistryKey^ servicesKey = localMachineKey->OpenSubKey("System")->OpenSubKey("CurrentControlSet")->OpenSubKey("Services");

        if (servicesKey == nullptr)
        {
            errorMessageBuilder->Append("Unable to find LocalMachine\\System\\CurrentControlSet\\Services registry key!");
            return false;
        }

        RegistryKey^ synapticsTouchPadKey = servicesKey->OpenSubKey("SynTP");
        if (synapticsTouchPadKey == nullptr)
        {
            errorMessageBuilder->Append("Unable to find LocalMachine\\System\\CurrentControlSet\\Services\\SynTP registry key!");
            return false;
        }

        RegistryKey^ parametersKey = synapticsTouchPadKey->OpenSubKey("Parameters");
        if (parametersKey == nullptr)
        {
            errorMessageBuilder->Append("Unable to find LocalMachine\\System\\CurrentControlSet\\Services\\SynTP\\Parameters registry key!\nSynaptics kernel driver registry keys missing.\n\nPlease re-install drivers.");
            return false;
        }

        Int32^ capabilitiesMask = static_cast<Int32^>(parametersKey->GetValue("CapabilitiesMask"));

		if (capabilitiesMask == nullptr)
        {
            errorMessageBuilder->Append("Unable to find LocalMachine\\System\\CurrentControlSet\\Services\\SynTP\\Parameters\\CapabilitiesMask registry value!\nSynaptics kernel driver registry keys missing.\n\nPlease re-install drivers.");
            return false;
        }
        if (*capabilitiesMask == 0xFFFFFFFF) 
        {
		    errorMessageBuilder->Append("Driver support for multiple fingers is already enabled but\nthe driver still doesn't report multiple fingers. Either you haven't restarted\nthe system yet or your TouchPad doesn't support multiple fingers.");
            return false;
        }
	}

    if (SYN_OK != fDevice->CreatePacket(&fPacket))
    {
        errorMessageBuilder->Append("Failed to create the packet!");
        return false;
    }

    return true;
}

bool TouchPad::isAcquired()
{
    return fIsAcquired;
}

bool TouchPad::registerEventListener(_ISynDeviceEvents* eventListener)
{
    return (SYN_OK == fDevice->SetSynchronousNotification(eventListener));
}

Packet^ TouchPad::getPacket()
{
    fDevice->LoadPacket(fPacket);
    return gcnew Packet(fPacket);
}

void TouchPad::acquire(bool acquire)
{
	if (acquire && !fIsAcquired)
	{
		fDevice->Acquire(SF_AcquireAll);
	}
	else if (!acquire && fIsAcquired)
	{
		fDevice->Unacquire();
	}
	fIsAcquired = acquire;
}

long TouchPad::getMinX() 
{ 
    return getValue(fDevice, SP_XLoBorder); 
}

long TouchPad::getMinY() 
{ 
    return getValue(fDevice, SP_YLoBorder); 
}

long TouchPad::getMaxX() 
{ 
    return getValue(fDevice, SP_XHiBorder); 
}

long TouchPad::getMaxY() 
{ 
    return getValue(fDevice, SP_YHiBorder); 
}

} // end namespace