#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string s = "", line, source, target;
	while (getline(cin, line))
	{
		if (line == "end")
		{
			getline(cin, source);
			getline(cin, target);

			// replace
			size_t pos = s.find(source);
			while (pos != std::string::npos)
			{
				s.replace(pos, source.size(), target);
				pos = s.find(source, pos + source.size());
			}
			cout << s << endl;
			break;
		}
		else
		{
			if (s != "")
			{
				s = s + '\n';
			}
			s = s + line;
		}
	}

	return 0;
}