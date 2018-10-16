#include <iostream>
#include <string>
using namespace std;

const static int PI = 3.14;

class Shape
{
  public:
	virtual void GetArea() = 0;
	virtual void GetPerim() = 0;
};

class Rectangle : public Shape
{
  protected:
	int h;
	int w;

  public:
	Rectangle(int _h, int _w) : h(_h), w(_w)
	{
	}
	void GetArea()
	{
		cout << "Rectangle area :" << h * w << endl;
	}
	void GetPerim()
	{
		cout << "Rectangle area :" << 2 * (h + w) << endl;
	}
};

class Circle : public Shape
{
  protected:
	int r;

  public:
	Circle(int _r) : r(_r)
	{
	}
	void GetArea()
	{
		cout << "Circle area :" << 2 * PI * r << endl;
	}
	void GetPerim()
	{
		cout << "Circle area :" << 2 * PI * r * r << endl;
	}
};

int main()
{
	Shape *s[2];
	s[0] = new Rectangle(1, 2);
	s[1] = new Circle(2);
	for (int i = 0; i < 2; i++)
	{
		s[i]->GetArea();
		s[i]->GetPerim();
	}
	return 0;
}