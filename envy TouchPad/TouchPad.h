#ifndef TOUCHPAD_H
#define TOUCHPAD_H

#include "SynKit.h"

#include "Packet.h"

namespace envyTouchPad
{

class TouchPad
{
public:
    TouchPad();
    ~TouchPad();

    bool isInitialized();
    bool isSetup(System::Text::StringBuilder^ errorMessageBuilder);
    bool isAcquired();
    bool registerEventListener(_ISynDeviceEvents* eventListener);

    Packet^ getPacket();

    void acquire(bool acquire);

    long getMinX();
	long getMinY();
	long getMaxX();
	long getMaxY();

private:
    ISynAPI* fAPI;
    ISynDevice* fDevice;
    ISynPacket* fPacket;

    bool fIsInitialized;
    bool fIsAcquired;
};

} // end namespace

#endif