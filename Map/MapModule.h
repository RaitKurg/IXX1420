#ifndef MAP_MODULE_H
#define MAP_MODULE_H

#include "../Base/BaseModule.h"

class MoveModule;
class RadarModule;

/**
 * Handles mapping
 */
class MapModule : public BaseModule
{

    public:
        MapModule();
        ~MapModule();

        void setRadarModule(RadarModule * radarModule);
        void setMoveModule(MoveModule * moveModule);

    protected:
        void action();

    private:
        RadarModule * m_radarModule;
        MoveModule * m_moveModule;
    
};

#endif