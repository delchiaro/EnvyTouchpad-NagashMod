#ifndef FINGERTAPANDDRAGTAPEVENT_H
#define FINGERTAPANDDRAGTAPEVENT_H

#include "TapEvent.h"

namespace envyTouchPad
{

ref class FingerTapAndDragTapEvent : public TapEvent
{ 
public:
    FingerTapAndDragTapEvent(int numberOfFingersTrigger);

    virtual bool fingersPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad);
    virtual bool fingersNotPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad);

private:
    void clear(bool clearPrevious);

    bool fHasPreviousSingleClick;
    bool fIsDoubleTap;
    int fMaxNumberOfFingers;
    long fPreviousSingleClickTimestamp;
    int fNumberOfFingersTrigger;
};

} // end namespace

#endif