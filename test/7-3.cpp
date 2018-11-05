#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <cstdio>
using namespace std;

int Map[101][101];
int vis[101][101];
int n, m;

void dp(){
for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Map[i][j] == 1)
            {
                vis[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0)
            {
                vis[0][0] = 1;
            }
            else if (i == 0)
            {
                vis[i][j] = vis[i][j - 1];
            }
            else if (j == 0)
            {
                vis[i][j] = vis[i - 1][j];
            }
            else
            {
                vis[i][j] = vis[i - 1][j] + vis[i][j - 1];
            }
        }
    }
    cout << vis[n - 1][m - 1] << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Map[i][j];
            vis[i][j] = 0;
        }
    }

    dp();
    return 0;
}
