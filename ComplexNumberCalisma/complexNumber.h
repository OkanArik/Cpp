#include <iostream>

using namespace std;

class complexNumber {
	private:
		//real=> karmaşık sayılarda gerçek kısım
		//imag=> karmaşık sayılarda sanal kısım
		//örnek: 4+5i => 4->real , 5i->imag
		int real, imag;
	public:
		complexNumber(int r = 0, int i = 0);
		~complexNumber();
		complexNumber(const complexNumber& oth);
		int getReal() const {
			return real;
		}
		int getImag() const {
			return imag;
		}
		void setValue(int r = 0, int i = 0);
		complexNumber addComplex(const complexNumber& oth);
		complexNumber multiplyComplex(const complexNumber& oth);
		complexNumber subtractComplex(complexNumber& oth);
		complexNumber multiplyConstant(int constant);
		void multiplyMinus();
		void displayComplex();
};

complexNumber::complexNumber(int r, int i) {
	this->real = r;
	this->imag = i;
	cout << "Complex Number created." << endl;
}

complexNumber::~complexNumber() {
	cout << "Complex Number destroyed." << endl;
}

complexNumber::complexNumber(const complexNumber& oth) {
	real = oth.real;
	imag = oth.imag;
	cout << "Complex Number copied to target." << endl;
}

void complexNumber::setValue(int r, int i) {
	this->real = r;
	this->imag = i;
}

void complexNumber::displayComplex() {
	cout << real << (imag>0 ? "+" : "") << imag << "i" << endl;
}

complexNumber complexNumber::addComplex(const complexNumber& oth) {
	complexNumber result;
	result.real = real + oth.real;
	result.imag = imag + oth.imag;
	return result;
}

complexNumber complexNumber::subtractComplex(complexNumber& oth) {
	complexNumber result;
	oth.multiplyMinus();
	result = addComplex(oth);
	return result;
}

void complexNumber::multiplyMinus() {
	this->real *= -1;
	this->imag *= -1;
}

complexNumber complexNumber::multiplyComplex(const complexNumber& oth) {
	complexNumber result;
	result.real = real * oth.real + imag * oth.imag;
	result.imag = real * oth.imag + imag * oth.real;
	return result;
}

complexNumber complexNumber::multiplyConstant(int constant) {
	complexNumber result;
	result.real = real * constant;
	result.imag = imag * constant;
	return result;
}





