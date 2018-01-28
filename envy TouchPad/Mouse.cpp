#include "stdafx.h"

#include <shlwapi.h>

#include "Mouse.h"

namespace
{

class TapInfo
{
public:
	static const TapInfo* getTapInfo(envyTouchPad::MouseButton mouseButton)
	{
		return &gTapInfo[mouseButton.getPersistentValue()];
	}

    DWORD eventDown;
	DWORD eventUp;
	DWORD x;

private:
	static const TapInfo gTapInfo[];
};

const TapInfo TapInfo::gTapInfo[] =
{
	{0, 0, 0}, // disabled
	{MOUSEEVENTF_LEFTDOWN, MOUSEEVENTF_LEFTUP, 0},
	{MOUSEEVENTF_MIDDLEDOWN, MOUSEEVENTF_MIDDLEUP, 0},
	{MOUSEEVENTF_RIGHTDOWN, MOUSEEVENTF_RIGHTUP, 0},
	{MOUSEEVENTF_XDOWN, MOUSEEVENTF_XUP, XBUTTON1},
	{MOUSEEVENTF_XDOWN, MOUSEEVENTF_XUP, XBUTTON2}
};

class ClickMouseInput
{
public:
    ClickMouseInput(bool hasDownEvent, bool hasUpEvent, const TapInfo* tapInfo)
    {
        fHasDownEvent = hasDownEvent;
        fHasUpEvent = hasUpEvent;
        fTapInfo = tapInfo;
    }

    bool hasDownEvent() { return fHasDownEvent; }
    bool hasUpEvent() { return fHasUpEvent; }
    const TapInfo* getTapInfo() { return fTapInfo; }
    int getNumberOfEvents()
    {
        int count = 0;
        if (fHasDownEvent)
        {
            ++count;
        }
        if (fHasUpEvent)
        {
            ++count;
        }

        return count;
    }

private:
    bool fHasDownEvent;
    bool fHasUpEvent;
    const TapInfo* fTapInfo;
};

void clickMouse(ClickMouseInput& clickMouseInput)
{
    int numberOfEvents = clickMouseInput.getNumberOfEvents();
    if (numberOfEvents == 0)
    {
        return;
    }

    INPUT* i = new INPUT[numberOfEvents];
	ZeroMemory(i, sizeof(INPUT) * numberOfEvents);

    int index = 0;
    if (clickMouseInput.hasDownEvent())
    {
	    i[index].type = INPUT_MOUSE;
	    i[index].mi.dwFlags = clickMouseInput.getTapInfo()->eventDown;
	    i[index].mi.mouseData = clickMouseInput.getTapInfo()->x;

        ++index;
    }
    if (clickMouseInput.hasUpEvent())
    {
	    i[index].type = INPUT_MOUSE;
	    i[index].mi.dwFlags = clickMouseInput.getTapInfo()->eventUp;
	    i[index].mi.mouseData = clickMouseInput.getTapInfo()->x;
    }
	
    SendInput(numberOfEvents, i, sizeof(INPUT));

    delete i;
}

// If dwFlags contains MOUSEEVENTF_WHEEL, then dwData specifies the amount of wheel movement.
// A positive value indicates that the wheel was rotated forward, away from the user;
// a negative value indicates that the wheel was rotated backward, toward the user.
// One wheel click is defined as WHEEL_DELTA, which is 120.
//
// If dwFlags contains MOUSEEVENTF_HWHEEL, then dwData specifies the amount of wheel movement.
// A positive value indicates that the wheel was rotated to the right;
// a negative value indicates that the wheel was rotated to the left.
void scrollMouse(long wheelMovement, DWORD flags)
{
	if (wheelMovement != 0)
	{
		INPUT i;

		ZeroMemory(&i, sizeof(INPUT));
		i.type = INPUT_MOUSE;
		i.mi.dwFlags = flags;
		i.mi.mouseData = wheelMovement;
		SendInput(1, &i, sizeof(INPUT));
	}
}

long calculateWheelMovement(envyTouchPad::ScrollConfiguration^ configuration, long delta)
{
	long wheelMovement = 0;
	short reverseScrolling = -(configuration->isReverseScrollingEnabled()*2 -1);

	delta = delta * configuration->getSpeed() / 100;

	if (configuration->isAccelerationEnabled())
	{
		wheelMovement = delta * delta / configuration->getAccelerationFactor();
		if (wheelMovement < 4)
		{
			wheelMovement = 4;
		}
		if (delta < 0)
		{
			wheelMovement = -wheelMovement;
		}
	}
	else
	{
		wheelMovement = delta;
    }

	return wheelMovement*reverseScrolling;
}



} // end anonymous namespace

namespace envyTouchPad
{
MouseButton MouseButton::UNKNOWN(0);
MouseButton MouseButton::LEFT_BUTTON(1);
MouseButton MouseButton::MIDDLE_BUTTON(2);
MouseButton MouseButton::RIGHT_BUTTON(3);
MouseButton MouseButton::XONE_BUTTON(4);
MouseButton MouseButton::XTWO_BUTTON(5);

int MouseButton::getPersistentValue()
{
    return fPersistentValue;
}

MouseButton MouseButton::getMouseButton(int persistentValue)
{
    switch (persistentValue)
    {
    case 1:
        return MouseButton::LEFT_BUTTON;
    case 2:
        return MouseButton::MIDDLE_BUTTON;
    case 3:
        return MouseButton::RIGHT_BUTTON;
    case 4:
        return MouseButton::XONE_BUTTON;
    case 5:
        return MouseButton::XTWO_BUTTON;
    default:
        break;
    }

    return MouseButton::UNKNOWN;
}

MouseButton::MouseButton(int persistentValue)
{
    fPersistentValue = persistentValue;
}

void Mouse::buttonClick(MouseButton button)
{
    if (button.getPersistentValue() == MouseButton::UNKNOWN.getPersistentValue())
    {
        return;
    }

    const TapInfo* tapInfo = TapInfo::getTapInfo(button);
    ClickMouseInput input(true, true, tapInfo);
    clickMouse(input);
}

void Mouse::buttonDown(MouseButton button)
{
    if (button.getPersistentValue() == MouseButton::UNKNOWN.getPersistentValue())
    {
        return;
    }

    const TapInfo* tapInfo = TapInfo::getTapInfo(button);
    ClickMouseInput input(true, false, tapInfo);
    clickMouse(input);
}

void Mouse::buttonUp(MouseButton button)
{
    if (button.getPersistentValue() == MouseButton::UNKNOWN.getPersistentValue())
    {
        return;
    }

    const TapInfo* tapInfo = TapInfo::getTapInfo(button);
    ClickMouseInput input(false, true, tapInfo);
    clickMouse(input);
}

void Mouse::scroll(ScrollConfiguration^ configuration, long deltaX, long deltaY)
{
    long absDeltaX = abs(deltaX);
    long absDeltaY = abs(deltaY);

    if (absDeltaX > 800 || absDeltaY > 800)
	{
		return;
	}

    bool shouldXScroll = (absDeltaY == 0) || ((absDeltaX * 100) / absDeltaY) > configuration->getDeltaRatioThreshold();
    bool shouldYScroll = (absDeltaX == 0) || ((absDeltaY * 100) / absDeltaX) > configuration->getDeltaRatioThreshold();

    if (shouldXScroll)
    {
        scrollMouse(calculateWheelMovement(configuration, deltaX), MOUSEEVENTF_HWHEEL);
    }
    if (shouldYScroll)
    {
        scrollMouse(calculateWheelMovement(configuration, deltaY), MOUSEEVENTF_WHEEL);
    }
}

} // end namespace