#include "stdafx.h"

#include "DisableTapEvent.h"

namespace envyTouchPad
{

DisableTapEvent::DisableTapEvent()
{
    clear();
}

bool DisableTapEvent::fingersPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad)
{
    fMaxNumberOfFingers = max(fMaxNumberOfFingers, packet->getCurrentNumberOfFingers());
    fIsInRegion = packet->getX() < 1350
                  &&
                  packet->getY() > 4100;

    return false; //(fMaxNumberOfFingers == fNumberOfFingersTrigger);
}

bool DisableTapEvent::fingersNotPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad)
{
    long totalDuration = packet->getTimestamp() - tapState.getInitialTouchTimestamp();
    bool shouldToggleDisableState = fIsInRegion 
                                    && 
                                    fMaxNumberOfFingers == 1
                                    &&
                                    totalDuration > 2000; // 2s
    clear();

    if (shouldToggleDisableState)
    {
        return true;
    }

    return false;
}

void DisableTapEvent::clear()
{
    fIsInRegion = false;
    fMaxNumberOfFingers = 0;
}

} // end namespace
