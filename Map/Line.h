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

    public:
        void push(vec2<double>&);
        void interpolate(void);

        vec2<double> intersect(const Line&);

};

#endif // _Map_Edge_h_