#ifndef MAP_MODULE_H
#define MAP_MODULE_H

#include "../Base/BaseModule.h"
#include "../Radar/RadarModule.h"
#include "../Move/MoveModule.h"
#include "Line.h"
#include <vector>

struct Section
{
    vec2<double> A;
    vec2<double> B;
};

/*
    description
        handles map generation
        gives moving orders to move module

    author
        Marek Grencštein
*/
class MapModule : public BaseModule
{

    public:
        MapModule();
        ~MapModule();

        void setRadarModule(RadarModule * radarModule);
        void setMoveModule(MoveModule * moveModule);

        std::vector<Line*> getLines();
        std::vector<Section*> getSections();

    protected:
        void action();

    private:
        RadarModule * m_radarModule;
        MoveModule * m_moveModule;

        std::vector<Section*> m_sections;
        std::vector<Line*> m_lines;
    
};

#endif