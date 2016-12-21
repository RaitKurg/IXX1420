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

    map.SetRadarModule(&radar);
    map.SetMoveModule(&move);
    gui.SetRadarModule(&radar);
    gui.SetMapModule(&map);

    radar.Execute();
    map.Execute();
    move.Execute();
    gui.Execute();

    while (gui.WindowNotClosed());

    return 0;
}