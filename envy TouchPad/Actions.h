#ifndef ACTIONS_H
#define ACTIONS_H

#include "Action.h"

namespace envyTouchPad
{

ref class Actions 
{
public:
    static Action^ getAction
    (
        int pairedActionValue,                 
        bool isFirstPairedAction,
        int actionValue
    );
};

} // end namespace

#endif