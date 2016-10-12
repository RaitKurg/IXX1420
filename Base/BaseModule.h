#ifndef BASE_MODULE_H
#define BASE_MODULE_H

#include <vector>

/**
 * Abstract base event listener. All module post execute event listeners must extend this class
 */
class EventListener
{

    public:
        virtual void call() = 0;

};

/**
 * Semi-abstract base module class. All modules must extend this class
 */
class BaseModule
{

    public:
        BaseModule();
        virtual ~BaseModule();
        
        /**
         * Main module entrypoint
         */
        void execute();

        /**
         * Adds postExecute event listener to the module (events are called right before execute end)
         * 
         * @param EventListener * listener
         */
        void addListener(EventListener * listener);

    protected:

        /**
         * Abstract method (must be overriden), module specific logic entrypoint
         */
        virtual void action() = 0;

    private:
        std::vector<EventListener*> m_listeners;

};

#endif