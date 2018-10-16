#pragma once

#include "point.h"

class circle{
    public: 
        void setCircle(int _r, int _x0, int _y0);
        int judge(point &p);
    
    private:
        int r;
        int x0;
        int y0;
};