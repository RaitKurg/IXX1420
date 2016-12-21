#include <iostream>
#include "RadarModule.h"
#include "../Map/MapModule.h"
#include <cmath>

RadarModule::RadarModule() : BaseModule()
{
    // initialize points
    m_points.resize(32);
    double angle = -1.5708; // -90 degrees
    for (int i = 0; i < 32; i++) {
        m_points[i].SetAngle(angle);
        m_points[i].SetDistance(100.0);
        angle += 0.09817477;
    }

    int i = 0;
    double scale = 3.0;
    m_points[i++].SetDistance(100.0*scale);
    m_points[i++].SetDistance(95.0*scale);
    m_points[i++].SetDistance(91.0*scale);
    m_points[i++].SetDistance(89*scale);
    m_points[i++].SetDistance(87*scale);
    m_points[i++].SetDistance(85*scale);
    m_points[i++].SetDistance(84*scale);
    m_points[i++].SetDistance(85*scale);
    m_points[i++].SetDistance(87*scale);
    m_points[i++].SetDistance(90*scale);
    m_points[i++].SetDistance(93*scale);
    m_points[i++].SetDistance(83*scale);
    m_points[i++].SetDistance(72*scale);
    m_points[i++].SetDistance(63*scale);
    m_points[i++].SetDistance(58*scale);
    m_points[i++].SetDistance(53*scale);
    m_points[i++].SetDistance(50*scale);
    m_points[i++].SetDistance(48*scale);
    m_points[i++].SetDistance(46*scale);
    m_points[i++].SetDistance(44*scale);
    m_points[i++].SetDistance(43*scale);
    m_points[i++].SetDistance(42*scale);
    m_points[i++].SetDistance(43*scale);
    m_points[i++].SetDistance(42*scale);
    m_points[i++].SetDistance(43*scale);
    m_points[i++].SetDistance(44*scale);
    m_points[i++].SetDistance(46*scale);
    m_points[i++].SetDistance(47*scale);
    m_points[i++].SetDistance(50*scale);
    m_points[i++].SetDistance(54*scale);
    m_points[i++].SetDistance(60*scale);
    m_points[i++].SetDistance(67*scale);
}

RadarModule::~RadarModule()
{

}

void RadarModule::Action()
{
    std::cout << "Radar Action\n";
}

std::vector<RadarPoint> RadarModule::GetPoints() const
{
    return m_points;
}