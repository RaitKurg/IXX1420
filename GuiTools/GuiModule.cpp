#include "GuiModule.h"
#include "RadarListener.h"
#include "../Radar/RadarPoint.h"
#include <cmath>

GuiModule::GuiModule()
{

}

GuiModule::~GuiModule()
{

}

void GuiModule::setRadarModule(RadarModule * radar)
{
    m_radarModule = radar;
    m_radarModule->addListener(new RadarListener(this));
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

}

void GuiModule::drawLocalMap()
{
    SDL_Renderer * renderer = m_window.getRenderer();
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    std::vector<RadarPoint> localPoints = m_radarModule->getPoints();
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xAA, 0x00, 0xFF);
    for (std::vector<RadarPoint>::iterator p = localPoints.begin(); p != localPoints.end(); ++p) {
        double lx = p->getDistance() * sin(p->getAngle());
        double ly = p->getDistance() * cos(p->getAngle());
        int x = (int)(lx*10) + Window::WIDTH / 2, y = Window::HEIGHT - (int)(ly*10) - 10;
        SDL_RenderDrawPoint(renderer, x, y);
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawPoint(renderer, Window::WIDTH/2, Window::HEIGHT - 10);

    SDL_RenderPresent(renderer);
}