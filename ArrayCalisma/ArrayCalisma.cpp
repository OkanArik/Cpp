#include "Array.h"

using namespace std;

int main()
{
	Array mainArray(10);
	Array mainArray2(mainArray);
	Array mainArray3;

	cout << endl << "-mainArray-" << endl;
	mainArray.AddItem(1);
	mainArray.AddItem(2);
	mainArray.AddItem(3);
	mainArray.AddItem(4);
	mainArray.AddItem(5);
	mainArray.printItems();
	mainArray.AddItem(6);
	mainArray.printItems();
	mainArray.AddItem(7);
	mainArray.AddItem(11);
	mainArray.AddItem(12);
	mainArray.AddItem(13);
	mainArray.printItems();
	mainArray.AddItem(16);
	mainArray.printItems();
	cout << "Capacity : " << mainArray.getCapacity() << endl;
	cout << "Size : " << mainArray.getSize() << endl;

	cout << endl << "-mainArray2-" << endl;
	cout << "Capacity : " << mainArray2.getCapacity() << endl;
	cout << "Size : " << mainArray2.getSize() << endl;

	cout << endl << "-mainArray3-" << endl;
	cout << "Capacity : " << mainArray3.getCapacity() << endl;
	cout << "Size : " << mainArray3.getSize() << endl;
	mainArray3.AddItem(1);
	mainArray3.AddItem(2);
	mainArray3.AddItem(3);
	mainArray3.AddItem(11);
	mainArray3.AddItem(11);
	mainArray3.printItems();
	mainArray3.AddItem(6);
	mainArray3.printItems();
	mainArray3.AddItem(7);
	mainArray3.AddItem(11);
	mainArray3.AddItem(12);
	mainArray3.AddItem(13);
	mainArray3.printItems();
	mainArray3.AddItem(16);
	mainArray3.printItems();

	cout << "\n" << "-mainArray4-" << endl;
	Array mainArray4 = mainArray3;
	cout << "Capacity : " << mainArray4.getCapacity() << endl;
	cout << "Size : " << mainArray4.getSize() << endl;
	mainArray4.printItems();
	mainArray4.AddItem(11111);
	cout << "\n" << "-mainArray4-" << endl;
	mainArray4.printItems();
	cout << "\n" << "-mainArray3-" << endl;
	mainArray3.printItems();
	mainArray3.removeIndexItem(1);
	mainArray3.removeIndexItem(-1);
	mainArray3.removeIndexItem(10);
	mainArray3.removeIndexItem(9);
	mainArray3.printItems();
	mainArray3.removeItem(11);
	mainArray3.printItems();
	mainArray3.findElement(5,1);
	mainArray3.findElement(3,2);
	mainArray3.findElement(3,1);
	mainArray3.findElement(155);

	return 0;
}
