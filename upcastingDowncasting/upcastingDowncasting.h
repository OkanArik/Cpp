#include <iostream>

using namespace std;

class Employee{
public:
	string empName, empSurname;
	double empSalary;
	Employee(string name, string surname, double salary) {
		empName = name;
		empSurname = surname;
		empSalary = salary;
	}

	virtual ~Employee() {
		cout << "Employee destructor worked." << endl;
	}
	virtual void displayInformation() {
		cout << "Name    : " << empName << endl;
		cout << "Surname : " << empSurname << endl;
		cout << "Salary  : " << empSalary << endl;
	}
};

class Manager : public Employee {
public:
	string mngDepartment;
	Manager(string name, string surname, double salary, string department) : Employee(name, surname, salary) {
		mngDepartment = department;
	}
	void displayInformation() {
		Employee::displayInformation();
		cout << "Department : " << mngDepartment << endl;
	}

	~Manager() {
		cout << "Manager destructor worked." << endl;
	}
	void increaseSalary() {
		empSalary += 200;
	}
};

//Reference
void print(Employee& employeeType) {
	cout << "--------Reference--------" << endl;
	employeeType.displayInformation();
}

//pointer
void print1(Employee* employeeType) {
	cout << "---------Pointer---------" << endl;
	employeeType->displayInformation();
}

//value
void print2(Employee employeeType) {
	cout << "---------Value-----------" << endl;
	employeeType.displayInformation();
}



//Pure Virtual Function Çalışması
class Animal {//Bu sınıfın içerisinde pure virtual function yazıldığı için soyut sınıf haline gelmiştir ve bu sınıftan nesne üretilemez.
public:
	virtual void talk() = 0; //Pure Virtual Function


};

class Dog : public Animal {
public:
	void talk() {
		cout << "Hav Hav" << endl;
	}


};

class Cat : public Animal {
public:
	void talk() {
		cout << "Miyav Miyav" << endl;
	}


};

class Duck : public Animal {
public:
	void talk() {
		cout << "Vak Vak" << endl;
	}


};


