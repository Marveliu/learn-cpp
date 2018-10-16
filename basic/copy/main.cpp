#include<iostream>
#include"student.h"
using namespace std;

int main(){
    student s("john",100);
    student s1(s);
    s.grade = 99;
    s.info();
    s1.info();
    return 0;
}