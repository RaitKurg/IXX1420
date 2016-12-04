#include "RadarModule.h"
#include "RadarPoint.h"
#include <cmath>

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

double RadarPoint::getAngle() const
{
    return m_angle;
}

void RadarPoint::setDistance(const double d)
{
    m_distance = d;
    calcCoordinates();
}

void RadarPoint::setAngle(const double a)
{
    m_angle = a;
    calcCoordinates();
}

void RadarPoint::calcCoordinates()
{
    m_coordinates.x = cos(m_angle)*m_distance;
    m_coordinates.y = sin(m_angle)*m_distance;
}

vec2<double> RadarPoint::getCoordinates()
{
    return m_coordinates;
}