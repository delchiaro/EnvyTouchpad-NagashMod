#ifndef TAPEVENTHANDLER_H
#define TAPEVENTHANDLER_H

#include <vcclr.h>

#include "Configurations.h"
#include "TapEvent.h"
#include "TouchPad.h"

namespace envyTouchPad
{

class TapEventHandler
{
public:
    TapEventHandler();

    bool handle(Configurations^ configurations, Packet^ packet, TouchPad& touchPad);

private:
    TapState fTapState;
    gcroot<System::Collections::Generic::List<TapEvent^>^> fTapEvents;
};

} // end namespace

#endif