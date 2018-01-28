#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include "ActionConfiguration.h"
#include "GeneralConfiguration.h"
#include "ScrollConfiguration.h"
#include "TapConfiguration.h"

namespace envyTouchPad
{

public ref class Configurations
{
public:
    Configurations
    (
        ActionConfiguration^ actionConfiguration,
        GeneralConfiguration^ generalConfiguration, 
        ScrollConfiguration^ scrollConfiguration,
        TapConfiguration^ tapConfiguration
    );

    ActionConfiguration^ getActionConfiguration();
    GeneralConfiguration^ getGeneralConfiguration();
    ScrollConfiguration^ getScrollConfiguration();
    TapConfiguration^ getTapConfiguration();

    bool load();
    bool save();

private:
    ActionConfiguration^ fActionConfiguration;
    GeneralConfiguration^ fGeneralConfiguration;
    ScrollConfiguration^ fScrollConfiguration;
    TapConfiguration^ fTapConfiguration;
};

} // end namespace
#endif