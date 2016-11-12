#include <iostream>
#include "RadarModule.h"

RadarModule::RadarModule() : BaseModule()
{

    // initialize points
    m_points.resize(32);
    double angle = -1.5708; // -90 degrees
    for (int i = 0; i < 32; i++) {
        m_points[i].setAngle(angle);
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