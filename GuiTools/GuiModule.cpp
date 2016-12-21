#include "GuiModule.h"
#include "RadarListener.h"
#include "../Radar/RadarPoint.h"
#include <cmath>
#include "../Map/Map.h"

GuiModule::GuiModule()
{

}

GuiModule::~GuiModule()
{

}

void GuiModule::setRadarModule(RadarModule * radar)
{
    m_radarModule = radar;
    //m_radarModule->addListener(new RadarListener(this));
}

void GuiModule::setMapModule(MapModule * map)
{
    m_mapModule = map;
}

bool GuiModule::windowNotClosed() {
    try {
        m_window.handleEvents();
        return true;
    } catch (int e) {
        return false;
    }
}

void GuiModule::action()
{
    drawLocalMap();
}

#include <iostream>

void GuiModule::drawLocalMap()
{
    SDL_Renderer * renderer = m_window.getRenderer();
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    Map map = m_mapModule->getMap();

    std::vector<vec2<double>> points = map.getPoints();
    std::vector<int> indices = map.getIndices();
    for (int i = 0; i + 1 < indices.size(); i += 2) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        vec2<double> A = points[indices[i]];
        vec2<double> B = points[indices[i+1]];
        SDL_RenderDrawLine(renderer,
            (int)(A.x + Window::WIDTH / 2),Window::HEIGHT - (int)(A.y) - 10,
            (int)(B.x + Window::WIDTH / 2),Window::HEIGHT - (int)(B.y) - 10
        );
    }

    std::vector<RadarPoint> localPoints = m_radarModule->getPoints();
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xAA, 0x00, 0xFF);
    for (std::vector<RadarPoint>::iterator p = localPoints.begin(); p != localPoints.end(); ++p) {
        double lx = p->getDistance() * sin(p->getAngle());
        double ly = p->getDistance() * cos(p->getAngle());
        int x = (int)(lx) + Window::WIDTH / 2, y = Window::HEIGHT - (int)(ly) - 10;
        SDL_RenderDrawPoint(renderer, x, y);
        SDL_RenderDrawPoint(renderer, x+1, y);
        SDL_RenderDrawPoint(renderer, x+1, y+1);
        SDL_RenderDrawPoint(renderer, x, y+1);
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawPoint(renderer, Window::WIDTH/2, Window::HEIGHT - 10);
    SDL_RenderPresent(renderer);
}