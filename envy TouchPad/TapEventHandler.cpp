#include "stdafx.h"

#include "TapEventHandler.h"

#include "DisableTapEvent.h"
#include "FingerTapEvent.h"
#include "FingerTapAndDragTapEvent.h"

namespace envyTouchPad
{

TapEventHandler::TapEventHandler()
{
    fTapEvents = gcnew System::Collections::Generic::List<TapEvent^>();
    //fTapEvents->Add(gcnew DisableTapEvent()); // disable pad
    fTapEvents->Add(gcnew FingerTapAndDragTapEvent(1)); // one finger click & drag
    fTapEvents->Add(gcnew FingerTapAndDragTapEvent(2)); // two finger click & drag
    fTapEvents->Add(gcnew FingerTapEvent(3)); // three finger click
}

bool TapEventHandler::handle(Configurations^ configurations, Packet^ packet, TouchPad& touchPad)
{
    bool wasHandled = false;

    fTapState.update(packet);
    if (packet->isFingerPresent())
    {
        for each(TapEvent^ tapEvent in static_cast<System::Collections::Generic::List<TapEvent^>^>(fTapEvents))
        {
            wasHandled |= tapEvent->fingersPresent(configurations, packet, fTapState, touchPad);
        }
        if (wasHandled)
        {
            // lock the touchpad here.
        }
    }
    else
    {
        for each(TapEvent^ tapEvent in static_cast<System::Collections::Generic::List<TapEvent^>^>(fTapEvents))
        {
            wasHandled |= tapEvent->fingersNotPresent(configurations, packet, fTapState, touchPad);
        }
        if (wasHandled)
        {
            //SetCursorPos(fTapState.getInitialMousePoint().x, fTapState.getInitialMousePoint().y);
        }

        // unlock touchpad here

        fTapState.clear();
    }

    fTapState.updateEnd(packet);

    return wasHandled;
}

} // end namespace