#pragma once
#include "Point.hpp"
#include "Projection.hpp"

namespace Geometry
{
    Point Reflection(const Point& a, const Point& b)
    {
        return (Projection(a, b) - b) * 2 + b;
    }
}
