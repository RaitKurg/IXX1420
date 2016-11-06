#include "../Move/MoveModule.h"
#include "../Radar/RadarModule.h"
#include "MapModule.h"
#include <iostream>
#include <vector>

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
    /**
     * get global position and orientation (from move module)
     * transform radarMap into global 2D coordinates
     * detect edges
     * interpolate edges
     * get global error direction
     * give moving module orders to move
     */

    std::vector<RadarPoint> localPoints = m_radarModule->getPoints();

    std::cout << "Map action\n";
}