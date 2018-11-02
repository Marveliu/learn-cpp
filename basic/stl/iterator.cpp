#include <iostream>
#include <list>
#include <deque>
#include <iterator>
using namespace std;

int main()
{

    // 逆向迭代器
    list<int> lt; //创建一个list列表容器
    for (int i = 0; i < 10; i++)
        lt.push_back(i + 1); //向容器中插入元素

    list<int>::iterator it; //定义一个list迭代器
    for (it = lt.begin(); it != lt.end(); it++)
        cout << *it << " ";
    cout << endl;
    list<int>::reverse_iterator itr(it);             //将it转换为逆向迭代器
    for (itr = lt.rbegin(); itr != lt.rend(); itr++) //itr++是上行移动
        cout << *itr << " ";
    cout << endl;

    int arr[] = {1, 2, 3, 4, 5, 6};
    deque<int> d1; //创建一个空的deque<int>对象
    cout << "d1(1): ";
    copy(arr, arr + 6, back_inserter(d1)); //将数组arr中的元素插入到d1容器中
    //将d1容器中的元素用输出流迭代器输出到屏幕
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "d1(2): ";
    front_inserter(d1) = 11; //前端插入元素
    front_inserter(d1) = 22;
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, " ")); //再次输入
    cout << endl;

    cout << "d1(3): ";
    //将d1容器中的所有元素再次插入到d1容器的前端
    copy(d1.begin(), d1.end(), front_inserter(d1));
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "d1(4): ";
    inserter(d1, d1.end()) = 33; //将33插入在d1容器的尾部
    inserter(d1, d1.end()) = 44;
    copy(d1.begin(), d1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<int> d2; //创建一个空的deque容器d2
    cout << "d2: ";
    //将d1容器的元素插入到d2容器的头部
    copy(d1.begin(), d1.end(), inserter(d2, d2.begin()));
    copy(d2.begin(), d2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "please input data:" << endl;
    deque<int> d;                   //创建一个deque<int>容器d
    istream_iterator<int> itc(cin); //定义一个输入流迭代器，从cin流中读取数据
    istream_iterator<int> itf;      //默认输入流迭代器
    while (itc != itf)              //比较it与itf迭代器，判断读取操作是否合法
    {
        *itc;              //相当于cin>>
        d.push_back(*itc); //将读取到的数据存储到d容器中
        ++itc;             //迭代器向后移动
    }
    // 用输出流迭代器输出容器中数据
    copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
