#include <iostream>
#include <string>

using namespace std;

class Person {
	protected:
		string personName, personSurname, personDepartment, personPosition, personID;
		int personSalary, personYear;
	public:
		Person(string name, string surname, string department, string position,int salary, int year) {
			personName = name;
			personSurname = surname;
			personDepartment = department;
			personPosition = position;
			personSalary = salary;
			personYear = year;
		}
		void sertName(string name) { personName = name; }
		void sertSurname(string surname) { personSurname = surname; }
		void sertDepartment(string department) { personDepartment = department; }
		void sertPosition(string position) { personPosition = position; }
		void sertId(string id) { personID = id; }
		void sertSalary(int salary) { personSalary = salary; }
		void sertYear(int year) { personYear = year; }
		string getName() { return personName; }
		string getSurname() { return personSurname; }
		string getDepartment() { return personDepartment; }
		string getPosition() { return personPosition; }
		string getID() { return personID; }
		int getSalary() { return personSalary; }
		int getYear() { return personYear; }
		void print1() {
			cout << "----------------------------" << endl;
			cout << "Name         : " << personName << " " << personSurname << endl;
			cout << "Department   : " << personDepartment << endl;
			cout << "Position     : " << personPosition << endl;
			cout << "Years worked : " << personYear << endl;
			cout << "ID Number    : " << personID << endl;

		}
};

class Employee : public Person {
	private:
		int employeeBonus;
    public:
		Employee(string name, string surname, string department, string position, int salary, int year) : Person(name, surname, department, position, salary, year) {
			employeeBonus = 85 * year;
			int randomID = rand() % 8999 + 1000;
			Employee::sertId("EMP" +to_string(randomID)+"-"+to_string(randomID));
		}
		void print1() {
			Person::print1();
			cout << "Bonus          : " << employeeBonus << endl;
			cout << "----------------------------" << endl;
		}
};

class Manager : public Employee {
		int managerBonus;
	public:
		Manager(string name, string surname, string department, string position, int salary, int year) : Employee(name, surname, department, position, salary, year) {
			managerBonus = 150 * year;
			int randomID = rand() % 8999 + 1000;
			Manager::sertId("MNG" + to_string(randomID) + "-" + to_string(randomID));
		}
		void print1() {
			Person::print1();
			cout << "Bonus            : " << managerBonus << endl;
			cout << "-----------------------------" << endl;
		}
		void extractEmployee(Employee employeeArray[], int countOfEmployees) {
			cout << "Manager Name : " << Manager::getName() << " " << Manager::getSurname() << endl;
			cout << "Manager ID   : " << Manager::getID() << endl;
			cout << "\n" << Manager::getDepartment() << " Department Employee List : " << endl;
			for (int i = 0; i < countOfEmployees; i++) {
				if (Manager::getDepartment() == employeeArray[i].getDepartment()) {
					employeeArray[i].Employee::print1();
				}
			}
		}
};







