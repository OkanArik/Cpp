#include <iostream>

using namespace std;

class Date {
	public:
		Date(int d = 1, int m = 1, int y = 1);
		Date(const Date& oth);
		~Date();
		void setDate(int d = 1, int m = 1, int y = 1900);
		void setDay(int d);
		void setMonth(int m);
		void setYear(int y);
		int getDay() const{
			return day;
		}
		int getMonth() const {
			return month;
		}
		int getYear() const {
			return year;
		}
		void increaseDay();
		void compareDate(const Date& othDate);
		void displayDate();
	private:
		int year, month, day;
		const int monthDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		const string monthString[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

};

Date::Date(int d, int m, int y) {
	setDate(d, m, y);
	cout << "Constructor worked." << endl;
}

Date::Date(const Date& oth) {
	this->year = oth.year;
	this->month = oth.month;
	this->day = oth.day;
	cout << "Date copied to target." << endl;
}

Date::~Date() {
	cout << "Date destroyed."<< endl;
}

void Date::setDay(int d) {
	d >= 1 && d <= monthDays[month - 1] ? day = d : day = 1;
}

void Date::setMonth(int m) {
	m >= 1 && m <= 12 ? month = m : m = 1;
}

void Date::setYear(int y) {
	y >= 1900 ? year = y : year = 1900;
}

void Date::setDate(int d, int m, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::increaseDay() {
	if (day < monthDays[month - 1]) {
		day++;
	}
	else {
		day = 1;
		if (month < 12) {
			month++;
		}
		else {
			month = 1;
			year++;
		}
	}
}

void Date::displayDate() {
	cout << day << " " << monthString[month - 1] << " " << year << endl;
}

void Date::compareDate(const Date& othDate) {
	long firstDay;
	long secondDay;

	firstDay = year * 365 + month * 30 + day;
	secondDay = othDate.year * 365 + othDate.month * 30 + othDate.day;

	cout << (firstDay > secondDay ? "First day is greater." : secondDay == firstDay ? "Equal." : "Second day is greater.") << endl;
}


