#include <iostream>
using namespace std;

// 重载
int max(const int& a, const int& b)  //非模板函数，求两个int类型数据的最大者
{
	cout << "invoke this" << endl;
	return a>b ? a : b;
}
template <typename T>  //定义求两个任意类型数据的最大值
T max(const T& t1, const T& t2)
{
	return t1 > t2 ? t1 : t2;
}
template<typename T>  //定义求三个任意类型数据的最大值
T max(const T& t1, const T& t2, const T&t3)
{
	// 调用的是非模板函数
	return max(max(t1, t2), t3);
}

//定义函数模板
template<typename T>
T add(T t1, T t2)
{
	return t1 + t2;
}
template int add<int>(int t1, int t2); //显式实例化为int类型
int main()
{
	cout << add(1, 2) << endl;  //传入int类型参数
	cout << add(1.2, 3.4) << endl; //传入double类型参数
    cout << add<int>(1, 'B') << endl;  //调用显示实例化的模板函数

	cout << max(1, 2, 3) << endl; //调用三个参数的函数模板
	return 0;
}
