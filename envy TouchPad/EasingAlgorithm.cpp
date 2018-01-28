#include "stdafx.h"

#include "EasingAlgorithm.h"

#include "Math.h"

namespace
{

float easeInCirc(float t, float b , float c, float d)
{
    float var = (t/=d)*t;
    var = (var > 1) ? 1 : var;

	return -c * (sqrt(1 - var) - 1) + b;
}

float easeOutCirc(float t, float b , float c, float d)
{
    float var = (t=t/d-1)*t;
    var = (var > 1) ? 1 : var;

	return c * sqrt(1 - var) + b;
}

float easeInOutCirc(float t, float b , float c, float d)
{
    float var = t * t;
    var = (var > 1) ? 1 : var;

	if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - var) - 1) + b;

    var = t*(t-=2);
    var = (var > 1) ? 1 : var;
	return c/2 * (sqrt(1 - var) + 1) + b;
}

float easeInCubic(float t, float b , float c, float d)
{
	return c*(t/=d)*t*t + b;
}

float easeOutCubic(float t, float b , float c, float d)
{
	return c*((t=t/d-1)*t*t + 1) + b;
}

float easeInOutCubic(float t, float b , float c, float d)
{
	if ((t/=d/2) < 1) return c/2*t*t*t + b;
	return c/2*((t-=2)*t*t + 2) + b;
}

float easeInExpo(float t, float b , float c, float d)
{
	return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}

float easeOutExpo(float t, float b , float c, float d)
{
	return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
}

float easeInOutExpo(float t, float b , float c, float d)
{
	if (t==0) return b;
	if (t==d) return b+c;
	if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
	return c/2 * (-pow(2, -10 * --t) + 2) + b;
}

float easeNoneLinear(float t, float b , float c, float d)
{
	return c*t/d + b;
}

float easeInLinear(float t, float b , float c, float d)
{
	return c*t/d + b;
}

float easeOutLinear(float t, float b , float c, float d)
{
	return c*t/d + b;
}

float easeInOutLinear(float t, float b , float c, float d)
{
	return c*t/d + b;
}

float easeInQuad(float t, float b , float c, float d)
{
	return c*(t/=d)*t + b;
}

float easeOutQuad(float t, float b , float c, float d)
{
	return -c *(t/=d)*(t-2) + b;
}

float easeInOutQuad(float t, float b , float c, float d)
{
	if ((t/=d/2) < 1) return ((c/2)*(t*t)) + b;
	return -c/2 * (((t-2)*(--t)) - 1) + b;
}

float easeInQuart(float t, float b , float c, float d)
{
	return c*(t/=d)*t*t*t + b;
}

float easeOutQuart(float t, float b , float c, float d)
{
	return -c * ((t=t/d-1)*t*t*t - 1) + b;
}

float easeInOutQuart(float t, float b , float c, float d)
{
	if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
	return -c/2 * ((t-=2)*t*t*t - 2) + b;
}

float easeInQuint(float t, float b , float c, float d)
{
	return c*(t/=d)*t*t*t*t + b;
}

float easeOutQuint(float t, float b , float c, float d)
{
	return c*((t=t/d-1)*t*t*t*t + 1) + b;
}

float easeInOutQuint(float t, float b , float c, float d)
{
	if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
	return c/2*((t-=2)*t*t*t*t + 2) + b;
}

float easeInSine(float t, float b , float c, float d)
{
	return static_cast<float>(-c * cos(t/d * (3.141593/2)) + c + b);
}

float easeOutSine(float t, float b , float c, float d)
{
	return static_cast<float>(c * sin(t/d * (3.141593/2)) + b);
}

float easeInOutSine(float t, float b , float c, float d)
{
	return static_cast<float>(-c/2 * (cos(3.141593*t/d) - 1) + b);
}

} // end anonymous namespace

namespace envyTouchPad
{

EasingAlgorithmType EasingAlgorithm::map(const int& value)
{
    return static_cast<EasingAlgorithmType>(value);
}

int EasingAlgorithm::mapPersistentValue(EasingAlgorithmType easingAlgorithm)
{
    return static_cast<int>(easingAlgorithm);
}

float EasingAlgorithm::apply(const EasingAlgorithmType& algorithm, float t, float b, float c, float d)
{
    switch (algorithm)
    {
        case CIRC_EASE_IN:
            return easeInCirc(t, b, c, d);
        case CIRC_EASE_OUT:
            return easeOutCirc(t, b, c, d);
        case CIRC_EASE_IN_OUT:
            return easeInOutCirc(t, b, c, d);
        case CUBIC_EASE_IN:
            return easeInCubic(t, b, c, d);
        case CUBIC_EASE_OUT:
            return easeOutCubic(t, b, c, d);
        case CUBIC_EASE_IN_OUT:
            return easeInOutCubic(t, b, c, d);
        case EXPO_EASE_IN:
            return easeInExpo(t, b, c, d);
        case EXPO_EASE_OUT:
            return easeOutExpo(t, b, c, d);
        case EXPO_EASE_IN_OUT:
            return easeInOutExpo(t, b, c, d);
        case LINEAR_EASE_NONE:
            return easeNoneLinear(t, b, c, d);
        case LINEAR_EASE_IN:
            return easeInLinear(t, b, c, d);
        case LINEAR_EASE_OUT:
            return easeOutLinear(t, b, c, d);
        case LINEAR_EASE_IN_OUT:
            return easeInOutLinear(t, b, c, d);
        case QUAD_EASE_IN:
            return easeInQuad(t, b, c, d);
        case QUAD_EASE_OUT:
            return easeOutQuad(t, b, c, d);
        case QUAD_EASE_IN_OUT:
            return easeInOutQuad(t, b, c, d);
        case QUART_EASE_IN:
            return easeInQuart(t, b, c, d);
        case QUART_EASE_OUT:
            return easeOutQuart(t, b, c, d);
        case QUART_EASE_IN_OUT:
            return easeInOutQuart(t, b, c, d);
        case QUINT_EASE_IN:
            return easeInQuint(t, b, c, d);
        case QUINT_EASE_OUT:
            return easeOutQuint(t, b, c, d);
        case QUINT_EASE_IN_OUT:
            return easeInOutQuint(t, b, c, d);
        case SINE_EASE_IN:
            return easeInSine(t, b, c, d);
        case SINE_EASE_OUT:
            return easeOutSine(t, b, c, d);
        case SINE_EASE_IN_OUT:
            return easeInOutSine(t, b, c, d);

    default:
        return c;
    }
}

} // end namespace