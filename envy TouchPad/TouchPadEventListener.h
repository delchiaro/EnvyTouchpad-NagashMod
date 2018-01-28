#ifndef TOUCHPADEVENTLISTENER_H
#define TOUCHPADEVENTLISTENER_H

#include <vcclr.h>

#include "Configurations.h"
#include "InertialScrollManager.h"
#include "PacketObserver.h"
#include "SynKit.h"
#include "ScrollEventHandler.h"
#include "TapEventHandler.h"
#include "TouchPad.h"

namespace envyTouchPad
{

class TouchPadEventListener : public _ISynDeviceEvents
{
public:
    TouchPadEventListener(Configurations^ configurations, TouchPad* touchPad);
    ~TouchPadEventListener();

    void addPacketObserver(PacketObserver^ packetObserver);

private:
    HRESULT STDMETHODCALLTYPE OnSynDevicePacket(long lSequence);

    void notifyPacketObservers(Packet^ packet);

    //-----------
    // attributes
    gcroot<Configurations^> fConfigurations;
    gcroot<InertialScrollManager^> fInertialScrollManager;
    gcroot<System::Collections::Generic::List<PacketObserver^>^> fPacketObservers;
    TouchPad* fTouchPad;
    ScrollEventHandler* fScrollEventHandler;
    TapEventHandler* fTapEventHandler;
};

} // end namespace

#endif