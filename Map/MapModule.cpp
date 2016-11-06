#include "../Move/MoveModule.h"
#include "../Radar/RadarModule.h"
#include "MapModule.h"
#include <iostream>
#include <vector>
#include <cmath>

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
    
    /**
     * globalize
     */
    struct vec2 {
        double x;
        double y;
    };

    std::vector<RadarPoint> localPoints = m_radarModule->getPoints();
    std::vector<vec2> globalPoints(localPoints.size());

    double cosFi = 0.0;
    double sinFi = 0.0;
    double gx = 0.0;
    double gy = 0.0;

    int i = 0;
    for (std::vector<RadarPoint>::iterator p = localPoints.begin(); p != localPoints.end(); ++p) {
        double lx = p->getDistance() * cos(p->getAngle());
        double ly = p->getDistance() * sin(p->getAngle());

        globalPoints[i].x = cosFi*lx - sinFi*ly + gx;
        globalPoints[i].y = sinFi*lx + cosFi*ly + gy;
        ++i;
    }

    std::cout << "Map action\n";
}