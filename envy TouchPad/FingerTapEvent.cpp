#include "stdafx.h"

#include <algorithm>

#include "Mouse.h"
#include "FingerTapEvent.h"

namespace envyTouchPad
{

FingerTapEvent::FingerTapEvent(int numberOfFingersTrigger)
{
    fNumberOfFingersTrigger = numberOfFingersTrigger;
}

bool FingerTapEvent::fingersPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad)
{
    fMaxNumberOfFingers = max(fMaxNumberOfFingers, packet->getCurrentNumberOfFingers());

    return false; //(fMaxNumberOfFingers == fNumberOfFingersTrigger);
}

bool FingerTapEvent::fingersNotPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad)
{
    TapConfiguration^ tapConfiguration = configurations->getTapConfiguration();

    if 
    (
        fMaxNumberOfFingers == fNumberOfFingersTrigger 
        &&
        TapEvent::isTap(tapConfiguration, packet, tapState)
    )
    {
        Mouse::buttonClick(tapConfiguration->getMouseButton(fNumberOfFingersTrigger));
        clear();
        return true;
    }

    clear();
    return false;
}

void FingerTapEvent::clear()
{
    fMaxNumberOfFingers = 0;
}

} // end namespace
