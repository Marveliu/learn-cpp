#include <iostream>

#include "point.h"
#include "circle.h"

using namespace std;

int main()
{
    point p;
    circle c;

    p.setPoint(7, 7);
    c.setCircle(2, 3, 3);

    int tag = c.judge(p);
    if (tag == 1)
    {
        cout << "point in the  circle" << endl;
    }
    else
    {
        cout << "point not int the circle" << endl;
    }
    return 0;
}