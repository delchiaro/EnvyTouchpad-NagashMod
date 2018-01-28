#ifndef EXECUTINGSCROLLEVENT_H
#define EXECUTINGSCROLLEVENT_H

#include "Mouse.h"
#include "ScrollEvent.h"

namespace envyTouchPad
{

ref class ExecutingScrollEvent : public ScrollEvent
{
public:
    ExecutingScrollEvent(int numberOfFingersTrigger);

    virtual bool fingersPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad);
    virtual bool fingersNotPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad);
    
private:
    void resetInitialState();
    void updateInitialState(Packet^ packet);

    void releaseKeys();

    //-----------
    // attributes
    int fNumberOfFingersTrigger;
    bool fWasEvent;

    System::Collections::Generic::List<int>^ fHeldKeyboardKeys;

    long fInitialX;
    long fInitialY;
    long fInitialTimestamp;
};

} // end namespace

#endif