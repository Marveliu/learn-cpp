#include "point.h"
#include "circle.h"

void circle::setCircle(int _r, int _x0, int _y0)
{
    r = _r;
    x0 = _x0;
    y0 = _y0;
}

int circle::judge(point &p)
{
    int dd = (p.getX1() - x0) * (p.getX1() - x0) + (p.getY1() - y0) * (p.getY1() - y0);
    if (dd < +r * r)
    {
        // inside
        return 1;
    }
    else
    {
        // outside
        return 0;
    }
}
