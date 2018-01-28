#include "stdafx.h"

#include "ScrollConfiguration.h"

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

int boolToInt(bool value)
{
    return value ? 1 : 0;
}

bool intToBool(int value)
{
    return value != 0;
}

} // end anonymous namespace

namespace envyTouchPad
{

bool ScrollConfiguration::isAccelerationEnabled()
{
    return fIsAccelerationEnabled;
}

int ScrollConfiguration::getAccelerationFactor()
{
    return fAccelerationFactor;
}

int ScrollConfiguration::getInertialScrollDuration()
{
    return fInertialScrollDuration;
}

int ScrollConfiguration::getDeltaRatioThreshold()
{
    return fDeltaRatioThreshold;
}

EasingAlgorithmType ScrollConfiguration::getInertialScrollEasingAlgorithm()
{
    return fInertialScrollEasingAlgorithm;
}

int ScrollConfiguration::getMaxZThreshold()
{
    return fMaxZThreshold;
}

int ScrollConfiguration::getSpeed()
{
    return fSpeed;
}

bool ScrollConfiguration::isReverseScrollingEnabled()
{
	return this->fReverseScrolling;
}

void ScrollConfiguration::update
(
    int accelerationFactor, 
    bool isAccelerationEnabled, 
    int deltaRatioThreshold,
    int inertialScrollDuration,
    EasingAlgorithmType inertialScrollEasingAlgorithm,
    int maxZThreshold,
    int speed,
	bool isReverseScrollingEnabled
)
{
    Monitor::Enter(this);
    try
    {
        fAccelerationFactor = accelerationFactor;
        fIsAccelerationEnabled = isAccelerationEnabled;
        fDeltaRatioThreshold = deltaRatioThreshold;
        fInertialScrollDuration = inertialScrollDuration;
        fInertialScrollEasingAlgorithm = inertialScrollEasingAlgorithm;
        fMaxZThreshold = maxZThreshold;
        fSpeed = speed;
		fReverseScrolling = isReverseScrollingEnabled;
    }
    finally
    {
        Monitor::Exit(this);
    }
}

bool ScrollConfiguration::load()
{
    RegistryKey^ currentUserKey = Registry::CurrentUser;
    RegistryKey^ envyTouchPadKey = currentUserKey->OpenSubKey("Software")->OpenSubKey("envyTouchPad");

    Monitor::Enter(this);
    try
    {
        fAccelerationFactor = getRegistryValueAsInt(envyTouchPadKey, "scrollAccelerationFactor", kDefaultAccelerationFactor);
        fIsAccelerationEnabled = intToBool(getRegistryValueAsInt(envyTouchPadKey, "scrollIsAccelerationEnabled", kDefaultIsAccelerationEnabled));
        fDeltaRatioThreshold = getRegistryValueAsInt(envyTouchPadKey, "scrollDeltaRatioThreshold", kDefaultDeltaRatioThreshold);
        fInertialScrollDuration = getRegistryValueAsInt(envyTouchPadKey, "scrollInertialScrollDuration", kDefaultInertialScrollDuration);
        fInertialScrollEasingAlgorithm = EasingAlgorithm::map(getRegistryValueAsInt(envyTouchPadKey, "scrollInertialScrollEasingAlgorithm", kDefaultInertialScrollEasingAlgorithm));
        fMaxZThreshold = getRegistryValueAsInt(envyTouchPadKey, "scrollMaxZThreshold", kDefaultMaxZThreshold);
        fSpeed = getRegistryValueAsInt(envyTouchPadKey, "scrollSpeed", kDefaultSpeed);
		fReverseScrolling = intToBool(getRegistryValueAsInt(envyTouchPadKey, "reverseScrolling", kDefaultReverseScrolling));
    }
    finally
    {
        Monitor::Exit(this);
    }

    return true;
}

bool ScrollConfiguration::save()
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
        envyTouchPadKey->SetValue("scrollAccelerationFactor", fAccelerationFactor);
        envyTouchPadKey->SetValue("scrollIsAccelerationEnabled", boolToInt(fIsAccelerationEnabled));
        envyTouchPadKey->SetValue("scrollDeltaRatioThreshold", fDeltaRatioThreshold);
        envyTouchPadKey->SetValue("scrollInertialScrollDuration", fInertialScrollDuration);
        envyTouchPadKey->SetValue("scrollInertialScrollEasingAlgorithm", EasingAlgorithm::mapPersistentValue(fInertialScrollEasingAlgorithm));
        envyTouchPadKey->SetValue("scrollMaxZThreshold", fMaxZThreshold);
        envyTouchPadKey->SetValue("scrollSpeed", fSpeed);
		envyTouchPadKey->SetValue("reverseScrolling", boolToInt(fReverseScrolling) );

    }
    finally
    {
        Monitor::Exit(this);
    }

    return true;
}


} // end namespace