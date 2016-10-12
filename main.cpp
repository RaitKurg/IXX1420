#include "Map/MapModule.h"
#include "Move/MoveModule.h"
#include "Radar/RadarModule.h"

int main(int argc, char ** argv)
{
    
    RadarModule radar;
    MoveModule move;
    MapModule map;

    map.setRadarModule(&radar);
    map.setMoveModule(&move);

    radar.execute();
    map.execute();
    move.execute();

    return 0;
}