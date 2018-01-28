#ifndef SCROLLEVENT_H
#define SCROLLEVENT_H

#include "Configurations.h"
#include "InertialScrollManager.h"
#include "Packet.h"
#include "ScrollState.h"
#include "TouchPad.h"

namespace envyTouchPad
{

interface class ScrollEvent
{
public:
    // this method will get called as the number of fingers in the packet changes
    virtual bool fingersPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad) = 0;
    // this method will get called when the fingers are lifted off the pad
    virtual bool fingersNotPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad) = 0;
};

} // end namespace
#endif