/*
    Description:
        RadarPoint holds distance information
    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
#ifndef _Radar_RadarPoint_h_
#define _Radar_RadarPoint_h_
        
#include "../Base/Math.h"

class RadarModule;

class RadarPoint
{

    public:
        RadarPoint();
        virtual ~RadarPoint();

        double getDistance() const;
        double getAngle() const;

        vec2<double> getCoordinates();

    private:

        /*
            Idea:
                Only RadarModule should be able to set angles and distances
        */
        friend class RadarModule;

        void setDistance(const double d);
        void setAngle(const double a);
        void calcCoordinates();

        double m_distance;
        double m_angle;

        vec2<double> m_coordinates;

};

#endif