#include <iostream>
using namespace std;

// 内联函数

class Test //定义Test类
{
  public:
    Test() : m_nX(10) {}
    inline void print(); //声明内联函数，占更多的内存，但是速度更快，头文件需要申明
    void display(int y);

  private:
    int m_nX;
};
void Test::print() //定义内联函数
{
    cout << m_nX << endl;
}
void Test::display(int y)
{
    cout << m_nX * y << endl;
}
int main()
{
    Test obj; //定义类对象
    obj.display(10);
    obj.print(); //调用内联函数
    system("pause");
    return 0;
}
