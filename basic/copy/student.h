#include<iostream>
using namespace std;

class student{
    public:
        student();
        student(const char* name, int grade);
        student(student &s);
        ~student(){delete[] name;};
        void info(){cout << name << " " << grade << endl;}
        char* name;
        int grade;
};