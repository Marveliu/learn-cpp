// 现在要开发一个系统，管理对多种汽车的收费工作。 给出下面的一个基类框架

// class Vehicle

// {

// protected:

// string NO;
// public:

// Vehicle(string n){

// NO = n;

// }

// virtual int fee()=0;//计算应收费用

// };

// 以Vehicle为基类，构建出Car、Truck和Bus三个类。

// Car的收费公式为： 载客数*8+重量*2

// Truck的收费公式为：重量*5

// Bus的收费公式为： 载客数*3

// 生成上述类并编写主函数

// 主函数根据输入的信息，相应建立Car,Truck或Bus类对象，对于Car给出载客数和重量，Truck给出重量，Bus给出载客数。假设载客数和重量均为整数

// 输入格式：第一行输入测试用例数。接着每个测试用例占一行，每行给出汽车的基本信息，第一个数据为当前汽车的类型：1为car，2为Truck，3为Bus。第二个数据为它的编号，接下来Car是载客数和重量，Truck要求输入重量，Bus要求输入载客数。

// 要求输出各车的编号和收费。

#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
  protected:
	string NO; //编号
  public:
	Vehicle(string n) { NO = n; }
	virtual int fee() = 0; //计算应收费用
};

/* 请在这里填写答案 */

// Car,Truck或Bus类对象

class Car : public Vehicle
{
  public:
	int c;
	int w;
	Car(string n, int _c, int _w) : Vehicle(n)
	{
		c = _c;
		w = _w;
	};
	int fee()
	{
		return c * 8 + w * 2;
	};
};

class Truck : public Vehicle
{
  public:
	int w;
	Truck(string n, int _w) : Vehicle(n)
	{
		w = _w;
	};
	int fee()
	{
		return w*5;
	};
};

class Bus : public Vehicle
{
  public:
	int c;
	Bus(string n, int _c) : Vehicle(n)
	{
		c = _c;
	};
	int fee()
	{
		return c*3;
	};
};


int main()
{
	Car c("", 0, 0);
	Truck t("", 0);
	Bus b("", 0);
	int i, repeat, ty, weight, guest;
	string no;
	cin >> repeat;
	for (i = 0; i < repeat; i++)
	{
		cin >> ty >> no;
		switch (ty)
		{
		case 1:
			cin >> guest >> weight;
			c = Car(no, guest, weight);
			cout << no << ' ' << c.fee() << endl;
			break;
		case 2:
			cin >> weight;
			t = Truck(no, weight);
			cout << no << ' ' << t.fee() << endl;
			break;
		case 3:
			cin >> guest;
			b = Bus(no, guest);
			cout << no << ' ' << b.fee() << endl;
			break;
		}
	}
	return 0;
}