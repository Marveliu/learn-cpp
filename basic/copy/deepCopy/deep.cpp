#include <iostream>
#include <cstring>
using namespace std;

// 深拷贝实现string

class String
{
  public:
    String(char *pStr)
    {
        if (NULL == pStr)
        {
            pstr = new char[1];
            pstr = '\0';
        }
        else
        {
            pstr = new char[strlen(pStr) + 1]; //加1,某位是'\0'
            strcpy(pstr, pStr);                //用拷贝字符串的函数
        }
    }

    String(const String &s) //浅拷贝，指向同一块空间
    {
        pstr = new char[strlen(s.pstr) + 1]; //加1,某位是'\0'
        strcpy(pstr, s.pstr);                //用拷贝字符串的函数
    }

    String &operator=(const String &s)
    {
        if (this != &s)
        {
            // pstr 浅拷贝之前没有分配空间
            delete[] pstr;                       //将原来所指向的空间释放
            pstr = new char[strlen(s.pstr) + 1]; //加1,某位是'\0'
            strcpy(pstr, s.pstr);                //用拷贝字符串的函数
            // pstr = s.pstr; //让pstr重新指向s的pstr所指向的空间
        }
        return *this;
    }

    ~String()
    {
        if (NULL != pstr)
        {
            delete[] pstr; //释放指针所指向的内容
            pstr = NULL;   //将指针置为空
        }
    }

    friend ostream &operator<<(ostream &_cout, const String &s)
    {
        _cout << s.pstr;
        return _cout;
    }

  private:
    char *pstr;
};

int main()
{
    String s1("sss");
    String s2(s1);
    String s3(NULL);
    s3 = s1;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    return 0;
}