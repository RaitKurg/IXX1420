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

        double GetDistance() const;
        double GetAngle() const;

        vec2<double> GetCoordinates();

    private:

        /*
            Idea:
                Only RadarModule should be able to set angles and distances
        */
        friend class RadarModule;

        void SetDistance(const double d);
        void SetAngle(const double a);
        void CalcCoordinates();

        double m_distance;
        double m_angle;

        vec2<double> m_coordinates;

};

#endif