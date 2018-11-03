#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int max = 0;
	while (cin >> n)
	{
		int *num = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}

		// 遍历
		int tmp = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (num[i] >= num[i + 1])
			{
				if (tmp >= max)
				{
					max = tmp;
				}
				tmp = 1;
			}
			else
			{
				tmp++;
			}
		}
		if (n != 0 && tmp >= max)
		{
			max = tmp;
		}
		cout << max << endl;
	}
	return 0;
}
