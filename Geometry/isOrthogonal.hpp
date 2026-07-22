#pragma once
#include "Point.hpp"

namespace Geometry
{
    bool isOrthogonal(const Point& a, const Point& b, const Point& c, const Point& d)
    {
        Point s1, s2;
        s1 = b - a;
        s2 = d - c;
        if(fabsl(s1.dot(s2)) < EPS) return true;
        return false;
    }
}

