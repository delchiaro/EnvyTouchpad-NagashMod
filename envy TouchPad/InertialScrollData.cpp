#include "stdafx.h"

#include "InertialScrollData.h"

using namespace System::Diagnostics;
using namespace System::Threading;

namespace envyTouchPad
{

InertialScrollData::InertialScrollData()
{
    fShouldScroll = false;
}

void InertialScrollData::set(bool shouldScroll)
{
    Monitor::Enter(this);
    try
    {
        fShouldScroll = shouldScroll;
    }
    finally
    {
        Monitor::Exit(this);
    }
}

void InertialScrollData::set(long deltaX, long deltaY, ScrollConfiguration^ scrollConfiguration)
{
    Monitor::Enter(this);
    try
    {
        fShouldScroll = true;
        fDeltaX = deltaX;
        fDeltaY = deltaY;
        fScrollConfiguration = scrollConfiguration;
        fStopwatch = Stopwatch::StartNew();
    }
    finally
    {
        Monitor::Exit(this);
    }
}
    
void InertialScrollData::get(bool& shouldScroll, long& deltaX, long& deltaY, ScrollConfiguration^% scrollConfiguration, System::Diagnostics::Stopwatch^% stopwatch)
{
    Monitor::Enter(this);
    try
    {
        shouldScroll = fShouldScroll;
        deltaX = fDeltaX;
        deltaY = fDeltaY;
        scrollConfiguration = fScrollConfiguration;
        stopwatch = fStopwatch;
    }
    finally
    {
        Monitor::Exit(this);
    }
}

} // end namespace