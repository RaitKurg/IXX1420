#include "BaseModule.h"

BaseModule::BaseModule()
{

}

BaseModule::~BaseModule()
{

}

void BaseModule::execute()
{
    action();
    for (std::vector<EventListener*>::iterator i = m_listeners.begin(); i < m_listeners.end(); (*i)->call(),i++);
}

void BaseModule::addListener(EventListener * listener)
{
    m_listeners.push_back(listener);
}