#include "../Move/MoveModule.h"
#include "../Radar/RadarModule.h"
#include <iostream>
#include "MapModule.h"

MapModule::MapModule()
{

}

MapModule::~MapModule()
{

}

void MapModule::setRadarModule(RadarModule * radarModule)
{
    m_radarModule = radarModule;
}

void MapModule::setMoveModule(MoveModule * moveModule)
{
    m_moveModule = moveModule;
}

void MapModule::action()
{
    std::cout << "Map action\n";
}