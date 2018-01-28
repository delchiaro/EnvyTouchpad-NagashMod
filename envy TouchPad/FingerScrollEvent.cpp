#include "stdafx.h"

#include "FingerScrollEvent.h"

namespace envyTouchPad
{

FingerScrollEvent::FingerScrollEvent(int numberOfFingersTrigger)
{
    fNumberOfFingersTrigger = numberOfFingersTrigger;
    fWasEvent = false;
    fWasFingerScroll = false;
}

bool FingerScrollEvent::fingersPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad)
{
    if (packet->getCurrentNumberOfFingers() != fNumberOfFingersTrigger)
    {
        return false;
    }

    if (packet->isFingerInMotion())
    {
        fWasEvent = true;
        touchPad.acquire(true);
        ScrollConfiguration^ scrollConfiguration = configurations->getScrollConfiguration();

        if 
        (
            touchPad.isAcquired()
            &&
            scrollState.getMaxZ() < scrollConfiguration->getMaxZThreshold()
        )
        {
            Mouse::scroll
            (
                configurations->getScrollConfiguration(),
                packet->getDeltaX(),
                packet->getDeltaY()
            );

            fPreviousDeltaX = packet->getDeltaX();
			fPreviousDeltaY = packet->getDeltaY();
            fWasFingerScroll = true;

            return true;
        }
    }

    return false;
}

bool FingerScrollEvent::fingersNotPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad)
{
    if (fWasEvent)
    {
        touchPad.acquire(false);
        ScrollConfiguration^ scrollConfiguration = configurations->getScrollConfiguration();
        if 
        (
            fWasFingerScroll 
            && 
            scrollState.getMaxZ() < scrollConfiguration->getMaxZThreshold()
        )
        {
            POINT initialMousePoint = scrollState.getInitialMousePoint();
		    SetCursorPos(initialMousePoint.x, initialMousePoint.y);

            inertialScrollManager->initiateScroll(fPreviousDeltaX, fPreviousDeltaY, configurations->getScrollConfiguration());
        }
    }
    reset();

    return false;
}

void FingerScrollEvent::reset()
{
    fPreviousDeltaX = 0;
	fPreviousDeltaY = 0;
    fWasFingerScroll = false;
}

} // end namespace