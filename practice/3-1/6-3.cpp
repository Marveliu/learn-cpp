#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */

static float avg = 0;
class Student
{
  protected:
	string num, name;
	float s;

  public:
	Student(string snum, string sname) : num(snum), name(sname) {}
	virtual void display()
	{
	}
	~Student()
	{
	}
};

class GroupA : public Student
{
  protected:
	int s1, s2;

  public:
	GroupA(string snum, string sname, int s1, int s2) : Student(snum, sname)
	{
		s1 = s1;
		s2 = s2;
		s = (s1 + s2) * 1.0 / 2;
		if (s > avg)
		{
			avg = s;
		}
	}
	void display()
	{
		if (s == avg)
		{
			cout << num << ' ' << name << endl;
		}
	}
};

class GroupB : public Student
{
  protected:
	int s1, s2;
	char level;

  public:
	GroupB(string snum, string sname, int s1, int s2, char s3) : Student(snum, sname)
	{
		s1 = s1;
		s2 = s2;
		level = s3;
		s = (s1 + s2) * 1.0 / 2;
		if (s > avg)
		{
			avg = s;
		}
	}
	void display()
	{
		if ((s == avg) || (s >= avg * 0.7 && level == 'A'))
		{
			cout << num << ' ' << name << endl;
		}
	}
};

class GroupC : public Student
{
  protected:
	int s1, s2, s3, s4, s5;

  public:
	GroupC(string snum, string sname, int s1, int s2, int s3, int s4, int s5) : Student(snum, sname)
	{
		s1 = s1;
		s2 = s2;
		s3 = s3;
		s4 = s4;
		s5 = s5;
		s = (s1 + s2 + s3 + s4 + s5) * 1.0 / 5;
	}
	void display()
	{
		if (s >= avg * 0.9)
		{
			cout << num << ' ' << name << endl;
		}
	}
};

int main()
{
	const int Size = 50;
	string num, name;
	int i, ty, s1, s2, s3, s4, s5;
	char gs;
	Student *pS[Size];
	int count = 0;
	for (i = 0; i < Size; i++)
	{
		cin >> ty;
		if (ty == 0)
			break;
		cin >> num >> name >> s1 >> s2;
		switch (ty)
		{
		case 1:
			pS[count++] = new GroupA(num, name, s1, s2);
			break;
		case 2:
			cin >> gs;
			pS[count++] = new GroupB(num, name, s1, s2, gs);
			break;
		case 3:
			cin >> s3 >> s4 >> s5;
			pS[count++] = new GroupC(num, name, s1, s2, s3, s4, s5);
			break;
		}
	}
	for (i = 0; i < count; i++)
	{
		pS[i]->display();
		delete pS[i];
	}
	return 0;
}