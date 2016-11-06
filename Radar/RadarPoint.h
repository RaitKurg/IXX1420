#ifndef RADAR_POINT_H
#define RADAR_POINT_H

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

    private:

        friend class RadarModule;
        
        /**
         * distance and angle can be set only in radar module
         */
        void setDistance(const double d);
        void setAngle(const double a);

        double m_distance;
        double m_angle;

};

#endif