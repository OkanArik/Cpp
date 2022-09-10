#include "Date.h"

using namespace std;

int main()
{
	Date mainDate;
	cout << "Day  : " << mainDate.getDay() << endl;
	cout << "Month: " << mainDate.getMonth() << endl;
	cout << "Year : " << mainDate.getYear() << endl;
	mainDate.displayDate();

	Date mainDate2(19, 07, 1999);
	cout << "Day  : " << mainDate2.getDay() << endl;
	cout << "Month: " << mainDate2.getMonth() << endl;
	cout << "Year : " << mainDate2.getYear() << endl;
	mainDate2.displayDate();

	Date mainDate3(mainDate2);
	cout << "Day  : " << mainDate3.getDay() << endl;
	cout << "Month: " << mainDate3.getMonth() << endl;
	cout << "Year : " << mainDate3.getYear() << endl;
	mainDate3.displayDate();
	mainDate3.setDate(30, 12, 2020);
	cout << "Day  : " << mainDate3.getDay() << endl;
	cout << "Month: " << mainDate3.getMonth() << endl;
	cout << "Year : " << mainDate3.getYear() << endl;
	mainDate3.displayDate();
	for (int i = 0; i <= 45; i++) {
		mainDate3.increaseDay();
		mainDate3.displayDate();
	}

	mainDate.compareDate(mainDate3);
	mainDate.setDate(15, 2, 2021);
	mainDate.compareDate(mainDate3);
	mainDate3.increaseDay();
	mainDate.compareDate(mainDate3);

    return 0;
}
