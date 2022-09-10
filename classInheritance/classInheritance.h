#include <iostream>
using namespace std;
/*
*** polimorphizm 2 şekilde olabilir:
-> compile-time(derleme zamanı)=> function overloading & operator overloading
-> run-time(çalışma zamanı)=>function overriding
*/

class baseClass {
	protected://protected erişim belirteci ile işaretlenmiş variable ve methodlara bu sınıf içerisinden ve bu sınıftan miraz alan sınıflar içerisinden erişilinebilir.
		int x;
	public:
		void setX(int mainX) {
			x = mainX;
		}
		int getX() const {
			return x;
		}
		void print() {
			cout << "X : " << x << endl;
		}
		baseClass(int mainX = 0) {
			x = mainX;
			cout << "Base class constructor worked." << endl;
		}
		~baseClass() {
			cout << "Base class destructor worked." << endl;
		}
		baseClass(const baseClass& oth) {
			x = oth.x;
			cout << "Base class copy constructor worked." << endl;
		}
};

class derivedClass : public baseClass {
	public:
		int y;
		void setY(int mainY) {
			y = mainY;
		}
		int getY() const {
			return y;
		}
		void print() { //print() fonklsiyonunu override ettik
			baseClass::print();
			cout << "Y : " << y << endl;
		}
		derivedClass(int mainX=0,int mainY=0):baseClass(mainX) {
			y = mainY;
			cout << "Derived class constructor worked." << endl;
		}
		~derivedClass() {
			cout << "Derived class destructor worked." << endl;
		}
		derivedClass(const derivedClass& oth) {
			x = oth.x;
			y = oth.y;
			cout << "Derived class copy constructor worked." << endl;
		}
};

class AClass {
	public:
		int a;
		AClass() {
			cout << "AClass constructor worked." << endl;
		}
		~AClass() {
			cout << "AClass destructor worked." << endl;
		}
};

class BClass {
	public:
		int b;
		BClass() {
			cout << "BClass constructor worked." << endl;
		}
		~BClass() {
			cout << "BClass destructor worked." << endl;
		}
};


class CClass : public AClass , public BClass {
	public:
		CClass() {
			cout << "CClass constructor worked." << endl;
		}
		~CClass() {
			cout << "CClass destructor worked." << endl;
		}
};
