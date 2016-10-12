#ifndef MOVE_MODULE_H
#define MOVE_MODULE_H

#include "../Base/BaseModule.h"
#include "MoveHistory.h"
#include "Wheels.h"

/**
 * Handles robot movement
 */
class MoveModule : public BaseModule
{

    public:
        MoveModule();
        virtual ~MoveModule();

        /**
         * Returns moving history repository
         *
         * @return MoveHistory&
         */
        MoveHistory& getMoveHistory();

        /**
         * Sets orders for future movements
         */
        void setPath();

    protected:

        /**
         * Logic entrypoint
         */
        void action();

    private:

        /**
         * history repository
         */
        MoveHistory m_MoveHistory;

        /**
         * handles movement by manipulating wheels
         */
        Wheels m_wheels;
    
};

#endif