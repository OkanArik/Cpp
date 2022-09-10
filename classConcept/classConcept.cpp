#include "studentClass.h"

int main()
{
    //We can access class member with dot operator 
    Student student1;
    student1.displayInformation();
    student1.setName("Okan");
    student1.setSurname("Arik");   
    student1.setStudentID("1");
    student1.setInformation("Okan", "Arik", "1");
    student1.displayInformation();
    string name = student1.getName();
    std::cout << name << endl;
    std::cout << student1.getSurname() << endl;
    std::cout << student1.getStudentID() << endl;
    Student student7(student1);

    student7.displayInformation();
    student7.~Student();
    student1.~Student();

    Student student2;
    student2.displayInformation();
    student2.setName("Engin");
    student2.setSurname("Mercan");
    student2.setStudentID("2");
    student2.displayInformation();
    student2.~Student();

    if (true) {
        Student student6;
        std::cout << "if blogunun icinde student6 nesnesi yaratildi.";
    }
    std::cout << "if blogundan cikildi."<<endl;

    Student studentArray[5];
    studentArray->setInformation("Osman", "Derya", "5");
    studentArray->displayInformation();
    studentArray[0].displayInformation();
    studentArray[1].setInformation("Deniz", "Sen", "4");
    studentArray[1].displayInformation();
    
    Student student3("Berkcan", "Derya", "3");
    student3.displayInformation();

    Student student4("Ayyuce", "Arayan");
    student4.displayInformation();

    return 0;
}
