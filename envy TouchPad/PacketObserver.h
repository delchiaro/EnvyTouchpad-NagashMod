#ifndef PACKETOBSERVER_H
#define PACKETOBSERVER_H

#include "Packet.h"

namespace envyTouchPad
{

interface class PacketObserver
{
public:
    virtual void update(Packet^ packet) = 0;
};

} // end namespace
#endif