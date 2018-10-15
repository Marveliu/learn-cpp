#include <iostream>
#include <map>
using namespace std;

class Student{
    public:
        int rno;
        char name[16];
        int h, w; 
};

bool isExist[1000001];
map<int, Student> stuMap;



int main(){
    int n ;
    cin >> n;

    for(int i = 0; i < n; i++){
        Student s;
        scanf("%d%s%d%d", &s.rno, s.name, &s.h, &s.w);
        s.rno += 1;

        if (!isExist[s.rno] || s.h > stuMap[s.rno].h) {
            isExist[s.rno] = true;
            stuMap[s.rno] = s;
        }

    }
    
    for (int i = 1; i <= 1000000; i++) {
        if (isExist[i]) {
            printf("%06d %s %d %d\n", stuMap[i].rno-1, stuMap[i].name, stuMap[i].h, stuMap[i].w);
        }
    }
    return 0;
}