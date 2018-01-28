#ifndef SCROLLCONFIGURATION_H
#define SCROLLCONFIGURATION_H

#include "Configuration.h"
#include "EasingAlgorithm.h"

namespace envyTouchPad
{

public ref class ScrollConfiguration : public Configuration
{
public:
    bool isAccelerationEnabled();
    int getAccelerationFactor();
    int getInertialScrollDuration();
    int getDeltaRatioThreshold();
    EasingAlgorithmType getInertialScrollEasingAlgorithm();
    int getMaxZThreshold();
    int getSpeed();
	bool isReverseScrollingEnabled();

    void update
    (
        int accelerationFactor, 
        bool isAccelerationEnabled,
        int deltaRatioThreshold,
        int inertialScrollDuration,
        EasingAlgorithmType inertialScrollEasingAlgorithm,
        int maxZThreshold,
        int speed,
		bool isReverseScrollingEnabled
    );

    virtual bool load();
    virtual bool save();

private:
    bool fIsAccelerationEnabled;
    int fAccelerationFactor;
    int fDeltaRatioThreshold;
    int fInertialScrollDuration;
    EasingAlgorithmType fInertialScrollEasingAlgorithm;
    int fMaxZThreshold;
    int fSpeed;
	bool fReverseScrolling;

	static const bool kDefaultReverseScrolling = false;
    static const bool kDefaultIsAccelerationEnabled = false;
    static const int kDefaultAccelerationFactor = 25;
    static const int kDefaultDeltaRatioThreshold = 50;
    static const int kDefaultInertialScrollDuration = 1000;
    static const int kDefaultInertialScrollEasingAlgorithm = EASING_DISABLED;
    static const int kDefaultMaxZThreshold = 100;
    static const int kDefaultSpeed = 100;
};

} // end namespace

#endif
