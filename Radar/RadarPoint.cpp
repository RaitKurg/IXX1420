#include "RadarModule.h"
#include "RadarPoint.h"

RadarPoint::RadarPoint()
{
    m_distance = 0.0;
}

RadarPoint::~RadarPoint()
{

}

double RadarPoint::getDistance() const
{
    return m_distance;
}

void RadarPoint::setDistance(const double d)
{
    m_distance = d;
}

void RadarPoint::setAngle(const double a)
{
    m_angle = a;
}