#include "stdafx.h"

#include "ActionConfiguration.h"

using namespace Microsoft::Win32;
using namespace System;
using namespace System::Threading;

namespace 
{

int getRegistryValueAsInt(RegistryKey^ registryKey, String^ key, int defaultValue)
{
    if (registryKey == nullptr)
    {
        return defaultValue;
    }

    Object^ object = registryKey->GetValue(key, defaultValue);

    return Int32::Parse(object->ToString());
}

} // end anonymous namespace




namespace envyTouchPad
{

	PairedAction PairedAction::DISABLED(0);
	PairedAction PairedAction::ALT_SHIFT_TAB_AND_ALT_TAB(1);
	PairedAction PairedAction::ALT_TAB_AND_ALT_SHIFT_TAB(2);
	PairedAction PairedAction::WIN_TAB_AND_WIN_SHIFT_TAB(3);
	PairedAction PairedAction::WIN_SHIFT_TAB_AND_WIN_TAB(4);
	PairedAction PairedAction::WIN_10_SWITCH_DESKTOP(5);
	PairedAction PairedAction::WIN_10_SWITCH_DESKTOP_REVERSED(6);
	PairedAction PairedAction::WIN_10_SHOW_DESKTOPS(7);

	PairedAction PairedAction::getPairedAction(int persistentValue)
	{
		switch (persistentValue)
		{
		case 1:
			return PairedAction::ALT_SHIFT_TAB_AND_ALT_TAB;
		case 2:
			return PairedAction::ALT_TAB_AND_ALT_SHIFT_TAB;
		case 3:
			return PairedAction::WIN_TAB_AND_WIN_SHIFT_TAB;
		case 4:
			return PairedAction::WIN_SHIFT_TAB_AND_WIN_TAB;
		case 5:
			return PairedAction::WIN_10_SWITCH_DESKTOP;
		case 6:
			return PairedAction::WIN_10_SWITCH_DESKTOP_REVERSED;
		case 7:
			return PairedAction::WIN_10_SHOW_DESKTOPS;
		default:
			break;
		}

		return PairedAction::DISABLED;
	}

	PairedAction::PairedAction(int persistentValue)
		: fPersistentValue(persistentValue)
	{
	}

	int PairedAction::getPersistentValue()
	{
		return fPersistentValue;
	}

	IndividualAction IndividualAction::NONE(0);
	IndividualAction IndividualAction::MOUSE_BUTTON_X_ONE(1);
	IndividualAction IndividualAction::MOUSE_BUTTON_X_TWO(2);
	IndividualAction IndividualAction::WIN_TILDE(3);
	IndividualAction IndividualAction::EXECUTE(4);
	IndividualAction IndividualAction::WIN_10_DESKTOP_LEFT(5);
	IndividualAction IndividualAction::WIN_10_DESKTOP_RIGHT(6);
	IndividualAction IndividualAction::WIN_10_SHOW_ALL_DESKTOPS(7);
	IndividualAction IndividualAction::WIN_10_SHOW_DESKTOP(8);

	IndividualAction IndividualAction::getIndividualAction(int persistentValue)
	{
		switch (persistentValue)
		{
		case 1:
			return IndividualAction::MOUSE_BUTTON_X_ONE;
		case 2:
			return IndividualAction::MOUSE_BUTTON_X_TWO;
		case 3:
			return IndividualAction::WIN_TILDE;
		case 4:
			return IndividualAction::EXECUTE;
		case 5:
			return IndividualAction::WIN_10_DESKTOP_LEFT;
		case 6:
			return IndividualAction::WIN_10_DESKTOP_RIGHT;
		case 7:
			return IndividualAction::WIN_10_SHOW_ALL_DESKTOPS;
		case 8:
			return IndividualAction::WIN_10_SHOW_DESKTOP;

		default:
			break;
		}

		return IndividualAction::NONE;
	}

	IndividualAction::IndividualAction(int persistentValue)
		: fPersistentValue(persistentValue)
	{
	}

	int IndividualAction::getPersistentValue()
	{
		return fPersistentValue;
	}

	int ActionConfiguration::getLeftRightTriggerDistancePercent()
	{
		return fLeftRightTriggerDistancePercent;
	}

	int ActionConfiguration::getUpDownTriggerDistancePercent()
	{
		return fUpDownTriggerDistancePercent;
	}

	PairedAction ActionConfiguration::getLeftRightPairedAction()
	{
		return PairedAction::getPairedAction(fLeftRightPairedActionPersistentValue);
	}

	PairedAction ActionConfiguration::getUpDownPairedAction()
	{
		return PairedAction::getPairedAction(fUpDownPairedActionPersistentValue);
	}

	IndividualAction ActionConfiguration::getLeftAction()
	{
		return IndividualAction::getIndividualAction(fLeftIndividualActionPersistentValue);
	}

	IndividualAction ActionConfiguration::getRightAction()
	{
		return IndividualAction::getIndividualAction(fRightIndividualActionPersistentValue);
	}

	IndividualAction ActionConfiguration::getUpAction()
	{
		return IndividualAction::getIndividualAction(fUpIndividualActionPersistentValue);
	}

	IndividualAction ActionConfiguration::getDownAction()
	{
		return IndividualAction::getIndividualAction(fDownIndividualActionPersistentValue);
	}

	void ActionConfiguration::update
	(
		int leftRightTriggerDistancePercent,
		int upDownTriggerDistancePercent,
		int leftRightPairedActionPersistentValue,
		int upDownPairedActionPersistentValue,
		int leftIndividualActionPersistentValue,
		int rightIndividualActionPersistentValue,
		int upIndividualActionPersistentValue,
		int downIndividualActionPersistentValue
	)
	{
		Monitor::Enter(this);
		try
		{
			fLeftRightTriggerDistancePercent = leftRightTriggerDistancePercent;
			fUpDownTriggerDistancePercent = upDownTriggerDistancePercent;

			fLeftRightPairedActionPersistentValue = leftRightPairedActionPersistentValue;
			fUpDownPairedActionPersistentValue = upDownPairedActionPersistentValue;

			fLeftIndividualActionPersistentValue = leftIndividualActionPersistentValue;
			fRightIndividualActionPersistentValue = rightIndividualActionPersistentValue;
			fUpIndividualActionPersistentValue = upIndividualActionPersistentValue;
			fDownIndividualActionPersistentValue = downIndividualActionPersistentValue;
		}
		finally
		{
			Monitor::Exit(this);
		}
	}

	bool ActionConfiguration::load()
	{
		RegistryKey^ currentUserKey = Registry::CurrentUser;
		RegistryKey^ envyTouchPadKey = currentUserKey->OpenSubKey("Software")->OpenSubKey("envyTouchPad");

		Monitor::Enter(this);
		try
		{
			fLeftRightTriggerDistancePercent = getRegistryValueAsInt(envyTouchPadKey, "actionLeftRightTriggerDistancePercent", kDefaultLeftRightTriggerDistancePercent);
			fUpDownTriggerDistancePercent = getRegistryValueAsInt(envyTouchPadKey, "actionUpDownTriggerDistancePercent", kDefaultUpDownTriggerDistancePercent);

			fLeftRightPairedActionPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "actionLeftRightPair", kDefaultLeftRightPairedActionPersistentValue);
			fUpDownPairedActionPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "actionUpDownPair", kDefaultUpDownPairedActionPersistentValue);

			fLeftIndividualActionPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "actionLeft", kDefaultLeftIndividualActionPersistentValue);
			fRightIndividualActionPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "actionRight", kDefaultRightIndividualActionPersistentValue);
			fUpIndividualActionPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "actionUp", kDefaultUpIndividualActionPersistentValue);
			fDownIndividualActionPersistentValue = getRegistryValueAsInt(envyTouchPadKey, "actionDown", kDefaultDownIndividualActionPersistentValue);
		}
		finally
		{
			Monitor::Exit(this);
		}

		return true;
	}

	bool ActionConfiguration::save()
	{
		RegistryKey^ currentUserKey = Registry::CurrentUser;
		RegistryKey^ envyTouchPadKey = currentUserKey->OpenSubKey("Software", true)->CreateSubKey("envyTouchPad");

		if (envyTouchPadKey == nullptr)
		{
			return false;
		}

		Monitor::Enter(this);
		try
		{
			envyTouchPadKey->SetValue("actionLeftRightTriggerDistancePercent", fLeftRightTriggerDistancePercent);
			envyTouchPadKey->SetValue("actionUpDownTriggerDistancePercent", fUpDownTriggerDistancePercent);

			envyTouchPadKey->SetValue("actionLeftRightPair", fLeftRightPairedActionPersistentValue);
			envyTouchPadKey->SetValue("actionUpDownPair", fUpDownPairedActionPersistentValue);

			envyTouchPadKey->SetValue("actionLeft", fLeftIndividualActionPersistentValue);
			envyTouchPadKey->SetValue("actionRight", fRightIndividualActionPersistentValue);
			envyTouchPadKey->SetValue("actionUp", fUpIndividualActionPersistentValue);
			envyTouchPadKey->SetValue("actionDown", fDownIndividualActionPersistentValue);
		}
		finally
		{
			Monitor::Exit(this);
		}

		return true;
	}


} // end namespace