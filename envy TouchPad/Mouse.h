#ifndef MOUSE_H
#define MOUSE_H

#include "ScrollConfiguration.h"

namespace envyTouchPad
{

class MouseButton
{
public:
    static MouseButton UNKNOWN;
    static MouseButton LEFT_BUTTON;
    static MouseButton MIDDLE_BUTTON;
    static MouseButton RIGHT_BUTTON;
    static MouseButton XONE_BUTTON;
    static MouseButton XTWO_BUTTON;

public:
    static MouseButton getMouseButton(int persistentValue);

    int getPersistentValue();

private:
    MouseButton(int persistentValue);

    int fPersistentValue;
};

class Mouse
{
public:
    static void buttonClick(MouseButton button);
    static void buttonDown(MouseButton button);
    static void buttonUp(MouseButton button);

    static void scroll(ScrollConfiguration^ configuration, long deltaX, long deltaY);
};

} // end namespace

#endif