#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

// strtok的用法：
// 第一步：初始化
// strtok("this is a demo"," ");
// 第二步：得到其它的子字符串
// strtok(NULL," ");
// 每执行一次第二步就可以得到一个子字符串，直到返回NULL，表示查找结束。

template <class T>
class Array
{
  public:
    vector<T> data;
};

int main()
{

    double a = 1234.34;
    string cv = to_string(a);
    cout << cv << endl;
    cout << stoi(cv) << endl;

    string line;
    int id = 1;
    while (getline(cin, line))
    {
        char *p = strtok(const_cast<char *>(line.c_str()), ", ");
        Array<double> a;
        while (p != NULL)
        {
            a.data.push_back(stod(p));
            p = strtok(NULL, ", ");
        }
    }
    return 0;
}
