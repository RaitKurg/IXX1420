#include "Map.h"

Map::Map()
{

}

Map::~Map()
{

}

void Map::insertSection(vec2<double> a, vec2<double> b)
{
    int ia = -1;
    int ib = -1;

    bool aFound = false;
    bool bFound = false;
    for (int i = 0; i < m_points.size(); ++i) {
        if (!aFound && a.x == m_points[i].x && a.y == m_points[i].y) {
            ia = i;
            aFound = true;
        }
        if (!bFound && b.x == m_points[i].x && b.y == m_points[i].y) {
            ib = i;
            bFound = true;
        }
        if (aFound && bFound) {
            break;
        }
    }

    if (!aFound) {
        ia = m_points.size();
        m_points.push_back(a);
    }

    if (!bFound) {
        ib = m_points.size();
        m_points.push_back(b);
    }
    m_indices.push_back(ia);
    m_indices.push_back(ib);
}

void Map::merge()
{
    /*
        Iterate through indices and perform merge for overlaps
        !Is not critical
    */
}

std::vector<vec2<double>>& Map::getPoints()
{
    return m_points;
}

std::vector<int>& Map::getIndices()
{
    return m_indices;
}