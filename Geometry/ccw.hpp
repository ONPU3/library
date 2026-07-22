#pragma once
#include"Point.hpp"

namespace Geometry
{
    const int COUNTER_CLOCKWISE = 1; // c - a | b
    const int CLOCKWISE = -1; // b | a - c
    const int ONLINE_BACK = 2; // c - a - b
    const int ONLINE_FRONT = -2; // a - b - c
    const int ON_SEGMENT = 0; // a - c - b

    int ccw(const Point& a, Point b, Point c)
    {
        b = b - a;
        c = c - a;
        if(b.cross(c) > EPS) return COUNTER_CLOCKWISE;
        if(b.cross(c) < -EPS) return CLOCKWISE;
        if(b.dot(c) < 0) return ONLINE_BACK;
        if(b.norm() < c.norm()) return ONLINE_FRONT;
        return ON_SEGMENT;
    }
}

