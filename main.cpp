#include "Map/MapModule.h"
#include "Move/MoveModule.h"
#include "Radar/RadarModule.h"

int main(int argc, char ** argv)
{
    
    RadarModule radar;
    MoveModule move;
    MapModule map;

    map.SetRadarModule(&radar);
    map.SetMoveModule(&move);

    radar.Execute();
    map.Execute();
    move.Execute();

    return 0;
}