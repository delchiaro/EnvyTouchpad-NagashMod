#ifndef ACTION_H
#define ACTION_H

#include "Keyboard.h"

namespace envyTouchPad
{

ref class Action abstract
{
public:
    virtual void execute(System::Collections::Generic::List<int>^ heldKeyboardKeys) = 0;
    
protected:
    void holdKeyboardKey(System::Collections::Generic::List<int>^ heldKeyboardKeys, int virtualKey)
    {
        if (!heldKeyboardKeys->Contains(virtualKey))
        {
            Keyboard::holdKey(virtualKey);
            heldKeyboardKeys->Add(virtualKey);
        }
    }
};

} // end namespace

#endif