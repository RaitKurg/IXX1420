/*
    Description:
        Handles radar data generation
    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
#ifndef _Radar_RadarModule_h_
#define _Radar_RadarModule_h_

#include "../Base/BaseModule.h"
#include "../Base/MotorActuator.h"
#include "../Base/UltrasonicSensor.h"
#include "RadarPoint.h"
#include <vector>

class RadarModule : public BaseModule
{

    public:
        RadarModule();
        virtual ~RadarModule();

        std::vector<RadarPoint> getPoints() const;

    protected:
        void action();

    private:

        /*
            Description:
                Contains radar data
        */
        std::vector<RadarPoint> m_points;

        /*
            Description:
                Ultrasonic sensor for distance
        */
        UltrasonicSensor m_sensor;

        /*
            Description:
                Motor to change ultrasonic sensor direction
        */
        MotorActuator m_motor;
    
};

#endif