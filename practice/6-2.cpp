#include <iostream>
using namespace std;

/* 请在这里填写答案 */
class Student
{
  public:
    static int count;
    void display();
    Student(int _no, int _grade);
    Student(Student &s);
    // ~Student();
  private:
    int no;
    int grade;
};

void Student::display()
{
    if (grade == 1)
    {
        cout << no << " Pass" << endl;
    }
    else
    {
        cout << no << " Fail" << endl;
    }
}

Student::Student(int _no, int _grade)
{
    no = _no;
    grade = _grade;
    Student::count++;
}

Student::Student(Student &s)
{
    no = s.no + 1;
    grade = s.grade;
    Student::count++;
}

int Student::count = 0;

int main()
{
    const int size = 100;
    int i, N, no, score;
    Student *st[size];
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> no;
        if (no > 0)
        {
            cin >> score;
            st[i] = new Student(no, score);
        }
        else
            st[i] = new Student(*st[i - 1]);
    }
    cout << Student::count << " Students" << endl;
    for (i = 0; i < N; i++)
        st[i]->display();
    for (i = 0; i < N; i++)
        delete st[i];
    return 0;
}