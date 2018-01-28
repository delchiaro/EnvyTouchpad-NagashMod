#ifndef DISABLETAPEVENT_H
#define DISABLETAPEVENT_H

#include "TapEvent.h"

namespace envyTouchPad
{

ref class DisableTapEvent : public TapEvent
{
public:
    DisableTapEvent();

    virtual bool fingersPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad);
    virtual bool fingersNotPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad);
    
private:
    void clear();

    bool fIsInRegion;
    long fMaxNumberOfFingers;
};

} // end namespace

#endif