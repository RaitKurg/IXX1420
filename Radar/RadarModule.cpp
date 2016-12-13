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
        m_points[i].setAngle(angle);
        m_points[i].setDistance(100.0);
        angle += 0.09817477;
    }

    int i = 0;
    double scale = 3.0;
    m_points[i++].setDistance(100.0*scale);
    m_points[i++].setDistance(95.0*scale);
    m_points[i++].setDistance(91.0*scale);
    m_points[i++].setDistance(89*scale);
    m_points[i++].setDistance(87*scale);
    m_points[i++].setDistance(85*scale);
    m_points[i++].setDistance(84*scale);
    m_points[i++].setDistance(85*scale);
    m_points[i++].setDistance(87*scale);
    m_points[i++].setDistance(90*scale);
    m_points[i++].setDistance(93*scale);
    m_points[i++].setDistance(83*scale);
    m_points[i++].setDistance(72*scale);
    m_points[i++].setDistance(63*scale);
    m_points[i++].setDistance(58*scale);
    m_points[i++].setDistance(53*scale);
    m_points[i++].setDistance(50*scale);
    m_points[i++].setDistance(48*scale);
    m_points[i++].setDistance(46*scale);
    m_points[i++].setDistance(44*scale);
    m_points[i++].setDistance(43*scale);
    m_points[i++].setDistance(42*scale);
    m_points[i++].setDistance(43*scale);
    m_points[i++].setDistance(42*scale);
    m_points[i++].setDistance(43*scale);
    m_points[i++].setDistance(44*scale);
    m_points[i++].setDistance(46*scale);
    m_points[i++].setDistance(47*scale);
    m_points[i++].setDistance(50*scale);
    m_points[i++].setDistance(54*scale);
    m_points[i++].setDistance(60*scale);
    m_points[i++].setDistance(67*scale);
}

RadarModule::~RadarModule()
{

}

void RadarModule::action()
{
    std::cout << "Radar action\n";
}

std::vector<RadarPoint> RadarModule::getPoints() const
{
    return m_points;
}