#ifndef SCROLLSTATE_H
#define SCROLLSTATE_H

#include "Packet.h"

namespace envyTouchPad
{

class ScrollState
{
public:
    ScrollState();

    // call this at the beginning of the handling method
    void update(Packet^ packet);
    // call this at the end of the handling method
    void updateEnd(Packet^ packet);
    void clear();

    long getInitialX();
    long getInitialY();
    long getInitialTouchTimestamp();
    const POINT& getInitialMousePoint();
    long getMaxZ();

private:
    long fInitialX;
    long fInitialY;
    long fInitialTouchTimestamp;
    POINT fInitialMousePoint;
    long fMaxZ;
};

}

#endif