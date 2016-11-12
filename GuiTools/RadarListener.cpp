#include "RadarListener.h"

RadarListener::RadarListener(GuiModule * gui)
{
    m_guiModule = gui;
}

void RadarListener::call()
{
    m_guiModule->drawLocalMap();
}