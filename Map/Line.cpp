#include "Line.h"
#include <iostream>

void Line::push(vec2<double>& p)
{
    points.push_back(p);
}

void Line::interpolate(void)
{
    /*
    Using regression formula:
        y = mx + b
        b = ỹ - mẍ
    */
    // finding means
    double meanX = 0.0;
    double meanY = 0.0;
    double meanXY = 0.0;
    double meanXX = 0.0;
    for (auto i = points.begin(); i != points.end(); i++) {
        vec2<double> p = (*i);
        meanX += p.x;
        meanY += p.y;
        meanXY += p.x*p.y;
        meanXX += p.x*p.x;
    }
    meanX /= points.size();
    meanY /= points.size();
    meanXY /= points.size();
    meanXX /= points.size();

    // slope parameters
    double m = (meanX*meanY - meanXY)/(meanX*meanX - meanXX);
    double b = meanY - m*meanX;

    a = -m;
    b = 1.0;
    c = -b;
}

vec2<double> Line::intersect(const Line& line)
{
    vec2<double> p;

    double oneOverDotProduct = 1.0/(a*line.b - b*line.a);
    p.x = (b*line.c - line.b*c)*oneOverDotProduct;
    p.y = -(a*line.c - line.a*c)*oneOverDotProduct;

    return p;
}