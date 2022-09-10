#include "dynamicMemory.h"

using namespace std;

int main()
{
	Example exampleObj, *examplePointer;//pointer(işaretçi)'ın nesnesi yaratılmaz.Burada Example türünde pointer tanımladık.


	//example nesnesine erişim
	exampleObj.x = 5;
	exampleObj.y = 6;
	exampleObj.print();

	examplePointer = &exampleObj;//Burada pointera nesnemizin adresini atadık.


	//pointer ile tuttuğumuz adresteki nesne ye ve nesnenin field ve methoları erişmenin iki yöntemi aşağıda gösterilmiştir.
	(*examplePointer).x = 11;
	(*examplePointer).y = 17;
	(*examplePointer).print();

	exampleObj.print();

	examplePointer->x = 99;
	examplePointer->y = 4;
	examplePointer->print();

	exampleObj.print();

	//Nesnelerimizi dinamik olarak nasıl oluşturuyoruz?

	int* ptr = new int;//int türünde bir değişken oluşturdum ve ptr olarak adlandırdığım pointer a adresini atadım.
	(*ptr) = 5;
	cout << *ptr << endl;
	delete ptr;//new keyword ü ile oluşturduğum değişkeni sildim(temizledim).

	Example* ptrExample = new Example;//Example türünde bir nesne oluşturdum ve ptrExample olarak adlandırdığım pointera adresini atadım.
	//Yukarıda new keywordü ile nesnemizi biz oluşturduk(constructorı çalıştırdık) , bundan dolayı delete keywordü ile nesnemizi bizim silmemiz gerkemedtedr(destructorı çalıştırmamız gerekmektedir)
	ptrExample->x = 333;
	ptrExample->y = 444;
	ptrExample->print();
	delete ptrExample;


	//dinamik tek boyutlu nesne dizisi oluşturma:

	int* ptrArray = new int[5];
	for (int i = 0; i < 5; i++) {
		ptrArray[i] = i * 2;
		cout << ptrArray[i] << endl;
	}
	delete[] ptrArray;

	
	Example* ptrExArray = new Example[5];
	for (int i = 0; i < 5; i++) {
		ptrExArray[i].x = i * 5;
		ptrExArray[i].y = i * 7;
		ptrExArray[i].print();
	}
	delete[] ptrExArray;

	//dinamik çift boyutlu nesne dizisi oluşturma:
	int** ptr2Array = new int* [5];
	for (int i = 0; i < 5; i++) {
		ptr2Array[i] = new int[4];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			ptr2Array[i][j] = i * j;
			cout << ptr2Array[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < 5; i++) {
		delete[] ptr2Array[i];
	}


	Example** ptrExArray1 = new Example*[5];
	for (int i = 0; i < 5; i++) {
		ptrExArray1[i] = new Example[6];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			ptrExArray1[i][j].x = i + j;
			ptrExArray1[i][j].y = i + j;
			ptrExArray1[i][j].print(false);
			cout << "        ";
		}
		cout << "\n\n";
	}
	for (int i = 0; i < 5; i++) {
		delete[] ptrExArray1[i];
	}
	delete[] ptrExArray1;

	Example exObj4(4,4), exObj5(5,5);
	exObj4.print();
	exObj4.addExample(exObj5);
	exObj4.print();

	return 0;
}
