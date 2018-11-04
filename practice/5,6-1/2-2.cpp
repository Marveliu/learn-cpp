#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <typename T>
void Max(T a, T b, T &c) { c = a + b; }

int main()
{
    // int x, y; char z;
    // double x, y,z;
    float x, y, z;
    cin >> x >> y >> z;
    Max(x, y, z);
    cout << x << y << z;
}
// 假设有函数模板定义如下： 　template 　Max( T a, T b ,T &c) { c　= a + b ; } 下列选项正确的是( )。 (2分)
// 类型要一致
// 1 3 2
// 134