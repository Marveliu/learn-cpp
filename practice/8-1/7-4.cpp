#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, pair<int, string> > item;

vector<item> str;

bool cmp(item x, item y)
{
	return x.second.first != y.second.first ? x.second.first < y.second.first : x.first < y.first;
}
int main()
{
	int n;
	while (cin >> n)
	{
		str.clear();
		string s;
		getchar();
		for (int i = 0; i < n; i++)
		{
			getline(cin, s);
			if (s == "stop")
			{
				break;
			}
			else
			{
				str.push_back(item(i, make_pair((int)s.length(), s)));
			}
		}
		sort(str.begin(), str.end(), cmp);
		for (int i = 0; i < (int)str.size(); i++)
		{
			cout << str[i].second.second << endl;
		}
	}
	return 0;
}
