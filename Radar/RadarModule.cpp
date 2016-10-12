#include <iostream>
#include "RadarModule.h"

RadarModule::RadarModule() : BaseModule()
{

}

RadarModule::~RadarModule()
{

}

void RadarModule::action()
{
    std::cout << "Radar action\n";
}

RadarMap& RadarModule::getRadarMap()
{
    return m_radarMap;
}