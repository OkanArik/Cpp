#include "PersonToEmployee.h"

using namespace std;

int main()
{
    Employee employee1 = { "Okan","Arik","Software", "Engineer",4500,5 };
    Employee employee2 = { "Engin","Mercan","Software","Test",4500,5 };
    Employee employee3 = { "Berkcan","Derya","Software", "Engineer",4500,5 };
    Employee employee4 = { "Deniz","Sen","Software", "Engineer",4500,6 };
    Employee employee5 = { "Ayyuce","Arayan","IT","Engineer",4500,8 };
    Employee employee6 = { "Cansel","Koylu","Software","Engineer",4500,10 };
    Manager manager1("Kerem", "Arik", "Software", "Manager", 8500, 10);
    Manager manager2("Kubra", "Arik", "IT", "Manager", 15000, 20);

    Employee employeeList[] = { employee1,employee2,employee3,employee4,employee5,employee6 };
    int countOfEmployees = sizeof(employeeList) / sizeof(*employeeList);
    cout << countOfEmployees << endl;

    manager1.extractEmployee(employeeList, countOfEmployees);
    manager2.extractEmployee(employeeList,countOfEmployees);

    return 0;
}
