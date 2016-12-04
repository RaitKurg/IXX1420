#ifndef RADAR_POINT_H
#define RADAR_POINT_H
#include "../Base/Math.h"

class RadarModule;

/**
 * RadarPoint holds distance information
 */
class RadarPoint
{

    public:
        RadarPoint();
        virtual ~RadarPoint();

        double getDistance() const;
        double getAngle() const;

        vec2<double> getCoordinates();

    private:

        friend class RadarModule;
        
        /**
         * distance and angle can be set only in radar module
         */
        void setDistance(const double d);
        void setAngle(const double a);
        void calcCoordinates();

        double m_distance;
        double m_angle;

        vec2<double> m_coordinates;

};

#endif