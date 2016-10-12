#ifndef RADAR_MODULE_H
#define RADAR_MODULE_H

#include "../Base/BaseModule.h"
#include "../Base/MotorActuator.h"
#include "../Base/UltrasonicSensor.h"
#include "RadarMap.h"

/**
 * Handles radar data generation
 */
class RadarModule : public BaseModule
{

    public:
        RadarModule();
        virtual ~RadarModule();

        /**
         * Returns local map of what radar sees
         * 
         * @return RadarMap&
         */
        RadarMap& getRadarMap();

    protected:

        /**
         * Logic entrypoint
         */
        void action();

    private:

        /**
         * Contains radar data
         */
        RadarMap m_radarMap;

        /**
         * Ultrasonic sensor for distance
         */
        UltrasonicSensor m_sensor;

        /**
         * Motor to change ultrasonic sensor direction
         */
        MotorActuator m_motor;
    
};

#endif