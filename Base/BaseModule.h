#ifndef _Base_BaseModule_h_
#define _Base_BaseModule_h_

#include <vector>

/*
    Description:
        Abstract base event listener. All module post Execute event listeners must extend this class
*/
class EventListener
{

    public:
        virtual void Call() = 0;

};

/*
    Description:
        Semi-abstract base module class. All modules must extend this class.
    Example:
        All modules extending this class have their main entrypoint via 'void Execute();' method
        'virtual void Action();' should contain main logic on entering per module
*/
class BaseModule
{

    public:
        BaseModule();
        virtual ~BaseModule();
        
        /*
            Main module entrypoint
        */
        void Execute();

        /*
            Description:
                Adds postExecute event listener to the module (events are Called right before Execute end)
            Parameters:
                EventListener * listener
        */
        void AddListener(EventListener * listener);

    protected:

        /*
            Abstract method (must be overriden), module specific logic entrypoint
        */
        virtual void Action() = 0;

    private:
        std::vector<EventListener*> m_listeners;

};

#endif // _Base_BaseModule_h_