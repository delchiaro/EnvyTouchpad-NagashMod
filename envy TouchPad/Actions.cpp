#include "stdafx.h"

#include "Actions.h"

#include "ActionConfiguration.h"
#include "KeyboardAction.h"
#include "Mouse.h"
#include "MouseAction.h"

#include <shlwapi.h>

namespace envyTouchPad
{

Action^ Actions::getAction
(
    int pairedActionValue,                 
    bool isFirstPairedAction,
    int actionValue
)
{
	if (pairedActionValue == PairedAction::WIN_10_SWITCH_DESKTOP.getPersistentValue())
    {
        System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();

		keySequence->Add(VK_CONTROL);
        if (!isFirstPairedAction) 
			keySequence->Add(VK_RIGHT);
		else keySequence->Add(VK_LEFT);
        
        return gcnew KeyboardAction(VK_LWIN, keySequence);
    }
	else if (pairedActionValue == PairedAction::WIN_10_SWITCH_DESKTOP_REVERSED.getPersistentValue())
    {
        System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();

		keySequence->Add(VK_CONTROL);
        if (!isFirstPairedAction) 
			keySequence->Add(VK_LEFT);
		else keySequence->Add(VK_RIGHT);
        
        return gcnew KeyboardAction(VK_LWIN, keySequence);
    }
	else if (pairedActionValue == PairedAction::WIN_10_SHOW_DESKTOPS.getPersistentValue())
    {
        System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();

        if (!isFirstPairedAction) 
		{
			keySequence->Add('D');
		}
		else
		{
			keySequence->Add(VK_TAB);
		}
        
        return gcnew KeyboardAction(VK_LWIN, keySequence);
    }
	else if (pairedActionValue == PairedAction::DISABLED.getPersistentValue())
    {
        if (actionValue == IndividualAction::NONE.getPersistentValue())
        {
        }
        else if (actionValue == IndividualAction::MOUSE_BUTTON_X_ONE.getPersistentValue())
        {
            return gcnew MouseAction(MouseButton::XONE_BUTTON.getPersistentValue());
        }
        else if (actionValue == IndividualAction::MOUSE_BUTTON_X_TWO.getPersistentValue())
        {
            return gcnew MouseAction(MouseButton::XTWO_BUTTON.getPersistentValue());
        }
        else if (actionValue == IndividualAction::WIN_TILDE.getPersistentValue())
        {
            System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();
            keySequence->Add(VK_LWIN);
            keySequence->Add(VK_OEM_3);

            return gcnew KeyboardAction(keySequence);
        }
		else if(actionValue == IndividualAction::WIN_10_DESKTOP_LEFT.getPersistentValue())
		{
			System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();
			keySequence->Add(VK_LEFT); 
			return gcnew KeyboardAction(VK_LWIN, keySequence);
		}
		else if(actionValue == IndividualAction::WIN_10_DESKTOP_RIGHT.getPersistentValue())
		{
			System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();
			keySequence->Add(VK_RIGHT); 
			return gcnew KeyboardAction(VK_LWIN, keySequence);
		}
		else if(actionValue == IndividualAction::WIN_10_SHOW_ALL_DESKTOPS.getPersistentValue())
		{
			System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();
			keySequence->Add(VK_TAB); 
			return gcnew KeyboardAction(VK_LWIN, keySequence);
		}
		else if(actionValue == IndividualAction::WIN_10_DESKTOP_RIGHT.getPersistentValue())
		{
			System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();
			keySequence->Add('D'); 
			return gcnew KeyboardAction(VK_LWIN, keySequence);
		}
        else if (actionValue == IndividualAction::EXECUTE.getPersistentValue())
        {
            // TODO
        }
    }
    else if (pairedActionValue == PairedAction::ALT_SHIFT_TAB_AND_ALT_TAB.getPersistentValue())
    {
        System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();
        
        if (isFirstPairedAction)
        {
            keySequence->Add(VK_SHIFT);
        }
        keySequence->Add(VK_TAB);

        return gcnew KeyboardAction(VK_MENU, keySequence);
    }
    else if (pairedActionValue == PairedAction::ALT_TAB_AND_ALT_SHIFT_TAB.getPersistentValue())
    {
        System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();
        
        if (!isFirstPairedAction)
        {
            keySequence->Add(VK_SHIFT);
        }
        keySequence->Add(VK_TAB);

        return gcnew KeyboardAction(VK_MENU, keySequence);
    }
    else if (pairedActionValue == PairedAction::WIN_TAB_AND_WIN_SHIFT_TAB.getPersistentValue())
    {
        System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();

        if (!isFirstPairedAction)
        {
            keySequence->Add(VK_SHIFT);
        }
        keySequence->Add(VK_TAB);

        return gcnew KeyboardAction(VK_LWIN, keySequence);
    }
    else if (pairedActionValue == PairedAction::WIN_SHIFT_TAB_AND_WIN_TAB.getPersistentValue())
    {
        System::Collections::Generic::List<int>^ keySequence = gcnew System::Collections::Generic::List<int>();

        if (isFirstPairedAction)
        {
            keySequence->Add(VK_SHIFT);
        }
        keySequence->Add(VK_TAB);

        return gcnew KeyboardAction(VK_LWIN, keySequence);
    }

    return nullptr;
}

} // end namespace