#ifndef INERTIALSCROLLMANAGER_H
#define INERTIALSCROLLMANAGER_H

#include "EasingAlgorithm.h"
#include "InertialScrollData.h"
#include "ScrollConfiguration.h"

namespace envyTouchPad
{

ref class InertialScrollManager
{
public:
    InertialScrollManager();
    ~InertialScrollManager();

    void initiateScroll(long deltaX, long deltaY, ScrollConfiguration^ configuration);
    void endScroll();

private:
    System::Threading::AutoResetEvent^ fEvent;
    InertialScrollData^ fData;
    System::Threading::Thread^ fWorkerThread;
};

} // end namespace
#endif