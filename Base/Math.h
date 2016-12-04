/*
    description
        A colleciton of basic math operations

    author
        Marek Grencštein
*/

#ifndef BASE_MATH_H
#define BASE_MATH_H

template <class T>
struct vec2
{
    T x;
    T y;

    vec2() {}
    vec2(T _x, T _y)
    {
        x = _x;
        y = _y;
    }

    double lengthSq()
    {
        return x*x + y*y;
    }

    static T dot(const vec2& a, const vec2& b)
    {
        return a.x*b.x + a.y*b.y;
    }

    vec2 operator+ (const vec2& v)
    {
        vec2 r;
        r.x = x + v.x;
        r.y = y + v.y;
        return r;
    }

    vec2 operator- (const vec2& v)
    {
        vec2 r;
        r.x = x - v.x;
        r.y = y - v.y;
        return r;
    }

    void operator= (const vec2& v)
    {
        x = v.x;
        y = v.y;
    }

    void operator+= (const vec2& v)
    {
        x = x + v.x;
        y = y + v.y;
    }

    void operator-= (const vec2& v)
    {
        x = x - v.x;
        y = y - v.y;
    }

};
    
#endif