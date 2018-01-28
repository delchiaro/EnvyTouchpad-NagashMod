#include "stdafx.h"

#include "TapState.h"

namespace
{

long calculateDistance(envyTouchPad::Packet^ packet)
{
    long distance = 0;
    long deltaX = packet->getDeltaX();
    long deltaY = packet->getDeltaY();

    if (abs(deltaX) < 800)
    {
        distance += abs(deltaX);
    }
    if (abs(deltaY) < 800)
    {
        distance += abs(deltaY);
    }

    return distance;
}

} // anonymous namespace

namespace envyTouchPad
{

TapState::TapState()
{
    clear();
}

void TapState::update(Packet^ packet)
{
    if (packet->getCurrentNumberOfFingers() > 0)
    {
        if (fInitialTouchTimestamp == 0)
        {
            fInitialTouchTimestamp = packet->getTimestamp();
            fInitialNumberOfFingers = packet->getCurrentNumberOfFingers();
            GetCursorPos(&fInitialMousePoint);
        }
        
        fMaxW = (packet->getW() > fMaxW) ? packet->getW() : fMaxW;
        fMaxZ = (packet->getZ() > fMaxZ) ? packet->getZ() : fMaxZ;
        fTotalDistance += calculateDistance(packet);
    }
}

void TapState::updateEnd(Packet^ packet)
{
    fPreviousNumberOfFingers = packet->getCurrentNumberOfFingers();
}

void TapState::clear()
{
    fInitialNumberOfFingers = 0;
    fMaxW = 0;
    fMaxZ = 0;
    fPreviousNumberOfFingers = 0;
    fTotalDistance = 0;
    fInitialTouchTimestamp = 0;
}

long TapState::getInitialNumberOfFingers()
{
    return fInitialNumberOfFingers;
}

long TapState::getMaxW() 
{
    return fMaxW;
}

long TapState::getMaxZ() 
{
    return fMaxZ;
}

long TapState::getPreviousNumberOfFingers()
{
    return fPreviousNumberOfFingers;
}

long TapState::getTotalDistance()
{
    return fTotalDistance;
}

long TapState::getInitialTouchTimestamp()
{
    return fInitialTouchTimestamp;
}

const POINT& TapState::getInitialMousePoint()
{
    return fInitialMousePoint;
}

} // end namespace