#include "stdafx.h"

#include "ScrollEventHandler.h"

#include "ExecutingScrollEvent.h"
#include "FingerScrollEvent.h"

namespace envyTouchPad
{

ScrollEventHandler::ScrollEventHandler(InertialScrollManager^ inertialScrollManager)
{
    fInertialScrollManager = inertialScrollManager;
    fScrollEvents = gcnew System::Collections::Generic::List<ScrollEvent^>();
    fScrollEvents->Add(gcnew FingerScrollEvent(2)); // two finger scroll
    fScrollEvents->Add(gcnew ExecutingScrollEvent(3)); // two finger scroll
}

bool ScrollEventHandler::handle(Configurations^ configurations, Packet^ packet, TouchPad& touchPad)
{
    fScrollState.update(packet);
    if (packet->isFingerPresent())
    {
        bool wasHandled = false;
        for each(ScrollEvent^ scrollEvent in static_cast<System::Collections::Generic::List<ScrollEvent^>^>(fScrollEvents))
        {
            wasHandled |= scrollEvent->fingersPresent(fInertialScrollManager, configurations, packet, fScrollState, touchPad);
        }
        if (wasHandled)
        {
            // lock the touchpad here.
        }
    }
    else
    {
        bool wasHandled = false;
        for each(ScrollEvent^ scrollEvent in static_cast<System::Collections::Generic::List<ScrollEvent^>^>(fScrollEvents))
        {
            wasHandled |= scrollEvent->fingersNotPresent(fInertialScrollManager, configurations, packet, fScrollState, touchPad);
        }
        if (wasHandled)
        {
            SetCursorPos(fScrollState.getInitialMousePoint().x, fScrollState.getInitialMousePoint().y);
        }

        // unlock touchpad here

        fScrollState.clear();
    }

    fScrollState.updateEnd(packet);

    return false;
}

} // end namespace