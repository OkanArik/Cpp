#include "Triangle.h"

int main()
{
	float a, b, c;
	cout << "Please enter the sides(a-b-c):" << endl;
	cin >> a >> b >> c;

	Triangle triangle1(a,b,c);//constructor
	Triangle triangle2 = { a,b,c }; //constructor
	Triangle triangle3{ a,b,c }; //constructor

	Triangle triangle4=triangle1; //copy constructor
	Triangle triangle5(triangle1); //copy constructor

	cout << "-Triangle1-" << endl;
	cout << "Side A:" << triangle1.getSideA() << endl;
	cout << "Side B:" << triangle1.getSideB() << endl;
	cout << "Side C:" << triangle1.getSideC() << endl;
	cout << "Triangle area: " << triangle1.calculateArea() << endl;

	cout << "-Triangle4-" << endl;
	cout << "Side A:" << triangle4.getSideA() << endl;
	cout << "Side B:" << triangle4.getSideB() << endl;
	cout << "Side C:" << triangle4.getSideC() << endl;
	cout << "Triangle area: " << triangle4.calculateArea() << endl;


	cout << "-Triangle2-" << endl;
	triangle2.setValue(12 ,16 ,20);
	cout << "Side A:" << triangle2.getSideA() << endl;
	cout << "Side B:" << triangle2.getSideB() << endl;
	cout << "Side C:" << triangle2.getSideC() << endl;
	cout << "Triangle area: " << triangle2.calculateArea() << endl;

	triangle1.triangleType();
	triangle2.triangleType();


}
