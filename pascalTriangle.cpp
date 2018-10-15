//
//  main.cpp
//  pi
//
//  Created by Marveliu on 2018/9/30.
//  Copyright © 2018年 Marveliu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

char str[1000] = "314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196";

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int id = 0;
    for (int i = 1; i <= n; i++) {
        // cout blank
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // cout 每行
        for (int j = 1; j <= i * 2 - 1; j++) {
            cout << str[id++];
        }
        cout << endl;
    }
    return 0;
}
