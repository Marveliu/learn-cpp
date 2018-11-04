#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    // string type
    string name;
    int l, w, c;
    cin >> name >> l >> w >> c;
    cout << name << l << w << c << endl;

    char *pStr = new char[20];
    // strcpy(pStr, name.c_str());
    strcpy(pStr, name.data());
    cout << pStr << endl;
    cout << name.length() << endl;
    for (int i = 0; i < name.length(); i++)
    {
        cout << pStr[i] << "\n";
    }

}

// Marry 22 12 5
// Marry22125