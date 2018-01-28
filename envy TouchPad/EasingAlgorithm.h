#ifndef EasingAlgorithmH
#define EasingAlgorithmH

/**
 * Robert Penner's easing algorithms.
 * BSD license
 *   http://robertpenner.com/easing/
 *
 * converted to C++ by this guy:
 *   http://www.jesusgollonet.com/blog/2007/09/24/penner-easing-cpp/
 *
 **/

namespace envyTouchPad
{

enum EasingAlgorithmType
{
    EASING_DISABLED = 0,
    CIRC_EASE_IN,
    CIRC_EASE_OUT,
    CIRC_EASE_IN_OUT,
    CUBIC_EASE_IN,
    CUBIC_EASE_OUT,
    CUBIC_EASE_IN_OUT,
    EXPO_EASE_IN,
    EXPO_EASE_OUT,
    EXPO_EASE_IN_OUT,
    LINEAR_EASE_NONE,
    LINEAR_EASE_IN,
    LINEAR_EASE_OUT,
    LINEAR_EASE_IN_OUT,
    QUAD_EASE_IN,
    QUAD_EASE_OUT,
    QUAD_EASE_IN_OUT,
    QUART_EASE_IN,
    QUART_EASE_OUT,
    QUART_EASE_IN_OUT,
    QUINT_EASE_IN,
    QUINT_EASE_OUT,
    QUINT_EASE_IN_OUT,
    SINE_EASE_IN,
    SINE_EASE_OUT,
    SINE_EASE_IN_OUT,
};

class EasingAlgorithm
{
public:
    static EasingAlgorithmType map(const int& value);
    static int mapPersistentValue(EasingAlgorithmType easingAlgorithm);
    static float apply(const EasingAlgorithmType& algorithm, float t, float b, float c, float d);
};

} // end namespace
#endif