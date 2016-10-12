#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>

class EventListener
{
public:
    virtual void call() = 0;
};

class BaseModule
{

public:
    BaseModule();
    virtual ~BaseModule();
    
    void execute();
    void addListener(EventListener * listener);

protected:
    virtual void action() = 0;

private:
    std::vector<EventListener*> m_listeners;

};

#endif