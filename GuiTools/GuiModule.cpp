#include "GuiModule.h"
#include "../Radar/RadarPoint.h"
#include <cmath>
#include "../Map/Map.h"

GuiModule::GuiModule()
{

}

GuiModule::~GuiModule()
{

}

void GuiModule::SetRadarModule(RadarModule * radar)
{
    m_radarModule = radar;
}

void GuiModule::SetMapModule(MapModule * map)
{
    m_mapModule = map;
}

bool GuiModule::WindowNotClosed() {
    try {
        m_window.HandleEvents();
        return true;
    } catch (int e) {
        return false;
    }
}

void GuiModule::Action()
{
    DrawLocalMap();
}

#include <iostream>

void GuiModule::DrawLocalMap()
{
    SDL_Renderer * renderer = m_window.GetRenderer();
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    Map map = m_mapModule->GetMap();

    std::vector<vec2<double>> points = map.GetPoints();
    std::vector<int> indices = map.GetIndices();
    for (int i = 0; i + 1 < indices.size(); i += 2) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        vec2<double> A = points[indices[i]];
        vec2<double> B = points[indices[i+1]];
        SDL_RenderDrawLine(renderer,
            (int)(A.x + Window::WIDTH / 2),Window::HEIGHT - (int)(A.y) - 10,
            (int)(B.x + Window::WIDTH / 2),Window::HEIGHT - (int)(B.y) - 10
        );
    }

    std::vector<RadarPoint> localPoints = m_radarModule->GetPoints();
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xAA, 0x00, 0xFF);
    for (std::vector<RadarPoint>::iterator p = localPoints.begin(); p != localPoints.end(); ++p) {
        double lx = p->GetDistance() * sin(p->GetAngle());
        double ly = p->GetDistance() * cos(p->GetAngle());
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