#pragma once

struct Point
{
    long double x, y;

    Point() : x(0), y(0) {}
    Point(long double X, long double Y) : x(X), y(Y) {}

    Point operator + (const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator * (long double k) const
    {
        return Point(x * k, y * k);
    }
    Point operator / (long double k) const
    {
        return Point(x / k, y / k);
    }

    long double dot(const Point& a) const
    {
        return x * a.x + y * a.y;
    }
    long double cross(const Point& a) const
    {
        return x * a.y - y * a.x;
    }
};
