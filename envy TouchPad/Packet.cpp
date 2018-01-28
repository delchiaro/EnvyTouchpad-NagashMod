#include "stdafx.h"

#include "Packet.h"

namespace 
{
long getValue(ISynPacket* packet, SynPacketProperty packetProperty)
{
    long value;
    packet->GetProperty(packetProperty, &value);

    return value;
}

} // end anonymous namespace

namespace envyTouchPad
{

Packet::Packet(ISynPacket* packet)
{
    fPacket = packet;
}

Packet::~Packet()
{
}

long Packet::getCurrentNumberOfFingers()
{
    long currentNumberOfFingers = getExtraFingerState();
    currentNumberOfFingers &= 3;
    return currentNumberOfFingers;
}

long Packet::getInitialNumberOfFingers()
{
    long initialNumberOfFingers = getExtraFingerState();
    initialNumberOfFingers >>= 8;
    return initialNumberOfFingers;
}
    
long Packet::getTimestamp()
{
    return getValue(fPacket, SP_TimeStamp); 
}

long Packet::getW()
{
    return getValue(fPacket, SP_W); 
}

long Packet::getX()
{
    return getValue(fPacket, SP_X); 
}

long Packet::getY()
{
    return getValue(fPacket, SP_Y); 
}

long Packet::getZ()
{
    return getValue(fPacket, SP_Z); 
}

long Packet::getDeltaX()
{
    return getValue(fPacket, SP_XDelta); 
}

long Packet::getDeltaY()
{
    return getValue(fPacket, SP_YDelta); 
}

long Packet::getDeltaZ()
{
    return getValue(fPacket, SP_ZDelta); 
}

bool Packet::isAnyPhysicalButtonPressed()
{
    return hasButtonState(SF_ButtonAnyPhysical);
}

bool Packet::isFingerPresent()
{
    return hasFingerState(SF_FingerPresent);
}

bool Packet::isFingerInMotion()
{
    return hasFingerState(SF_FingerMotion);
}

bool Packet::hasButtonState(SynButtonFlags buttonFlags)
{
    long state = getValue(fPacket, SP_ButtonState); 

    return (state & buttonFlags) > 0;
}

bool Packet::hasFingerState(SynFingerFlags fingerFlags)
{
    long state = getValue(fPacket, SP_FingerState); 

    return (state & fingerFlags) > 0;
}

long Packet::getExtraFingerState()
{
    return getValue(fPacket, SP_ExtraFingerState); 
}

} // end namespace