#ifndef WHEELS_H
#define WHEELS_H

#include "../Base/MotorActuator.h"

/**
 * Handles robot movement
 */
class Wheels
{

    public:
        Wheels();
        ~Wheels();

    private:

        /**
         * Left motor
         */
        MotorActuator m_left;

        /**
         * Right motor
         */
        MotorActuator m_right;

};

#endif