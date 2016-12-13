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

std::vector<Line*> MapModule::getLines()
{
    return m_lines;
}

void MapModule::action()
{
    std::vector<RadarPoint> points = m_radarModule->getPoints();

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
            m_lines.push_back(activeLine);
            activeLine = new Line();
        }

        prevPoint = curPoint;
    }
    m_lines.push_back(activeLine);

    for (int i = 0; i < m_lines.size(); ++i) {
        m_lines[i]->interpolate();
    }

    m_sections.push_back(new Section());
    m_sections.push_back(new Section());

    m_sections[0]->A = m_lines[0]->getFirstCoordinates();
    m_sections[1]->B = m_lines[1]->getLastCoordinates();

    vec2<double> intersect = m_lines[0]->intersect(*m_lines[1]);

    m_sections[0]->B = intersect;
    m_sections[1]->A = intersect;

    std::cout << "TOTAL: " << m_lines.size() << "\n";
}

std::vector<Section*> MapModule::getSections()
{
    return m_sections;
}