#ifndef SCROLLEVENTHANDLER_H
#define SCROLLEVENTHANDLER_H

#include <vcclr.h>

#include "Configurations.h"
#include "InertialScrollManager.h"
#include "ScrollEvent.h"
#include "TouchPad.h"

namespace envyTouchPad
{

class ScrollEventHandler
{
public:
    ScrollEventHandler(InertialScrollManager^ inertialScrollManager);

    bool handle(Configurations^ configurations, Packet^ packet, TouchPad& touchPad);

private:
    gcroot<InertialScrollManager^> fInertialScrollManager;
    ScrollState fScrollState;
    gcroot<System::Collections::Generic::List<ScrollEvent^>^> fScrollEvents;
};

} // end namespace

#endif