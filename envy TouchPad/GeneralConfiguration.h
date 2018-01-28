#ifndef GENERALCONFIGURATION_H
#define GENERALCONFIGURATION_H

#include "Configuration.h"

namespace envyTouchPad
{

public ref class GeneralConfiguration : public Configuration
{
public:
    bool isStartWithWindowsEnabled();

    void update(bool isStartWithWindowsEnabled);

    virtual bool load();
    virtual bool save();

private:
    bool fIsStartWithWindowsEnabled;

    static const bool kDefaultStartWithWindowsEnabled = false;
};

} // end namespace

#endif