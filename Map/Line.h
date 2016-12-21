/*
    Description:
        Line class containing regression line and intersection with additional methods
    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
#ifndef _Map_Line_h_
#define _Map_Line_h_

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

        /*
            Description:
                Push new point for this line
        */
        void push(vec2<double>&);

        /*
            Description:
                Generates Regression line based on pushed points
        */
        void generateRegressionLine(void);

        /*
            Return:
                Intersection point between two lines
        */
        vec2<double> intersect(const Line&);

        /*
            Return:
                Closest coordinate on the line based on first point in points array
        */
        vec2<double> getFirstCoordinates();

        /*
            Return:
                Closest coordinate on the line based on last point in points array
        */
        vec2<double> getLastCoordinates();

};

#endif // _Map_Line_h_