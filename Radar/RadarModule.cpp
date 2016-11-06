#include <iostream>
#include "RadarModule.h"

RadarModule::RadarModule() : BaseModule()
{

    // initialize points
    m_points.reserve(32);
    double angle = -90.0;
    for (int i = 0; i < 32; i++) {
        m_points[i].setAngle(angle);
        angle += 5.625;
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