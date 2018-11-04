#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{

    /// formate
    // 5
    // 3 0
    int n;
    cin >> n;
    int *score = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << score[i];
    }

    
    string line;
    getline(cin, line);
    cout << line << endl;
    return 0;
}