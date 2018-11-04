#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 2014/06/27 08:00:01
int main()
{
    int y, mo, d, h, mi, s;
    scanf("%d/%d/%d %d:%d:%d", &y, &mo, &d, &h, &mi, &s);
    cout << y << mo << d << h << mi << s << endl;
    return 0;
}