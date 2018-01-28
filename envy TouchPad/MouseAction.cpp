#include "stdafx.h"

#include "MouseAction.h"

#include "Mouse.h"

namespace envyTouchPad
{

MouseAction::MouseAction(int mouseButtonPersistentValue)
    : fMouseButtonPersistentValue(mouseButtonPersistentValue)
{
}

void MouseAction::execute(System::Collections::Generic::List<int>^ heldKeyboardKeys)
{
    Mouse::buttonClick(MouseButton::getMouseButton(fMouseButtonPersistentValue));
}

} // end namespace