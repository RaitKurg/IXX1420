#include <iostream>
#include "RadarModule.h"

RadarModule::RadarModule() : BaseModule()
{

    // initialize points
    m_points.resize(32);
    double angle = -1.5708; // -90 degrees
    double d = 16.0;
    double dir = -1.0;
    for (int i = 0; i < 32; i++) {
        m_points[i].setAngle(angle);
        m_points[i].setDistance(d);
        if (d <= 10.0) {
            dir = 1.0;
        }
        d += dir;
        angle += 0.09817477; // 90/32 degrees
    }
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