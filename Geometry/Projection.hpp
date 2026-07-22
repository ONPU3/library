#pragma once
#include"Point.hpp"

namespace Geometry
{
    Point Projection(const Point& a, const Point& b)
    {
        long double k = a.dot(b) / a.norm();
        return a * k;
    }
}
