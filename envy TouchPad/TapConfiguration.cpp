#include "stdafx.h"

#include "TapConfiguration.h"

using namespace Microsoft::Win32;
using namespace System;
using namespace System::Threading;

namespace 
{

int getRegistryValueAsInt(RegistryKey^ registryKey, String^ key, int defaultValue)
{
    if (registryKey == nullptr)
    {
        return defaultValue;
    }

    Object^ object = registryKey->GetValue(key, defaultValue);

    return Int32::Parse(object->ToString());
}

} // end anonymous namespace

namespace envyTouchPad
{

int TapConfiguration::getMaxDistance()
{
    return fMaxDistance;
}

int TapConfiguration::getMaxWThreshold()
{
    return fMaxWThreshold;
}

int TapConfiguration::getMaxZThreshold()
{
    return fMaxZThreshold;
}

int TapConfiguration::getSingleTapIntervalThreshold()
{
    return fSingleTapIntervalThreshold;
}

MouseButton TapConfiguration::getMouseButton(long numberOfFingers)
{
    int persistentValue = MouseButton::UNKNOWN.getPersistentValue();
    Monitor::Enter(this);
    try
    {
        switch(numberOfFingers)
        {
        case 1:
            persistentValue = fOneFingerMouseButtonPersistentValue;
            break;
        case 2:
            persistentValue = fTwoFingerMouseButtonPersistentValue;
            break;
        case 3:
            persistentValue = fThreeFingerMouseButtonPersistentValue;
            break;
        }
    }
    finally
    {
        Monitor::Exit(this);
    }

    return MouseButton::getMouseButton(persistentValue);
}

void TapConfiguration::update
(
    int singleTapIntervalThreshold,
    int maxDistance,
    int maxWThreshold,
    int maxZThreshold,
    int oneFingerMouseButtonPersistentValue,
    int twoFingerMouseButtonPersistentValue,
    int threeFingerMouseButtonPersistentValue
)
{
    Monitor::Enter(this);
    try
    {
        fMaxDistance = maxDistance;
        fMaxWThreshold = maxWThreshold;
        fMaxZThreshold = maxZThreshold;
        fSingleTapIntervalThreshold = singleTapIntervalThreshold;
        fOneFingerMouseButtonPersistentValue = oneFingerMouseButtonPersistentValue;
        fTwoFingerMouseButtonPersistentValue = twoFingerMouseButtonPersistentValue;
        fThreeFingerMouseButtonPersistentValue = threeFingerMouseButtonPersistentValue;
    }
    finally
    {
        Monitor::Exit(this);
    }
}

bool TapConfiguration::load()
{
    RegistryKey^ currentUserKey = Registry::CurrentUser;
    RegistryKey^ envyTouchPadKey = currentUserKey->OpenSubKey("Software")->OpenSubKey("envyTouchPad");

    Monitor::Enter(this);
    try
    {
        fMaxDistance = getRegistryValueAsInt(envyTouchPadKey, "tapMaxDistance", kDefaultMaxDistance);
        fMaxWThreshold = getRegistryValueAsInt(envyTouchPadKey, "tapMaxWThreshold", kDefaultMaxWThreshold);
        fMaxZThreshold = getRegistryValueAsInt(envyTouchPadKey, "tapMaxZThreshold", kDefaultMaxZThreshold);
        fSingleTapIntervalThreshold = getRegistryValueAsInt(envyTouchPadKey, "tapSingleTapIntervalThreshold", kDefaultSingleTapIntervalThreshold);
        fOneFingerMouseButtonPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "tapOneFingerMouseButton", kDefaultOneFingerMouseButtonPersistentValue);
        fTwoFingerMouseButtonPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "tapTwoFingerMouseButton", fDefaultTwoFingerMouseButtonPersistentValue);
        fThreeFingerMouseButtonPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "tapThreeFingerMouseButton", fDefaultThreeFingerMouseButtonPersistentValue);
    }
    finally
    {
        Monitor::Exit(this);
    }

    return true;
}

bool TapConfiguration::save()
{
    RegistryKey^ currentUserKey = Registry::CurrentUser;
    RegistryKey^ envyTouchPadKey = currentUserKey->OpenSubKey("Software", true)->CreateSubKey("envyTouchPad");

    if (envyTouchPadKey == nullptr)
    {
        return false;
    }

    Monitor::Enter(this);
    try
    {
        envyTouchPadKey->SetValue("tapMaxDistance", fMaxDistance);
        envyTouchPadKey->SetValue("tapMaxWThreshold", fMaxWThreshold);
        envyTouchPadKey->SetValue("tapMaxZThreshold", fMaxZThreshold);
        envyTouchPadKey->SetValue("tapSingleTapIntervalThreshold", fSingleTapIntervalThreshold);
        envyTouchPadKey->SetValue("tapOneFingerMouseButton", fOneFingerMouseButtonPersistentValue);
        envyTouchPadKey->SetValue("tapTwoFingerMouseButton", fTwoFingerMouseButtonPersistentValue);
        envyTouchPadKey->SetValue("tapThreeFingerMouseButton", fThreeFingerMouseButtonPersistentValue);
    }
    finally
    {
        Monitor::Exit(this);
    }

    return true;
}

} // end namespace