#ifndef ACTIONCONFIGURATION_H
#define ACTIONCONFIGURATION_H

#include "Configuration.h"

namespace envyTouchPad
{

public class PairedAction
{
public:
    static PairedAction DISABLED;
    static PairedAction ALT_SHIFT_TAB_AND_ALT_TAB;
    static PairedAction ALT_TAB_AND_ALT_SHIFT_TAB;
    static PairedAction WIN_TAB_AND_WIN_SHIFT_TAB;
    static PairedAction WIN_SHIFT_TAB_AND_WIN_TAB;
	static PairedAction WIN_10_SWITCH_DESKTOP;
	static PairedAction WIN_10_SWITCH_DESKTOP_REVERSED;
	static PairedAction WIN_10_SHOW_DESKTOPS;


public:
    static PairedAction getPairedAction(int persistentValue);

    int getPersistentValue();

private:
    PairedAction(int persistentValue);

    int fPersistentValue;
};

public class IndividualAction
{
public:
    static IndividualAction NONE;
    static IndividualAction MOUSE_BUTTON_X_ONE;
    static IndividualAction MOUSE_BUTTON_X_TWO;
    static IndividualAction WIN_TILDE;
    static IndividualAction EXECUTE;
	static IndividualAction WIN_10_DESKTOP_LEFT;
	static IndividualAction WIN_10_DESKTOP_RIGHT;
	static IndividualAction WIN_10_SHOW_ALL_DESKTOPS;
	static IndividualAction WIN_10_SHOW_DESKTOP;


public:
    static IndividualAction getIndividualAction(int persistentValue);

    int getPersistentValue();

private:
    IndividualAction(int persistentValue);

    int fPersistentValue;
};


public ref class ActionConfiguration : public Configuration
{
public:
    int getLeftRightTriggerDistancePercent();
    int getUpDownTriggerDistancePercent();

    PairedAction getLeftRightPairedAction();
    PairedAction getUpDownPairedAction();

    IndividualAction getLeftAction();
    IndividualAction getRightAction();
    IndividualAction getUpAction();
    IndividualAction getDownAction();

    void update
    (
        int leftRightTriggerDistancePercent,
        int upDownTriggerDistancePercent,
        int leftRightPairedActionPersistentValue,
        int upDownPairedActionPersistentValue,
        int leftIndividualActionPersistentValue,
        int rightIndividualActionPersistentValue,
        int upIndividualActionPersistentValue,
        int downIndividualActionPersistentValue
    );

    virtual bool load();
    virtual bool save();

private:
    int fLeftRightTriggerDistancePercent;
    int fUpDownTriggerDistancePercent;

    int fLeftRightPairedActionPersistentValue;
    int fUpDownPairedActionPersistentValue;
    int fLeftIndividualActionPersistentValue;
    int fRightIndividualActionPersistentValue;
    int fUpIndividualActionPersistentValue;
    int fDownIndividualActionPersistentValue;

    static const int kDefaultLeftRightTriggerDistancePercent = 10;
    static const int kDefaultUpDownTriggerDistancePercent = 10;
    static const int kDefaultLeftRightPairedActionPersistentValue = 0;
    static const int kDefaultUpDownPairedActionPersistentValue = 0;
    static const int kDefaultLeftIndividualActionPersistentValue = 0;
    static const int kDefaultRightIndividualActionPersistentValue = 0;
    static const int kDefaultUpIndividualActionPersistentValue = 0;
    static const int kDefaultDownIndividualActionPersistentValue = 0;
};

} // end namespace

#endif
