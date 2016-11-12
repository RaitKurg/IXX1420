#include "Map/MapModule.h"
#include "Move/MoveModule.h"
#include "Radar/RadarModule.h"
#include "GuiTools/GuiModule.h"

int main(int argc, char ** argv)
{
    
    RadarModule radar;
    MoveModule move;
    MapModule map;
    GuiModule gui;

    map.setRadarModule(&radar);
    map.setMoveModule(&move);
    gui.setRadarModule(&radar);

    radar.execute();
    map.execute();
    move.execute();

    while (gui.windowNotClosed());

    return 0;
}