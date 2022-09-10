#include <iostream>
#include <string>
using namespace std;

class Triangle {
public:
	Triangle(float a, float b, float c); // Parameter Constructor
	~Triangle(); // Destructor
	Triangle(const Triangle& oth); // Copy Constructor
	bool isTriangle(float a, float b, float c);
	//float getSideA() const; => bu fonksiyonu constant olarak tanımlamamızın sebebi , constant fonksiyonlar input'tan bağımsız herzaman aynı değeri döndürür.
	float getSideA() const {
		return sideA;
	}
	float getSideB() const {
		return sideB;
	}
	float getSideC() const {
		return sideC;
	}
	void setValue(float a, float b, float c);
	bool isEquilateral(); //Equilateral => eşkenar
	bool isScalene(); //Scalene => çeşitkenar(eşkenar olmayan)
	bool isIsosceles(); //Isosceles => ikizkenar
	void triangleType();
	float calculateArea();
private:
	float sideA, sideB, sideC;
};

// isTriangle methodu ile girilen verilerle bir üçgen oluşturulabiliyor mu oluşturulamıyor mu onu sorgulayacağız.
bool Triangle::isTriangle(float a, float b, float c) {
	//sideA:  |b-c|<a<b+c
	//sideB:  |a-c|<b<a+c
	//sideC:  |a-b|<c<a+b
	//verilen a,b ve c verilerinden bir üçgen oluşabilmesi için yukarıda üç şartın birden sağlanıyor olması gereklidir.
	if ((abs(b - c) < a) && (a < b + c) && (abs(a - c) < b) && (b < a + c) && (abs(a - b) < c) && (c < a + b))
		return true;
	cout << "Invalid sides!" << endl;
	return false;
}

// Aşağıda constructor ile aldığımız a,b ve c verileri ile üçgen oluşup oluşmadığını sorguluyucaz ve oluşan veriler girilince nesne yaratılacak ve veriler kenar değişkenlerine atanacak.
Triangle::Triangle(float a, float b, float c) {
	while (!isTriangle(a, b, c))
	{
		cout << "Please enter the sides(a-b-c):" << endl;
		cin >> a >> b >> c;
	}
	sideA = a;
	sideB = b;
	sideC = c;
	cout << "Triangle created." << endl;
}

Triangle::~Triangle() {
	cout << "Triangle destroyed." << endl;
}

Triangle::Triangle(const Triangle& oth) {
	sideA = oth.sideA;
	sideB = oth.sideB;
	sideC = oth.sideC;
	cout << "Triangle copied to target." << endl;
}

void Triangle::setValue(float a, float b, float c) {
	while (!isTriangle(a, b, c))
	{
		cout << "Please enter the sides(a-b-c):" << endl;
		cin >> a >> b >> c;
	}
	sideA = a;
	sideB = b;
	sideC = c;
}

bool Triangle::isEquilateral() {
	return  sideA == sideB && sideB == sideC ? true : false;
}

bool Triangle::isIsosceles() {

	return isEquilateral() || sideA == sideB || sideA == sideC || sideB == sideC ? true : false;
}

bool Triangle::isScalene() {
	return !isIsosceles();
}
void Triangle::triangleType() {
	if (isEquilateral()) {
		cout << "Equilater Triangle" << endl;
	}
	else if (isIsosceles()) {
		cout << "Isosceles Triangle" << endl;
	}
	else if(isScalene()) {
		cout << "Scalene Triangle" << endl;
	}
}

float Triangle::calculateArea() {
	float area;
	if (isEquilateral()) {
		area = (pow(sideA, 2) * sqrt(3) / 4);
	}
	else {
		float s = (sideA + sideB + sideC) / 2;
		area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
	}
	return area;
}