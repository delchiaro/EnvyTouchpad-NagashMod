#ifndef KEYBOARD_H
#define KEYBOARD_H

namespace envyTouchPad
{

class Keyboard
{
public:
    static void holdKey(int virtualKey);
    static void pressKey(int virtualKey);
    static void releaseKey(int virtualKey);
};

} // end namespace

#endif