#include "stdafx.h"

#include "KeyboardAction.h"

#include "Keyboard.h"

namespace envyTouchPad
{

KeyboardAction::KeyboardAction
(
    int keyToHold,
    System::Collections::Generic::List<int>^ keySequence
) : fHasKeyToHold(true),
    fKeyToHold(keyToHold),
    fKeySequence(keySequence)
{
}

KeyboardAction::KeyboardAction
(
    System::Collections::Generic::List<int>^ keySequence
) : fHasKeyToHold(false),
    fKeyToHold(0),
    fKeySequence(keySequence)
{
}

void KeyboardAction::execute(System::Collections::Generic::List<int>^ heldKeyboardKeys)
{
    if (fHasKeyToHold)
    {
        holdKeyboardKey(heldKeyboardKeys, fKeyToHold);
    }

    for (int index = 0; index < fKeySequence->Count; ++index)
    {
        int virtualKey = fKeySequence[index];
        Keyboard::holdKey(virtualKey);
    }

    for (int index = fKeySequence->Count - 1; index >= 0; --index)
    {
        int virtualKey = fKeySequence[index];
        Keyboard::releaseKey(virtualKey);
    }
}

} // end namespace