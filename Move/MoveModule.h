#ifndef MOVE_MODULE_H
#define MOVE_MODULE_H

#include "../Base/BaseModule.h"

/**
 * Handles robot movement
 */
class MoveModule : public BaseModule
{

    public:
        MoveModule();
        virtual ~MoveModule();

    protected:

        /**
         * Logic entrypoint
         */
        void action();

    private:
    
};

#endif