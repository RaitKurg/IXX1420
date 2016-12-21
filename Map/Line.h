#ifndef _Map_Edge_h_
#define _Map_Edge_h_

#include "../Base/Math.h"
#include <vector>

class Line
{

    private:
        // ax + by + c = 0 (line formula)
        double a;
        double b;
        double c;
        std::vector<vec2<double>> points;

        vec2<double> getLineCoordinates(vec2<double> p);


    public:

        Line() {
            isConnectedToNext = true;
        }

        /*
            Description:
                A true/false if the next line should share common point or not
        */
        bool isConnectedToNext;

        void push(vec2<double>&);
        void interpolate(void);

        vec2<double> intersect(const Line&);

        vec2<double> getFirstCoordinates();
        vec2<double> getLastCoordinates();

};

#endif // _Map_Edge_h_