/*
    Description:
        Handles map generation.
        Gives moving orders to move module

    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
#ifndef _Map_MapModule_h_
#define _Map_MapModule_h_

#include "../Base/BaseModule.h"
#include "../Radar/RadarModule.h"
#include "../Move/MoveModule.h"
#include "Line.h"
#include <vector>
#include "Map.h"

class MapModule : public BaseModule
{

    public:
        MapModule();
        ~MapModule();

        void setRadarModule(RadarModule * radarModule);
        void setMoveModule(MoveModule * moveModule);

        /*
            Description:
                Returns reference to Map
        */
        Map& getMap();

    protected:
        void action();

    private:
        RadarModule * m_radarModule;
        MoveModule * m_moveModule;

        Map m_map;
    
};

#endif