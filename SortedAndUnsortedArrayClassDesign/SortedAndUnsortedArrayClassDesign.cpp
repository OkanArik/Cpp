#include "ArrayUsAndS.h"


using namespace std;

int main()
{
    unsortedArray usArray(10);

    sortedArray sArray(10);

    usArray.addItem1(10);
    usArray.addItem1(8);
    usArray.addItem1(1);
    usArray.addItem1(11);
    usArray.addItem1(55);
    usArray.addItem1(7);
    usArray.addItem1(155);
    usArray.removeIndexItem(0);
    usArray.removeItem(8);
    cout<<usArray.findIndex(122)<<endl;
    usArray.printItems();

    sArray.addItem1(10);
    sArray.addItem1(8);
    sArray.addItem1(1);
    sArray.addItem1(11);
    sArray.addItem1(55);
    sArray.addItem1(7);
    sArray.addItem1(155);
    sArray.removeIndexItem(0);
    sArray.removeItem(8);
    cout << sArray.findIndex(55) << endl;
    sArray.printItems();

    return 0;
}
