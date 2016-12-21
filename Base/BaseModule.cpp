#include "BaseModule.h"

BaseModule::BaseModule()
{

}

BaseModule::~BaseModule()
{

}

void BaseModule::Execute() 
{
    Action();
    for (std::vector<EventListener*>::iterator i = m_listeners.begin(); i < m_listeners.end(); (*i)->Call(),i++);
}

void BaseModule::AddListener(EventListener * listener)
{
    m_listeners.push_back(listener);
}
