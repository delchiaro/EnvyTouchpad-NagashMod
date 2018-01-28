#include "stdafx.h"

#include "ExecutingScrollEvent.h"

#include "Actions.h"

#include "Keyboard.h"
#include "Mouse.h"

namespace envyTouchPad
{

ExecutingScrollEvent::ExecutingScrollEvent(int numberOfFingersTrigger)
{
    fNumberOfFingersTrigger = numberOfFingersTrigger;
    fWasEvent = false;

    fHeldKeyboardKeys = gcnew System::Collections::Generic::List<int>();
    resetInitialState();
}

bool ExecutingScrollEvent::fingersPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad)
{
    if (packet->getCurrentNumberOfFingers() != fNumberOfFingersTrigger)
    {
        return false;
    }

    if (packet->isFingerInMotion())
    {
        updateInitialState(packet);

        fWasEvent = true;
        touchPad.acquire(true);
        if (touchPad.isAcquired())
        {
            ScrollConfiguration^ scrollConfiguration = configurations->getScrollConfiguration();
            if (scrollState.getMaxZ() < scrollConfiguration->getMaxZThreshold())
            {
                ActionConfiguration^ actionConfiguration = configurations->getActionConfiguration();

			    long xDistanceThreshold = (touchPad.getMaxX() - touchPad.getMinX()) * actionConfiguration->getLeftRightTriggerDistancePercent() / 100;
			    long xDistance = packet->getX() - fInitialX;
                bool wasXTriggered = abs(xDistance) >= xDistanceThreshold;
                    
                long yDistanceThreshold = (touchPad.getMaxY() - touchPad.getMinY()) * actionConfiguration->getUpDownTriggerDistancePercent() / 100;
			    long yDistance = packet->getY() - fInitialY;
                bool wasYTriggered = abs(yDistance) >= yDistanceThreshold;
			    
                int pairedActionValue = PairedAction::DISABLED.getPersistentValue();
                bool isFirstPairedAction = false;
                int actionValue = IndividualAction::NONE.getPersistentValue();

                // horizontal scroll
			    if (wasXTriggered && abs(xDistance) >= abs(yDistance))
			    {
                    resetInitialState();

                    pairedActionValue = actionConfiguration->getLeftRightPairedAction().getPersistentValue();
                    isFirstPairedAction = xDistance < 0;
                    actionValue = (xDistance < 0) ? actionConfiguration->getLeftAction().getPersistentValue() : actionConfiguration->getRightAction().getPersistentValue();

			    }
                else if (wasYTriggered && abs(xDistance) <= abs(yDistance))
			    {
                    resetInitialState();

                    pairedActionValue = actionConfiguration->getUpDownPairedAction().getPersistentValue();
                    isFirstPairedAction = yDistance >= 0;
                    actionValue = (yDistance < 0) ? actionConfiguration->getDownAction().getPersistentValue() : actionConfiguration->getUpAction().getPersistentValue();
			    }

                Action^ action = Actions::getAction(pairedActionValue, isFirstPairedAction, actionValue);
                if (action != nullptr)
                {
                    action->execute(fHeldKeyboardKeys);
                }
            }
        }

        return true;
    }

    return false;
}

bool ExecutingScrollEvent::fingersNotPresent(InertialScrollManager^ inertialScrollManager, Configurations^ configurations, Packet^ packet, ScrollState& scrollState, TouchPad& touchPad)
{
    resetInitialState();

    if (fWasEvent)
	{
        fWasEvent = false;
        touchPad.acquire(false);
        releaseKeys();

        return true;
	}

    return false;
}

void ExecutingScrollEvent::resetInitialState()
{
    fInitialX = -1;
    fInitialY = -1;
    fInitialTimestamp = -1;
}

void ExecutingScrollEvent::updateInitialState(Packet^ packet)
{
    if (fInitialX == -1)
    {
        fInitialX = packet->getX();
    }
    if (fInitialY == -1)
    {
        fInitialY = packet->getY();
    }
    if (fInitialTimestamp == -1)
    {
        fInitialTimestamp = packet->getTimestamp();
    }
}

void ExecutingScrollEvent::releaseKeys()
{
    for each(int heldVirtualKey in fHeldKeyboardKeys)
    {
        Keyboard::releaseKey(heldVirtualKey);
    }
    fHeldKeyboardKeys->Clear();
}

} // end namespace