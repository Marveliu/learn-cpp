//
//  main.cpp
//  test
//
//  Created by Marveliu on 2018/9/30.
//  Copyright © 2018年 Marveliu. All rights reserved.
//

#include <iostream>
using namespace std;

int _cal(int m)
{
    if (m % 2 == 0)
    {
        return m / 2;
    }
    else
    {
        return (3 * m + 1) / 2;
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...
    int n;
    int count = 0;
    cin >> n;
    while (n != 1)
    {
        n = _cal(n);
        count++;
    }
    cout << count << endl;
    return 0;
}
