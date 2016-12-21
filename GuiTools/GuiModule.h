/*
    Description:
        Graphical module to debug other modules
    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
#ifndef _GuiTools_GuiModule_h_
#define _GuiTools_GuiModule_h_

#include "../Base/BaseModule.h"
#include "../Radar/RadarModule.h"
#include "../Map/MapModule.h"
#include "Window.h"

class GuiModule : public BaseModule
{

    public:
        GuiModule();
        virtual ~GuiModule();

        void SetRadarModule(RadarModule*);
        void SetMapModule(MapModule*);
        bool WindowNotClosed();

    protected:
        void Action();

    private:

        void DrawLocalMap();

        Window m_window;
        RadarModule * m_radarModule;
        MapModule * m_mapModule;

};

#endif // _GuiTools_GuiModule_h_