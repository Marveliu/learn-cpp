// 运行时多态，继承进行实现

#include <iostream>
#include <cstring>
using namespace std;

class Animal //定义基类Animal
{
  public:
    void print_name(); //声明print_name()函数
    // 基类虚函数
    Animal(char *name); //声明基类构造函数
    virtual void speak() { cout << "animal language!" << endl; }
    virtual void breath() { cout << "animal breath!" << endl; }
    // virtual void print_color(); //声明虚函数print_color()
    virtual void print_color() = 0; //纯虚函数实现，一旦存在纯虚函数，此时类为抽象类，无法申明改对象，如果子类也没有实现，它也是抽象类
    virtual ~Animal();              //声明析构函数,如果不是虚函数，则基类引用派生类只会执行基类的析构函数
  private:
    char *m_pAnimalName; //存放动物名称的数据成员
};

Animal::Animal(char *name) //Animal类构造函数的定义
{
    int len = strlen(name) + 1;
    m_pAnimalName = new char[len]; //为m_pAnimalName指针开辟空间
    strcpy(m_pAnimalName, name);   //存入动物名称
}

Animal::~Animal() //Animal类析构函数
{
    cout << "Animal destructor!" << endl;
    if (m_pAnimalName)
    {
        delete[] m_pAnimalName; //释放空间
    }
}

void Animal::print_name() //显示动物名称
{
    cout << "name:" << m_pAnimalName << endl;
}

//定义虚函数print_color()，本函数在基类中为空函数，需要在派生类中重定义
// void Animal::print_color() {}

class Cat : public Animal //定义派生类Cat
{
  public:
    Cat(char *name, char *catcolor);
    //定义与基类同名的函数speak()
    virtual void speak() { cout << "cat language: miaomiao!" << endl; }
    // 基类虚函数
    virtual void breath() { cout << "cat breath!" << endl; }
    virtual void print_color(); //声明虚函数print_color()
    virtual ~Cat();

  private:
    char *m_pCatColor; //存放猫的颜色的数据成员
};

Cat::Cat(char *name, char *color) : Animal(name) //Cat类构造函数的定义
{
    cout << "Cat constructor!" << endl;
    m_pCatColor = new char[strlen(color) + 1]; //为m_pCatcolor指针开辟空间
    strcpy(m_pCatColor, color);                //存入描述猫颜色自的字符串
}

Cat::~Cat() //Cat类析构函数的定义
{
    cout << "Cat destructor!" << endl;
    if (m_pCatColor)
    {
        delete[] m_pCatColor; //释放m_pCatcolor指向的空间
    }
}

void Cat::print_color() //print_color()虚函数的实现
{
    cout << "cat color :" << m_pCatColor << endl;
}

int main()
{
    Cat cat("short_haired_cat", "white"); //定义派生类对象cat
    Animal *panimal = &cat;               //定义基类指针并指向派生类对象
    panimal->speak();                     //通过指针调用speak()函数

    Animal &ref = cat; //定义基类引用，初始化为cat
    panimal->breath();
    ref.breath();

    cout << "\n"
         << endl;

    Animal *p[2]; //定义基类Animal指针数组
    int i;
    p[0] = new Cat("short_haired_cat", "white"); //通过new生成派生类Cat对象
    p[0]->print_name();
    p[0]->print_color();
    p[0]->speak();

    cout << "\n"
         << endl;

    p[1] = new Cat("persian_cat", "brown"); //通过new生成派生类Cat对象
    p[1]->print_name();
    p[1]->print_color();

    cout << "destructor begin"
         << "\n"
         << endl;
    for (i = 0; i < 2; i++)
        delete p[i]; //通过delete释放派生类对象

    cout << "destructor end"
         << "\n"
         << endl;
    return 0;
}