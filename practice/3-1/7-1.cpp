#include <iostream>
#include <string>
using namespace std;

class Date
{
  protected:
    int year, month, day;

  public:
    Date(int y, int mo, int d) : year(y), month(mo), day(d) {}
};
class Time
{
  protected:
    int hour, minute, second;

  public:
    Time(int h, int mi, int s) : hour(h), minute(mi), second(s) {}
};

class Schedule : public Date, public Time
{
  protected:
    int ID;

  public:
    Schedule(int id, int y, int mo, int d, int h, int mi, int s) : Date(y, mo, d), Time(h, mi, s)
    {
        ID = id;
    }
    // 重载
    bool operator<(const Schedule &s2)
    {
        if (this->year < s2.year)
        {
            return true;
        }
        else if (this->year > s2.year)
        {
            return false;
        }
        else
        {
            if (this->month < s2.month)
            {
                return true;
            }
            else if (this->month > s2.month)
            {
                return false;
            }
            else
            {
                if (this->day < s2.day)
                {
                    return true;
                }
                else if (this->day > s2.day)
                {
                    return false;
                }
                else
                {
                    if (this->hour < s2.hour)
                    {
                        return true;
                    }
                    else if (this->hour > s2.hour)
                    {
                        return false;
                    }
                    else
                    {
                        if (this->minute < s2.minute)
                        {
                            return true;
                        }
                        else if (this->minute > s2.minute)
                        {
                            return false;
                        }
                        else
                        {
                            return this->second < s2.second;
                        }
                    }
                }
            }
        }
    }
    void display()
    {
        cout << "The urgent schedule is No.";
        cout << ID << ':' << ' ';
        cout << year << '/' << month << '/' << day << ' ';
        cout << hour << ':' << minute << ':' << second << endl;
    }
};

int main()
{
    int n;
    int y, mo, d, h, mi, s;
    Schedule sch(0, 0, 0, 0, 0, 0, 0);
    for (int i = 0;; i++)
    {
        cin >> n;
        if (n == 0)
        {
            sch.display();
            break;
        }
        else
        {
            scanf("%d/%d/%d%d:%d:%d", &y, &mo, &d, &h, &mi, &s);
            Schedule temp = Schedule(n, y, mo, d, h, mi, s);
            if (i == 0)
            {
                sch = temp;
            }
            else
            {
                if (temp < sch)
                {
                    sch = temp;
                }
            }
        }
    }
    return 0;
}