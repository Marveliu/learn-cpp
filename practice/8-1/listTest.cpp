#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class student
{
  public:
    int no;
    string name;
    double grade;
    student(int _no, string _name, double _grade) : no(_no), name(_name), grade(_grade){};
    void show() { cout << "学号:" << no << " 姓名:" << name << " 成绩:" << grade << endl; }
};

list<student> stus;

// log readme
void help()
{
    cout << "\n\n输入0,添加学生成绩,添加格式: \n";
    cout << "	 input: 1 liu 98\n";
    cout << "	output: 学号:1 姓名:liu 成绩:98\n";
    cout << "输入1,通过学号查找学生成绩,查找格式:\n";
    cout << "	 input: 1\n";
    cout << "	output: 学号:1 姓名:liu 成绩:98\n";
    cout << "输入2,通过姓名查找学生成绩,查找格式:\n";
    cout << "	 input: liu\n";
    cout << "	output: 学号:1 姓名:liu 成绩:98\n";
    cout << "输入3,排序学生成绩\n";
}

bool cmp(student a, student b)
{
    return a.grade > b.grade;
}

void disp()
{
    typename list<student>::iterator it;
    for (it = stus.begin(); it != stus.end(); it++)
    {
        (*it).show();
    }
}

void searchByNo(int no)
{
    typename list<student>::iterator it;
    for (it = stus.begin(); it != stus.end(); it++)
    {
        if (no == (*it).no)
        {
            (*it).show();
        }
    }
}

void searchByName(string name)
{
    typename list<student>::iterator it;
    for (it = stus.begin(); it != stus.end(); it++)
    {
        if (name.compare((*it).name) == 0)
        {
            (*it).show();
        }
    }
}

int main()
{
    int n;
    help();
    while (cin >> n)
    {
        switch (n)
        {
        case 0:
            // add student:
            {
                int no;
                string name;
                double grade;
                cin >> no >> name >> grade;
                student s(no, name, grade);
                stus.push_back(s);
                disp();
                break;
            }
        case 1:
        {
            // search
            int no;
            cin >> no;
            searchByNo(no);
            break;
        }
        case 2:
        {
            // search
            string name;
            cin >> name;
            searchByName(name);
            break;
        }
        case 3:
        {
            stus.sort(cmp);
            disp();
            break;
        }
        }
        help();
    }
    return 0;
}