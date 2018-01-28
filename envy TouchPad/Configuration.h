#ifndef CONFIGURATION_H
#define CONFIGURATION_H

namespace envyTouchPad
{

interface class Configuration
{
public:
    virtual bool load() = 0;
    virtual bool save() = 0;
};

} // end namespace

#endif