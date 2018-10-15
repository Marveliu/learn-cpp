#include <iostream>
using namespace std;

bool _check(string s)
{
    char c[101];
    // c point
    int p = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char temp = s[i];

        if (temp == 'A')
        {
            if (p == 0 || c[p - 1] == 'A')
            {
                continue;
            }
        }

        if (temp == 'P' || temp == 'A' || temp == 'T')
        {
            c[p] = s[i];
            p++;
        }
        else
        {
            return false;
        }
    }
    
    string r = c;
    return r == "PAT" || r == "PATA";
}

int main(int argc, const char *argv[])
{
    int n;
    string str[20];

    cin >> n;

    // read
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    // output
    for (int i = 0; i < n; i++)
    {
        if (_check(str[i]))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
