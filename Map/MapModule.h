#ifndef MAP_MODULE_H
#define MAP_MODULE_H

#include "../Base/BaseModule.h"
#include "../Radar/RadarModule.h"
#include "../Move/MoveModule.h"
#include "Line.h"
#include <vector>
#include "Map.h"

/*
    Description:
        Handles map generation.
        Gives moving orders to move module

    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
class MapModule : public BaseModule
{

    public:
        MapModule();
        ~MapModule();

        void setRadarModule(RadarModule * radarModule);
        void setMoveModule(MoveModule * moveModule);

        Map& getMap();

    protected:
        void action();

    private:
        RadarModule * m_radarModule;
        MoveModule * m_moveModule;

        Map m_map;
    
};

#endif