#ifndef MOUSEACTION_H
#define MOUSEACTION_H

#include "Action.h"

namespace envyTouchPad
{

ref class MouseAction : public Action
{
public:
    MouseAction(int mouseButtonPersistentValue);

    virtual void execute(System::Collections::Generic::List<int>^ heldKeyboardKeys) override;

private:
    int fMouseButtonPersistentValue;
};

} // end namespace

#endif
