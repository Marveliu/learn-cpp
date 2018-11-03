#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare(string x, string y)
{
	int x_len = (int)x.length();
	int y_len = (int)y.length();
	int len = (int)max(x_len, y_len);
	for (int i = 0; i < len; i++)
	{
		if (x[i % x_len] != y[i % y_len])
		{
			return x[i % x_len] > y[i % y_len];
		}
	}
	return true;
}

void print(string *ns, int n)
{
	string ans = "";
	for (int i = 0; i < n; i++)
	{
		ans += ns[i];
	}
	cout << ans << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		string *ns = new string[n];
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			ns[i] = to_string(v);
		}
		sort(ns, ns + n, compare);
		print(ns, n);
		delete[] ns;
	}

	return 0;
}
