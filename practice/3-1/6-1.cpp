// 补充下列代码，使得程序的输出为：
// A:3
// A:15
// B:5
// 3
// 15
// 5

#include <iostream>
using namespace std;
class CMyClassA
{
	int val;

  public:
	CMyClassA(int);
	void virtual print();
};
CMyClassA::CMyClassA(int arg)
{
	val = arg;
	printf("A:%d\n", val);
}
void CMyClassA::print()
{
	printf("%d\n", val);
	return;
}

/* 在这里填写代码 */
class CMyClassB : public CMyClassA
{
	int val;

  public:
	CMyClassB(int);
	void print();
};

CMyClassB::CMyClassB(int arg) : CMyClassA(3 * arg)
{
	val = arg;
	printf("B:%d\n", arg);
}

void CMyClassB::print(){
	printf("%d\n", val);
}

int main(int argc, char **argv)
{
	CMyClassA a(3), *ptr;
	CMyClassB b(5);
	ptr = &a;
	ptr->print();
	a = b;
	a.print();
	ptr = &b;
	ptr->print();
	return 0;
}