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
    double cosFi = 1.0;
    double sinFi = 0.0;
    double gx = 0.0;
    double gy = 0.0;

    int i = 0;
    for (std::vector<RadarPoint>::iterator p = localPoints.begin(); p != localPoints.end(); ++p) {
        double lx = p->getDistance() * sin(p->getAngle());
        double ly = p->getDistance() * cos(p->getAngle());
        globalPoints[i].x = cosFi*lx - sinFi*ly + gx;
        globalPoints[i].y = sinFi*lx + cosFi*ly + gy;
        ++i;
    }

    /**
     * group edge points
     */
    struct edge {
        std::vector<vec2> gPoints;
    };
    std::vector<edge> edges(1);

    // detect corner
    const double cmp = 1.0;
    for (int i = 0; i + 2 < globalPoints.size(); i++) {
        vec2 A = globalPoints[i];
        vec2 B = globalPoints[i+1];
        vec2 C = globalPoints[i+2];

        vec2 AC;
        AC.x = C.x - A.x;
        AC.y = C.y - A.y;

        double top = AC.x*B.x - AC.y*B.y + C.x*A.y - A.x*C.y;
        double lenSqr = AC.x*AC.x + AC.y*AC.y;
        double sqrRelation = (top*top)/(lenSqr*lenSqr);

        if (sqrRelation > cmp) {
            // handle corner
        }
    }

    std::cout << "Map action\n";
}