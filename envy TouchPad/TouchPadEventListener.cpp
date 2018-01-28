#include "stdafx.h"

#include "TouchPadEventListener.h"

#include "Configurations.h"

namespace envyTouchPad
{

TouchPadEventListener::TouchPadEventListener(Configurations^ configurations, TouchPad* touchPad)
{
    fConfigurations = configurations;
    fInertialScrollManager = gcnew InertialScrollManager();
    fPacketObservers = gcnew System::Collections::Generic::List<PacketObserver^>();
    fScrollEventHandler = new ScrollEventHandler(fInertialScrollManager);
    fTapEventHandler = new TapEventHandler();
    fTouchPad = touchPad;
}

TouchPadEventListener::~TouchPadEventListener()
{
    delete fScrollEventHandler;
    delete fTapEventHandler;
}

void TouchPadEventListener::addPacketObserver(PacketObserver^ packetObserver)
{
    fPacketObservers->Add(packetObserver);
}

HRESULT STDMETHODCALLTYPE TouchPadEventListener::OnSynDevicePacket(long lSequence)
{
    Packet^ packet = fTouchPad->getPacket();

    notifyPacketObservers(packet);

    if (packet->isFingerPresent())
    {
        fInertialScrollManager->endScroll();
    }

    if (packet->isAnyPhysicalButtonPressed())
    {
        return SYN_OK;
    }
    
    if (fTapEventHandler->handle(fConfigurations, packet, *fTouchPad))
    {
        return SYN_OK;
    }

    if (fScrollEventHandler->handle(fConfigurations, packet, *fTouchPad))
    {
        return SYN_OK;
    }

    return SYN_OK;
}

void TouchPadEventListener::notifyPacketObservers(Packet^ packet)
{
    for each(PacketObserver^ packetObserver in static_cast<System::Collections::Generic::List<PacketObserver^>^>(fPacketObservers))
    {
        packetObserver->update(packet);
    }
}

} // end namespace