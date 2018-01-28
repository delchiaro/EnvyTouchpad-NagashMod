#include "stdafx.h"

#include "Configurations.h"

namespace envyTouchPad
{

Configurations::Configurations
(
    ActionConfiguration^ actionConfiguration,
    GeneralConfiguration^ generalConfiguration,
    ScrollConfiguration^ scrollConfiguration,
    TapConfiguration^ tapConfiguration
)
{
    fActionConfiguration = actionConfiguration;
    fGeneralConfiguration = generalConfiguration;
    fScrollConfiguration = scrollConfiguration;
    fTapConfiguration = tapConfiguration;
}

ActionConfiguration^ Configurations::getActionConfiguration()
{
    return fActionConfiguration;
}

GeneralConfiguration^ Configurations::getGeneralConfiguration()
{
    return fGeneralConfiguration;
}

ScrollConfiguration^ Configurations::getScrollConfiguration()
{
    return fScrollConfiguration;
}

TapConfiguration^ Configurations::getTapConfiguration()
{
    return fTapConfiguration;
}

bool Configurations::load()
{
    bool success = true;
    success &= fActionConfiguration->load();
    success &= fGeneralConfiguration->load();
    success &= fScrollConfiguration->load();
    success &= fTapConfiguration->load();
    return success;
}

bool Configurations::save()
{
    bool success = true;
    success &= fActionConfiguration->save();
    success &= fGeneralConfiguration->save();
    success &= fScrollConfiguration->save();
    success &= fTapConfiguration->save();
    return success;
}

}