#include "stdafx.h"

#include "ScrollState.h"

namespace envyTouchPad
{

ScrollState::ScrollState()
{
    clear();
}

void ScrollState::update(Packet^ packet)
{
    if (packet->getCurrentNumberOfFingers() > 0)
    {
        if (fInitialTouchTimestamp == 0)
        {
            fInitialX = packet->getX();
            fInitialY = packet->getY();
            fInitialTouchTimestamp = packet->getTimestamp();
            GetCursorPos(&fInitialMousePoint);
        }
        fMaxZ = (packet->getZ() > fMaxZ) ? packet->getZ() : fMaxZ;
    }
}

void ScrollState::updateEnd(Packet^ packet)
{
}

void ScrollState::clear()
{
    fInitialX = 0;
    fInitialY = 0;
    fInitialTouchTimestamp = 0;
    fMaxZ = 0;
}

long ScrollState::getInitialX()
{
    return fInitialX;
}

long ScrollState::getInitialY()
{
    return fInitialY;
}

long ScrollState::getInitialTouchTimestamp()
{
    return fInitialTouchTimestamp;
}

const POINT& ScrollState::getInitialMousePoint()
{
    return fInitialMousePoint;
}

long ScrollState::getMaxZ()
{
    return fMaxZ;
}

} // end namespace