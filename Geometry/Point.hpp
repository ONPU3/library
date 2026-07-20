#pragma once

const long double EPS = 1e-10;

const int COUNTER_CLOCKWISE = 1;
const int CLOCKWISE = -1;
const int ONLINE_BACK = 2;
const int ONLINE_FRONT = -2;
const int ON_SEGMENT = 0;

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
    long double norm() const 
    {
        return dot(*this);
    }
    long double abs() const 
    {
        return sqrt(norm());
    }

    int ccw(Point a, Point b) const 
    {
        a = a - *this;
        b = b - *this;
        if(a.cross(b) > EPS) return COUNTER_CLOCKWISE;
        if(a.cross(b) < -EPS) return CLOCKWISE;
        if(a.dot(b) < 0) return ONLINE_BACK;
        if(a.norm() < b.norm()) return ONLINE_FRONT;
        return ON_SEGMENT;
    }
};
