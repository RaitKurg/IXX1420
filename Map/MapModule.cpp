#include "MapModule.h"
#include <iostream>
#include <cmath>

MapModule::MapModule()
{

}

MapModule::~MapModule()
{

}

void MapModule::SetRadarModule(RadarModule * radarModule)
{
    m_radarModule = radarModule;
}

void MapModule::SetMoveModule(MoveModule * moveModule)
{
    m_moveModule = moveModule;
}

void MapModule::Action()
{
    std::vector<RadarPoint> points = m_radarModule->GetPoints();

    std::vector<Line*> lines;

    Line * activeLine = new Line();
    vec2<double> prevPoint = points[0].GetCoordinates();
    vec2<double> curPoint;

    for (int i = 1; i + 1 < points.size(); ++i) {

        curPoint = points[i].GetCoordinates();
        points[i+1].GetCoordinates();

        vec2<double> AB = curPoint - prevPoint;
        vec2<double> BC = points[i+1].GetCoordinates() - curPoint;

        double dot = vec2<double>::dot(AB, BC);
        double angleSq = (dot*dot)/(AB.LengthSq() * BC.LengthSq());

        if (angleSq >= 0.5) {
            activeLine->Push(curPoint);
        } else {
            lines.push_back(activeLine);
            activeLine = new Line();
            activeLine->Push(curPoint);
        }

        prevPoint = curPoint;
    }
    activeLine->isConnectedToNext = false;
    lines.push_back(activeLine);

    for (int i = 0; i < lines.size(); ++i) {
        lines[i]->GenerateRegressionLine();
    }

    vec2<double> intersection;
    bool connectToPrevious = false;
    vec2<double> A;
    vec2<double> B;
    for (int i = 0; i < lines.size(); ++i) {
        //A
        if (connectToPrevious) {
            A = intersection;
        } else {
            A = lines[i]->GetFirstCoordinates();
        }
        connectToPrevious = lines[i]->isConnectedToNext;
        //B
        if (connectToPrevious) {
            intersection = lines[i]->Intersect(*lines[i+1]);
            B = intersection;
        } else {
            B = lines[i]->GetLastCoordinates();
        }
        m_map.InsertSection(A, B);
    }

    // clean-up
    for (int i = 0; i < lines.size(); ++i) {
        delete lines[i];
    }

}

Map& MapModule::GetMap()
{
    return m_map;
}