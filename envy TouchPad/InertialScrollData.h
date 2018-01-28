#ifndef INERTIALSCROLLDATA_H
#define INERTIALSCROLLDATA_H

#include "ScrollConfiguration.h"

namespace envyTouchPad
{

ref class InertialScrollData
{
public:
    InertialScrollData();

    void set(bool shouldScroll);
    void set(long deltaX, long deltaY, ScrollConfiguration^ scrollConfiguration);
    void get(bool& shouldScroll, long& deltaX, long& deltaY, ScrollConfiguration^% scrollConfiguration, System::Diagnostics::Stopwatch^% stopwatch);

private:
    bool fShouldScroll;

    long fDeltaX;
    long fDeltaY;
    ScrollConfiguration^ fScrollConfiguration;

    System::Diagnostics::Stopwatch^ fStopwatch;
};

} // end namespace

#endif