#ifndef _GuiTools_GuiModule_h_
#define _GuiTools_GuiModule_h_

#include "../Base/BaseModule.h"
#include "../Radar/RadarModule.h"
#include "../Map/MapModule.h"
#include "Window.h"

class RadarListener;

class GuiModule : public BaseModule
{

    public:
        GuiModule();
        virtual ~GuiModule();

        void setRadarModule(RadarModule*);
        void setMapModule(MapModule*);
        bool windowNotClosed();

    protected:
        void action();

    private:
        friend class RadarListener;

        void drawLocalMap();

        Window m_window;
        RadarModule * m_radarModule;
        MapModule * m_mapModule;

};

#endif // _GuiTools_GuiModule_h_