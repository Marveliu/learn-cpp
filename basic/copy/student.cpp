#include "student.h"
#include<cstring>
#include<string>

student::student(const char* _name, int _grade){
    int len = strlen(_name);
    grade = _grade;
    name =  new char[len+1];
    strcpy(name,_name);
}

student::student(student &s){
    int len = strlen(s.name);
    grade = s.grade;
    name =  new char[len+1];
    strcpy(name,s.name);
}