#ifndef TAPEVENT_H
#define TAPEVENT_H

#include "Configurations.h"
#include "Packet.h"
#include "TapState.h"
#include "TouchPad.h"

namespace envyTouchPad
{

interface class TapEvent
{
public:
    // this method will get called as the number of fingers in the packet changes
    virtual bool fingersPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad) = 0;
    // this method will get called when the fingers are lifted off the pad
    virtual bool fingersNotPresent(Configurations^ configurations, Packet^ packet, TapState& tapState, TouchPad& touchPad) = 0;

    static bool isTap(TapConfiguration^ tapConfiguration, Packet^ packet, TapState& tapState)
    {
        long timeDifference = packet->getTimestamp() - tapState.getInitialTouchTimestamp();
        return timeDifference < tapConfiguration->getSingleTapIntervalThreshold()
               &&
               tapState.getTotalDistance() < tapConfiguration->getMaxDistance()
               &&
               tapState.getMaxW() < tapConfiguration->getMaxWThreshold()
               &&
               tapState.getMaxZ() < tapConfiguration->getMaxZThreshold();
    }
};

} // end namespace
#endif