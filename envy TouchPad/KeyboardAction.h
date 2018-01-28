#ifndef KEYBOARDACTION_H
#define KEYBOARDACTION_H

#include "Action.h"

namespace envyTouchPad
{

ref class KeyboardAction : public Action
{
public:
    KeyboardAction
    (
        int keyToHold,
        System::Collections::Generic::List<int>^ keySequence
    );

    KeyboardAction
    (
        System::Collections::Generic::List<int>^ keySequence
    );

    virtual void execute(System::Collections::Generic::List<int>^ heldKeyboardKeys) override;

private:
    bool fHasKeyToHold;
    int fKeyToHold;
    System::Collections::Generic::List<int>^ fKeySequence;
};

} // end namespace

#endif
