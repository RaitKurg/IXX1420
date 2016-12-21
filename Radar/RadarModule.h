/*
    Description:
        Handles radar data generation
    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
#ifndef _Radar_RadarModule_h_
#define _Radar_RadarModule_h_

#include "../Base/BaseModule.h"
#include "RadarPoint.h"
#include <vector>

class RadarModule : public BaseModule
{

    public:
        RadarModule();
        virtual ~RadarModule();

        std::vector<RadarPoint> GetPoints() const;

    protected:
        void Action();

    private:

        /*
            Description:
                Contains radar data
        */
        std::vector<RadarPoint> m_points;
    
};

#endif