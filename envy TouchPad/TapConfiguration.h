#ifndef TAPCONFIGURATION_H
#define TAPCONFIGURATION_H

#include "Configuration.h"
#include "Mouse.h"

namespace envyTouchPad
{

public ref class TapConfiguration : public Configuration
{
public:
    int getMaxDistance();
    int getMaxWThreshold();
    int getMaxZThreshold();
    int getSingleTapIntervalThreshold();
    MouseButton getMouseButton(long numberOfFingers);

    void update
    (
        int singleTapIntervalThreshold,
        int maxDistance,
        int maxWThreshold,
        int maxZThreshold,
        int oneFingerMouseButtonPersistentValue,
        int twoFingerMouseButtonPersistentValue,
        int threeFingerMouseButtonPersistentValue
    );

    virtual bool load();
    virtual bool save();

private:
    int fMaxDistance;
    int fMaxWThreshold;
    int fMaxZThreshold;
    int fSingleTapIntervalThreshold;
    int fOneFingerMouseButtonPersistentValue;
    int fTwoFingerMouseButtonPersistentValue;
    int fThreeFingerMouseButtonPersistentValue;

    static const int kDefaultMaxDistance = 50;
    static const int kDefaultMaxWThreshold = 15;
    static const int kDefaultMaxZThreshold = 100;
    static const int kDefaultSingleTapIntervalThreshold = 150;
    static const int kDefaultOneFingerMouseButtonPersistentValue = MouseButton::LEFT_BUTTON.getPersistentValue();
    static const int fDefaultTwoFingerMouseButtonPersistentValue = MouseButton::RIGHT_BUTTON.getPersistentValue();
    static const int fDefaultThreeFingerMouseButtonPersistentValue = MouseButton::MIDDLE_BUTTON.getPersistentValue();
};

} // end namespace
#endif