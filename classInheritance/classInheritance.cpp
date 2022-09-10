
#include "classInheritance.h"

using namespace std;

int main()
{
	baseClass obj1(5);
	derivedClass obj2(8, 3);

	derivedClass obj3(obj2);

	cout << "For base ; X : " << obj1.getX() << endl;
	cout << "For derived ; X : " << obj2.getX() << " Y : " << obj2.getY() << endl;
	cout << "For derived and copied object ; X : " << obj3.getX() << " Y : " << obj3.getY() << endl;
	

	CClass cObject;
	
	obj1.print();
	obj2.print();

	return 0;
}
