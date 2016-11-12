#ifndef _GuiTools_GuiModule_h_
#define _GuiTools_GuiModule_h_

#include "../Base/BaseModule.h"
#include "../Radar/RadarModule.h"
#include "Window.h"

class RadarListener;

class GuiModule : public BaseModule
{

    public:
        GuiModule();
        virtual ~GuiModule();

        void setRadarModule(RadarModule*);
        bool windowNotClosed();

    protected:
        void action();

    private:
        friend class RadarListener;

        void drawLocalMap();

        Window m_window;
        RadarModule * m_radarModule;

};

#endif // _GuiTools_GuiModule_h_