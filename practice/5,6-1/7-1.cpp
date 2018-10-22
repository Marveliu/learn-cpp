#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

template <class T>
class Array
{
  public:
    vector<T> data;
    Array() { data.clear(); }
    void _sort();
    int seek(T v);
    void disp();
};

template <class T>
void Array<T>::_sort()
{
    sort(data.begin(), data.end());
}

template <class T>
int Array<T>::seek(T v)
{
    return lower_bound(data.begin(), data.end(), v) - data.begin();
}

template <class T>
void Array<T>::disp()
{
    int items = (int)data.size();
    for (int i = 0; i < items - 1; i++)
    {
        cout << data[i] << ' ';
    }
    cout << data[items - 1] << endl;
}
int main()
{
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
        getline(cin, line);
        double v = stod(line);
        cout << "arr" << id << ":" << endl;
        cout << " 原序列:";
        a.disp();
        cout << " 在arr" << id << "中的位置:" << a.seek(v) << endl;
        cout << " 排序后:";
        a._sort();
        a.disp();
        id += 1;
    }
    return 0;
}
