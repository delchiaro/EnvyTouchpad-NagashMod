#include "stdafx.h"

#include "InertialScrollManager.h"

#include <shlwapi.h>

#include "EasingAlgorithm.h"
#include "Mouse.h"

using namespace System::Diagnostics;
using namespace System::Threading;

namespace
{
using namespace envyTouchPad;

ref class Worker
{
public:
    Worker(InertialScrollData^ data, AutoResetEvent^ rEvent)
    {
        fData = data;
        fEvent = rEvent;
    }

    void work()
    {
        while (true)
        {
            bool shouldScroll;
            long deltaX;
            long deltaY;
            ScrollConfiguration^ configuration;
            Stopwatch^ stopwatch;

            fData->get(shouldScroll, deltaX, deltaY, configuration, stopwatch);

            if (shouldScroll)
            {

                long maxDuration = configuration->getInertialScrollDuration();
                int step = maxDuration / 25;

                long time = static_cast<long>(maxDuration - stopwatch->ElapsedMilliseconds);

                long x = static_cast<long>
                (
                    EasingAlgorithm::apply
                    (
                        configuration->getInertialScrollEasingAlgorithm(), 
                        static_cast<float>(time), 
                        0, 
                        static_cast<float>(deltaX), 
                        static_cast<float>(maxDuration)
                    )
                );
                long y = static_cast<long>
                (
                    EasingAlgorithm::apply
                    (
                        configuration->getInertialScrollEasingAlgorithm(), 
                        static_cast<float>(time), 
                        0, 
                        static_cast<float>(deltaY), 
                        static_cast<float>(maxDuration)
                    )
                );

                Mouse::scroll(configuration, x, y);

                if (stopwatch->ElapsedMilliseconds > maxDuration)
                {
                    fData->set(false);
                }
                else
                {
                    Sleep(step);
                }
            }
            else
            {
                fEvent->WaitOne();
            }
        }
    }

private:
    AutoResetEvent^ fEvent;
    InertialScrollData^ fData;
};

} // end anonymous namespace

namespace envyTouchPad
{

InertialScrollManager::InertialScrollManager()
{
    fData = gcnew InertialScrollData();
    fEvent = gcnew AutoResetEvent(false);
    Worker^ worker = gcnew Worker(fData, fEvent);
    fWorkerThread = gcnew Thread(gcnew ThreadStart(worker, &Worker::work));
    fWorkerThread->IsBackground = true;
    fWorkerThread->Start();
}

InertialScrollManager::~InertialScrollManager()
{
}

void InertialScrollManager::initiateScroll(long deltaX, long deltaY, ScrollConfiguration^ configuration)
{
    if (configuration->getInertialScrollEasingAlgorithm() == EASING_DISABLED)
    {
        return;
    }

    if (abs(deltaX) > WHEEL_DELTA || abs(deltaY) > WHEEL_DELTA)
    {
        fData->set(deltaX, deltaY, configuration);
        fEvent->Set();
    }
}

void InertialScrollManager::endScroll()
{
    fData->set(false);
}

} // end namespace