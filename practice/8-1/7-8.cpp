#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

char str[101][101];
int n, m;

bool flag[101][101];
int _next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 边界校验以及是否出现过
bool judge(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m && !flag[x][y];
}

bool dfs(int x, int y, string go, string t, int now)
{
	// 长度交验完
	if (now == (int)t.length())
	{
		return go == t;
	}

	// 初始情况
	if (now == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 找到符合条件的点
				if (str[i][j] == t[now])
				{
					flag[i][j] = true;
					if (dfs(i, j, go + str[i][j], t, now + 1))
					{
						return true;
					}
					flag[i][j] = false;
				}
			}
		}
	}
	else
	{
		// 上下左右去搜索
		for (int i = 0; i < 4; i++)
		{
			int nx = x + _next[i][0];
			int ny = y + _next[i][1];
			if (judge(nx, ny) && str[nx][ny] == t[now])
			{
				flag[nx][ny] = true;
				if (dfs(nx, ny, go + str[nx][ny], t, now + 1))
				{
					return true;
				}
				flag[nx][ny] = false;
			}
		}
	}

	return false;
}

bool search(string t)
{
	return dfs(0, 0, "", t, 0);
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> str[i][j];
				flag[i][j] = false;
			}
		}
		string target;
		cin >> target;
		if (search(target))
		{
			cout << "Exist" << endl;
		}
		else
		{
			cout << "Not exist" << endl;
		}
	}
	return 0;
}
