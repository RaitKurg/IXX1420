#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

/**
 * Communicates with pins to controll ultrasonic sensor
 */
class UltrasonicSensor
{
    
    public:
        UltrasonicSensor();
        ~UltrasonicSensor();
    
        /**
         * Gets closest distance
         *
         * @return int
         */
        int getDistance();
};

#endif