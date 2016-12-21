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

double RadarPoint::GetDistance() const
{
    return m_distance;
}

double RadarPoint::GetAngle() const
{
    return m_angle;
}

void RadarPoint::SetDistance(const double d)
{
    m_distance = d;
    CalcCoordinates();
}

void RadarPoint::SetAngle(const double a)
{
    m_angle = a;
    CalcCoordinates();
}

void RadarPoint::CalcCoordinates()
{
    m_coordinates.x = sin(m_angle)*m_distance;
    m_coordinates.y = cos(m_angle)*m_distance;
}

vec2<double> RadarPoint::GetCoordinates()
{
    return m_coordinates;
}