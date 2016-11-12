#ifndef _GuiTools_RadarListener_h_
#define _GuiTools_RadarListener_h_

#include "GuiModule.h"

class RadarListener : public EventListener
{
    private:
        GuiModule * m_guiModule;

    public:
        RadarListener(GuiModule*);

        void call();

};

#endif // _GuiTools_RadarListener_h_