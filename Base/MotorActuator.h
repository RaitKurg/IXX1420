#ifndef MOTOR_ACTUATOR_H
#define MOTOR_ACTUATOR_H

/**
 * Communicates with pins to controll motor
 */
class MotorActuator
{

    public:
        MotorActuator();
        ~MotorActuator();

        /**
         * Makes step in clockwise direction
         */
        void stepCW();

        /**
         * Makes step in counter-clockwise direction
         */
        void stepCCW();

};

#endif