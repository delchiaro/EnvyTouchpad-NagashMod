#ifndef PACKET_H
#define PACKET_H

#include "SynKit.h"

namespace envyTouchPad
{

public ref class Packet
{
public:
    Packet(ISynPacket* packet);
    ~Packet();

    long getCurrentNumberOfFingers();
    long getInitialNumberOfFingers();
    
    long getTimestamp();
    
    long getW();
    long getX();
    long getY();
    long getZ();

    long getDeltaX();
    long getDeltaY();
    long getDeltaZ();

    bool isAnyPhysicalButtonPressed();
    bool isFingerPresent();
    bool isFingerInMotion();

private:
    long getExtraFingerState();
    bool hasButtonState(SynButtonFlags buttonFlags);
    bool hasFingerState(SynFingerFlags fingerFlags);

    ISynPacket* fPacket;
};

} // end namespace
#endif