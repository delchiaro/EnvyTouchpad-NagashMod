#ifndef FINGERSCROLLEVENT_H
#define FINGERSCROLLEVENT_H

#include "ScrollEvent.h"

namespace envyTouchPad
{

ref class FingerScrollEvent : public ScrollEvent
{
public:
    FingerScrollEvent(int numberOfFingersTrigger);

    virtual bool fingersPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad);
    virtual bool fingersNotPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad);
    
private:
    void reset();

    //-----------
    // attributes
    int fNumberOfFingersTrigger;
	long fPreviousDeltaX;
	long fPreviousDeltaY;
    bool fWasEvent;
    bool fWasFingerScroll;
};

} // end namespace

#endif