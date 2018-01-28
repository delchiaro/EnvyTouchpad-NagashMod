#ifndef FINGERTAPEVENT_H
#define FINGERTAPEVENT_H

#include "TapEvent.h"

namespace envyTouchPad
{

ref class FingerTapEvent : public TapEvent
{
public:
    FingerTapEvent(int numberOfFingersTrigger);

    virtual bool fingersPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad);
    virtual bool fingersNotPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad);

private:
    void clear();

    int fMaxNumberOfFingers;
    int fNumberOfFingersTrigger;
};

}

#endif