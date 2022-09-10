#include "upcastingDowncasting.h"

using namespace std;

int main()
{
    cout << "--------Up Casting----------" << endl;
    //Up Casting
    //Up Casting işleminden sonra up casting yaptığımız yerden sadece ve sadece base sınıfta tanımlı class member lara erişebiliriz.
    /*
         EMPLOYEE                      MANAGER
         name                          name
         surname                       surname
         salary                        salary
         display                       display
                                       department
                                       increaseSalary
    
    */
    // Upcasting işlemi base sınfın pointerına ,derived sınıfın nesnesinin adresi atılır ve bu pointerdan sade ve sadece base sınıfın member larına erişilebilir.
    Employee* emp1;

    Manager mng("Okan", "Arik", 5000, "Software");

    emp1 = &mng;
    emp1->displayInformation();
    //Her (derived class)yönetici bir (base class)çalışan olduğu için upcasting riskli değildir.

    cout << "---------Down Casting----------" << endl;
    //Down Casting 
    //Down casting işlemi base sınfının pointerını derived sınıfın pointerına çevirme işlemidir.

    Manager* mng2 = (Manager*)(emp1);
    mng2->displayInformation();

    cout << "----------------------------" << endl;

    //Her (base class)çalışan bir (derived class)yönetici olmadığı için downcasting risklidir.

    Employee emp2("Engin", "Mercan", 55000);
    Employee* emp3 = &emp2;
    Manager* mng3 = (Manager*)(emp3);
    mng3->displayInformation();

    cout << "-------------------------------------------------" << endl;
    Employee emp5("Ayyuce", "Arayan", 7500);
    Manager mng5("Deniz", "Sen", 12550, "Software");

    print(emp5);
    print(mng5);

    cout << "-------------------------------------------------" << endl;
    Employee* emp6 = new Employee("Eren", "Yilmaz", 22222);
    Manager* mng6 = new Manager("Berkcan", "Derya", 33333, "Software");

    print1(emp6);
    print1(mng6);

    cout << "-------------------------------------------------" << endl;
    print2(emp5);
    print2(mng5);

    cout << "-------------------------------------------------" << endl;
    Manager* mng7 = new Manager("Okan", "Arikj", 12222, "Software");
    Employee* emp7 = mng7;
    delete emp7;
    cout << "--------------------------------------------" << endl;

    Cat* catAnimal = new Cat();
    Dog* dogAnimal = new Dog();
    Duck* duckAnimal = new Duck();

    Animal* animalsPointer[] = { catAnimal,dogAnimal,duckAnimal };
    for (int i = 0; i < 3; i++) {
        animalsPointer[i]->talk();
        cout << "----------------" << endl;
    }

    return 0;
}
