#include "MapModule.h"
#include <iostream>
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
    std::vector<RadarPoint> points = m_radarModule->getPoints();
    std::vector<Line*> lines;

    Line * activeLine = new Line();
    vec2<double> prevPoint = points[0].getCoordinates();
    vec2<double> curPoint;
    for (int i = 1; i + 1 < points.size(); ++i) {
        curPoint = points[i].getCoordinates();
        points[i+1].getCoordinates();


        vec2<double> AB = curPoint - prevPoint;
        vec2<double> BC = points[i+1].getCoordinates() - curPoint;

        double dot = vec2<double>::dot(AB, BC);
        double angleSq = (dot*dot)/(AB.lengthSq() * BC.lengthSq());
        
        std::cout << angleSq << "\n";
        if (angleSq >= 0.5) {
            activeLine->push(curPoint);
        } else {
            lines.push_back(activeLine);
            activeLine = new Line();
        }

        prevPoint = curPoint;
    }
    lines.push_back(activeLine);

}