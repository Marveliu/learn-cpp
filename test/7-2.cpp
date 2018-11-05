#include <iostream>
#include <cstring>
#include <map>
#include <string>

using namespace std;

class MyMap
{
  public:
    map<string, int> data;
    void insert(string name, int no);
    void sum(string c);
};

void MyMap::insert(string name, int no)
{
    // map<string, int>::iterator it;
    // pair<string, int> p;
    // for (it = data.begin(); it != data.end(); it++)
    // {
    //     p = (pair<string, int>)*it;
    //     if (p.first == name)
    //     {
    //         data.erase(it);
    //         break;
    //         // data.insert(make_pair(name, no));
    //     }
    // }
    // data.insert(make_pair(name, no));
    data[name] = no;
}

void MyMap::sum(string c)
{
    int sum;
    pair<string, int> p;
    map<string, int>::iterator it;
    for (it = data.begin(); it != data.end(); it++)
    {
        p = (pair<string, int>)*it;
        if (strcspn(p.first.c_str(), c.c_str()) == 0)
        {
            sum += p.second;
        }
    }
    cout << sum << endl;
}

int main()
{
    /// 前缀字符串匹配
    // char a[101] = "1234567890987654321";
    // cout << strcspn(a, "123") << endl;

    MyMap map;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            string name;
            int no;
            cin >> name >> no;
            map.insert(name, no);
        }
        if (s == "sum")
        {
            string p;
            cin >> p;
            map.sum(p);
        }
    }

    return 0;
}

// 3
// insert china 5
// insert china 10
// sum c

// 4
// insert china 5
// insert china 10
// insert aanada 10
// sum c