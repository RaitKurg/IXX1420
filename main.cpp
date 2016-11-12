#include "Map/MapModule.h"
#include "Move/MoveModule.h"
#include "Radar/RadarModule.h"
#include "GuiTools/Window.h"

int main(int argc, char ** argv)
{
    
    RadarModule radar;
    MoveModule move;
    MapModule map;

    map.setRadarModule(&radar);
    map.setMoveModule(&move);

    Window * window = Window::getInstance();
    SDL_Renderer * gRenderer = window->getRenderer();
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear( gRenderer );

    radar.execute();
    map.execute();
    move.execute();

    SDL_RenderPresent( gRenderer );
    try {
        while(true) {
            window->handleEvents();
        }
    } catch (int e) {}
    delete window;

    return 0;
}