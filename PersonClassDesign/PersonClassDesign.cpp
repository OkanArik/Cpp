#include "Person.h"
#include <time.h>


using namespace std;

int main()
{
    srand(time(NULL));
    Student studentArray[] = {
        {"Okan","Arik",1000},
        {"Engin","Mercan",1001},
        {"Berkcan","Derya",1002},
        {"Deniz","Sen",1003},
        {"Dogukan","Akyurek",1004},
        {"Ayyuce","Maras",1005}
    };
    for (int i = 0; i < 6; i++) {
        studentArray[i].setStudentGrade(rand() % 100 + 1);
        studentArray[i].print();
    }
    cout << sizeof(studentArray) / sizeof(*studentArray) << endl;//sizeof(studentArray)/sizeof(studentArray[0]) => aynıdır.
    cout << sizeof(studentArray) << endl;
    cout << sizeof(*studentArray) << endl;
    int a = 5;
    cout << sizeof(a) << endl;
    Student student("Okan","Arik",100000);
    cout << sizeof(student) << endl;
    int studentsCount=(int)(sizeof(studentArray) / sizeof(*studentArray));
    Teacher teacher("Kerem", "Arik", "Software");
    teacher.passFailStatus(studentArray,studentsCount);
    teacher.printStudentInformation(studentArray,studentsCount);




    return 0;
}
