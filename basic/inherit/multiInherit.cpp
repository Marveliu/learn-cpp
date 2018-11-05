#include <iostream>
using namespace std;

class Animal //定义类Animal
{
public:
  //定义类Animal的构造函数
  Animal(int age) : m_nAge(age) { cout << "Animal constructor!" << endl; }

protected:
  int m_nAge; //成员m_nAge记录动物年龄
};

class Date
{
  //定义日期类
public:
  Date(int con_year, int con_month, int con_day); //声明构造函数
  //显示年月日信息的函数print_date()
  void print_date() { cout << m_nYear << "-" << m_nMonth << "-" << m_nDay << endl; }

private:
  int m_nYear, m_nMonth, m_nDay;
};

Date::Date(int con_year, int con_month, int con_day) //定义日期类构造函数
{
  cout << "Date constructor!" << endl;
  m_nYear = con_year;
  m_nMonth = con_month;
  m_nDay = con_day;
}

class Bird : public Animal //定义鸟类
{
public:
  Bird(int age, int fh) : Animal(age) //定义鸟类带参数的构造函数
  {
    cout << "Bird constructor!" << endl;
    m_nFlightAltitude = fh;
  }
  //定义鸟呼吸的成员函数
  void breath() { cout << "bird breath!" << endl; }
  //定义获取鸟飞行高度的函数
  int get_flightaltitude() { return m_nFlightAltitude; }

private:
  int m_nFlightAltitude;
};

class Fish : public Animal //定义鱼类
{
public:
  Fish(int age, int speed) : Animal(age) //定义鱼类带参数构造函数
  {
    cout << "Fish constructor!" << endl;
    m_nSwimSpeed = speed;
  }
  //定义鱼呼吸的成员函数
  void breath() { cout << "fish breath!" << endl; }
  //定义获取鱼游速的函数
  int get_swimspeed() { return m_nSwimSpeed; }

private:
  int m_nSwimSpeed;
};

class WaterBird : public Bird, public Fish //定义水鸟类
{
public:
  //定义派生类构造函数，函数的前三个参数用于为本类数据成员m_iBirthday提供初值
  //m_iBirthday的初始化在初始化列表中完成
  WaterBird(int b_age, int f_age, int year, int month, int day, int fh, int speed) : Bird(b_age, fh), Fish(f_age, speed), m_iBirthday(year, month, day)
  {
    cout << "WaterBird constructor!" << endl;
  }
  void print_birthday()
  {
    m_iBirthday.print_date();
  }
  // 注释掉则会发生继承的二义性
  void breath() { cout << "waterbird breath!" << endl; }
  void print_animalage() //定义打印动物年龄的函数
  {
    cout << "age = " << Bird::m_nAge << endl;
    cout << "age = " << Fish::m_nAge << endl;
    // 直接访问公共基类的成员会有二义性 class Fish :virtual public Animal，class Bird :virtual public Animal
    // 也可以使用虚基类的方式，使得派生类只继承一份成员
    // cout << "age = " << m_nAge << endl;
  }

private:
  //定义Date类对象为WaterBird类的数据成员
  Date m_iBirthday;
};

int main()
{
  WaterBird waterbird(5, 6, 2010, 5, 1, 20, 30); //定义水鸟对象并提供参数
  cout << "waterbird birthday:";
  waterbird.print_birthday();

  waterbird.breath();

  cout << "waterbird flight altitude: " << waterbird.get_flightaltitude()
       << ", swimming speed:" << waterbird.get_swimspeed() << endl;

  waterbird.print_animalage();

  return 0;
}
