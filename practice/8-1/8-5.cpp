#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int num[100];

int main()
{
	string str;
	while (cin >> str)
	{
		int len = (int)str.length();

		// 初始化
		for (int i = 0; i < 100; i++)
			num[i] = 0;

		// 统计
		for (int i = 0; i < len; i++)
			num[str[i] - 'A'] += 1;

		// 排序
		sort(num, num + 100);
		int ans = 0;
		bool have_odd = false;

		for (int i = 99; num[i]; i--)
		{
			if (num[i] & 1)
			{
				// 奇数
				ans += num[i] - 1;
				have_odd = true;
			}
			else
			{
				ans += num[i];
			}
		}
		ans += have_odd;
		cout << ans << endl;
	}
	return 0;
}
