#pragma once

struct Point
{
    long double x, y;

    Point() : x(0), y(0) {}
    Point(long double X, long double Y) : x(X), y(Y) {}

    Point operator + (const Point& p)
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (const Point& p)
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator * (const Point& p)
    {
        return Point(x * p.x, y * p.y);
    }
    Point operator / (const Point& p)
    {
        return Point(x / p.x, y / p.y);
    }

    long double dot(Point a, Point b)
    {
        return a.x * b.x + a.y * b.y;
    }
    long double cross(Point a, Point b)
    {
        return a.x * b.y - a.y * b.x;
    }
};
