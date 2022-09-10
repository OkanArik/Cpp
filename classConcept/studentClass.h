#include <iostream>
using namespace std;

class Student {


	private:
		string studentName , studentSurname , studentID; //class member (variables)
		

	public:
		Student(); // Parametre almayan yani default constructor

		Student(string name, string surname, string ID) {
			cout <<endl<< "3 parameter constructor worked." << endl;
			this->studentName = name;
			this->studentSurname = surname;
			this->studentID = ID;
		}

		Student(string name, string surname);

		~Student(); //Destructor

		Student(const Student& oth);//copy constructor

		void displayInformation();//class member (method)

		void setInformation(string name, string surname, string ID) {
			studentName = name;
			studentSurname = surname;
			studentID = ID;
		}

		void setName(string name) {
			studentName = name;
		}

		void setSurname(string surname);

		void setStudentID(string ID) {
			studentID = ID;
		}

		string getName() {
			return studentName;
		}

		string getSurname() {
			return studentSurname;
		}

		string getStudentID() {
			return studentID;
		}
		 
};

void Student::displayInformation() {  // Class içerisinde imzası tanımalanan methodu classın alt tarında doldurabiliriz.
	cout << "Name: " << studentName << " " << studentSurname << endl;
	cout << "ID: " << studentID << endl<<endl;
}

void Student::setSurname(string surname) { // Class içerisinde imzası tanımalanan methodu classın alt tarında doldurabiliriz.
	studentSurname = surname;
}

Student::Student() { // Parametre almayan yani default constructor.
	cout <<endl<<"Default constructor worked."<<endl; 
	studentName = "None";
	studentSurname = "None";
	studentID = "None";
}

Student::Student(string name ,string surname){
	cout <<endl<< "2 parameter constructor worked."<<endl;
	this->studentName = name;
	this->studentSurname = surname;
	this->studentID = "None";
}

Student::~Student() {
	cout << endl << "Default destructor worked."<<endl;
}

Student::Student(const Student& oth) {
	cout << endl << "Copy Constructor worked." << endl;
	studentName = oth.studentName;
	studentSurname = oth.studentSurname;
	studentID = oth.studentID;
}



/*
		ERİŞİM BELİRTEÇLERİ :
	- private(özel) => sadece sınıfın(class) içerisinde erişilinebilir.(sınıfa özel)
	- protected(korumalı) => sadece class ve miras alan sınıflardan erişilinebilir.Main kısımdan erişilemez.
	- public(genel) => her yerden erişilinebilir.
*/


/*
		CONSTRUCTOR(Yaratıcı/Kurucu)
	- Constructor'lar bir sınıftan nesne üretirken çalışan ilk methodlardır.Constructor method çalışır
	ve nesneyi ayağa kaldırır/yaratır.
	- Constructor'ları ikiye ayırabiliriz.Parametre alan constructor'lar ve parametre almayan default constructor'lar olarak.
*/

/*
		DESTRUCTOR(Yıkıcı)
	- Nesne yokolurken/yıkılırken çalışır.
	- Bir sınıfta bir tane desructor tanımlanabilir ve destructor'lar parametre almazlar.
	- Nesne ile işlem bitince nesne yıkılır ve bu sırada destructor method çalışır.
*/