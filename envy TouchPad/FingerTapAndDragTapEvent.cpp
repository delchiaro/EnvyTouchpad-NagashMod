#include "stdafx.h"

#include "FingerTapAndDragTapEvent.h"

#include "Mouse.h"

namespace envyTouchPad
{

FingerTapAndDragTapEvent::FingerTapAndDragTapEvent(int numberOfFingersTrigger)
{
    fNumberOfFingersTrigger = numberOfFingersTrigger;
    clear(true);
}

bool FingerTapAndDragTapEvent::fingersPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad)
{
    fMaxNumberOfFingers = max(fMaxNumberOfFingers, packet->getCurrentNumberOfFingers());
    
    if (fIsDoubleTap)
    {
        return true;
    }

    TapConfiguration^ tapConfiguration = configurations->getTapConfiguration();
    // handle the double tap event
    if (fHasPreviousSingleClick && fMaxNumberOfFingers == fNumberOfFingersTrigger)
    {
        long previousClickTimeDifference = packet->getTimestamp() - fPreviousSingleClickTimestamp;
        if (previousClickTimeDifference < tapConfiguration->getSingleTapIntervalThreshold())
        {
            fIsDoubleTap = true;
            Mouse::buttonDown(tapConfiguration->getMouseButton(fNumberOfFingersTrigger));

            clear(true);

            return true;
        }
    }

    return false; //(fMaxNumberOfFingers == fNumberOfFingersTrigger);
}

// should always return false since we don't want the mouse cursor to move.
bool FingerTapAndDragTapEvent::fingersNotPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad)
{
    TapConfiguration^ tapConfiguration = configurations->getTapConfiguration();

    if (fIsDoubleTap)
    {
        fIsDoubleTap = false;
        Mouse::buttonUp(tapConfiguration->getMouseButton(fNumberOfFingersTrigger));
        
        // perform the second click if it was a double tap and the finger didn't move
        // and the time difference isn't too large.  otherwise, this was a double
        // tap and drag
        if 
        (
            (fMaxNumberOfFingers == fNumberOfFingersTrigger)
            && 
            TapEvent::isTap(tapConfiguration, packet, tapState)
        )
        {
            Mouse::buttonClick(tapConfiguration->getMouseButton(fNumberOfFingersTrigger));
        }

        return true;
    }
    else
    {
        if 
        (
            fMaxNumberOfFingers == fNumberOfFingersTrigger 
            && 
            TapEvent::isTap(tapConfiguration, packet, tapState)
        )
        {
            if (!fHasPreviousSingleClick)
            {
                fHasPreviousSingleClick = true;
                fPreviousSingleClickTimestamp = packet->getTimestamp();
            
                clear(false);

                return true;
            }
        }
        else if (fHasPreviousSingleClick)
        {
            long previousClickTimeDifference = packet->getTimestamp() - fPreviousSingleClickTimestamp;
            if (previousClickTimeDifference > tapConfiguration->getSingleTapIntervalThreshold())
            {
                Mouse::buttonClick(tapConfiguration->getMouseButton(fNumberOfFingersTrigger));
                clear(true);
            }
        }

        clear(false);
    }

    return false;
}

void FingerTapAndDragTapEvent::clear(bool clearPrevious)
{
    if (clearPrevious)
    {
        fHasPreviousSingleClick = false;
        fPreviousSingleClickTimestamp = 0;
    }
    fMaxNumberOfFingers = 0;
}

} // end namespace