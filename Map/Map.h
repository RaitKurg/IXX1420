/*
    Description:
        A base class that holds methods and information about map
    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
#ifndef _Map_Map_h_
#define _Map_Map_h_

#include <vector>
#include "../Base/Math.h"

class Map
{

    public:
        
        Map();
        virtual ~Map();

        /*
            Description:
                Inserts a section of line defined by 2 points
            Parameters:
                vec2<double> a - first point
                vec2<double> b - second point
        */
        void insertSection(vec2<double>, vec2<double>);

        /*
            Description:
                Merges a sections (cleanup)
        */
        void merge();

    private:


        /*
            Description:
                A collection of points that define corners and turningpoints
        */
        std::vector<vec2<double>> m_points;

        /*
            Descriotion:
                A paired indices that make up section of line (reference of points)
        */
        std::vector<int> m_indices;

};

#endif