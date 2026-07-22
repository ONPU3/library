#pragma once
#include"Point.hpp"

namespace Geometry
{
    const int COUNTER_CLOCKWISE = 1;
    const int CLOCKWISE = -1;
    const int ONLINE_BACK = 2;
    const int ONLINE_FRONT = -2;
    const int ON_SEGMENT = 0;

    int ccw(const Point& a, Point b, Point c)
    {
        b = b - a;
        c = c - a;
        if(a.cross(b) > EPS) return COUNTER_CLOCKWISE;
        if(a.cross(b) < -EPS) return CLOCKWISE;
        if(a.dot(b) < 0) return ONLINE_BACK;
        if(a.norm() < b.norm()) return ONLINE_FRONT;
        return ON_SEGMENT;
    }
}

