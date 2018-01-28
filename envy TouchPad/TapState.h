#ifndef TAPSTATE_H
#define TAPSTATE_H

#include "Packet.h"

namespace envyTouchPad
{

class TapState
{
public:
    TapState();

    // call this at the beginning of the handling method
    void update(Packet^ packet);
    // call this at the end of the handling method
    void updateEnd(Packet^ packet);
    void clear();

    long getInitialNumberOfFingers();
    long getMaxW();
    long getMaxZ();
    long getPreviousNumberOfFingers();
    long getTotalDistance();
    long getInitialTouchTimestamp();
    const POINT& getInitialMousePoint();

private:
    long fInitialNumberOfFingers;
    long fMaxW;
    long fMaxZ;
    long fPreviousNumberOfFingers;
    long fTotalDistance;
    long fInitialTouchTimestamp;
    POINT fInitialMousePoint;
};

}

#endif