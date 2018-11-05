#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

template <class T>
class Array
{
  public:
    vector<T> data;
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int h, mi, s;
        scanf("%d:%d:%d", &h, &mi, &s);

        int next;
        cin >> next;

        s = s + next;
        if (s + next >= 60)
        {
            mi = s / 60 + mi;
            s = s % 60;
            if (mi >= 60)
            {
                h = mi / 60 + h;
                mi = mi % 60;
                if (h >= 24)
                {
                    h = h % 24;
                }
            }
        }
        printf("time: %d:%d:%d\n", h, mi, s);
    }
}