#include "stdafx.h"

#include <shlwapi.h>

#include "Keyboard.h"

namespace
{

void sendKey(int virtualKey, bool isKeyUp)
{
    INPUT input[1];
    ZeroMemory(input, sizeof(input));        
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = virtualKey;        
    if (isKeyUp)
    {
        input[0].ki.dwFlags = KEYEVENTF_KEYUP;
    }

    SendInput(1, input, sizeof(INPUT));
}

} // end anonymous namespace

namespace envyTouchPad
{
void Keyboard::holdKey(int virtualKey)
{
    sendKey(virtualKey, false);
}

void Keyboard::pressKey(int virtualKey)
{
    holdKey(virtualKey);
    releaseKey(virtualKey);
}

void Keyboard::releaseKey(int virtualKey)
{
    sendKey(virtualKey, true);
}

} // end namespace