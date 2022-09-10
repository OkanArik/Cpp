#include <iostream>

using namespace std;

class Matrix {
	private:
		int row, col;
		int** matrix;// pointer to pointer => işaretçilerin adresini tutan bir işaretçi
	public:
		Matrix(int r = 5, int c = 5);
		~Matrix();
		Matrix(const Matrix& oth);
		int getRowNumber() const { return row; }
		int getColumnNumber() const { return col; }
		void setValue(int r, int c, int value);
		void randomSet(int randomNumber=10);
		void identityMatrixSet();
		void display();
		void addMatrix(const Matrix& othMatrix);
};

Matrix::Matrix(int r, int c) {
	if (r > 0 && c > 0) {
		row = r;
		col = c;
	}
	else {
		row = 5;
		col = 5;
	}

	matrix = new int* [row];// işaretçilerin adresini atıyoruz => satır sayısı kadarlık bir pointer dizisi oluşturduk.
	for (int i = 0; i < row; i++) { 
		matrix[i] = new int[col];
	}
	cout << "Matrix created." << endl;
	cout << "Row    : " << row << endl;
	cout << "Column : " << col << endl;
}

Matrix::~Matrix() {
	for (int i = 0; i < row; i++) { 
		delete[] matrix[i];
	}
	delete[] matrix;
	cout << "Matrix destroyed." << endl;
}

Matrix::Matrix(const Matrix& oth) {
	row = oth.row;
	col = oth.col;
	matrix = new int* [row];// işaretçilerin adresini atıyoruz => satır sayısı kadarlık bir pointer dizisi oluşturduk.
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = oth.matrix[i][j];
		}
	}
	cout << "Matrix copied to target." << endl;
}

void Matrix::setValue(int r, int c, int value) {
	matrix[r][c] = value;
}

void Matrix::display() {
	cout << "Matrix:" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Matrix::randomSet(int randomNumber) {
	srand(time(NULL));//rand() fonksiyonundan önce kullanılır ve rastgele sayı üretmek için kullanılır. 
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = rand() % randomNumber;//0 dan 10 a kadar rastgele değer ataması yaptık.
		}
	}
}

void Matrix::identityMatrixSet() { //Birim matrix
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			i == j ? matrix[i][j] = 1 : matrix[i][j] = 0;
		}
	}
}

void Matrix::addMatrix(const Matrix& othMatrix) {
	if (row != othMatrix.row || col != othMatrix.col) {
		cout << "Row and column should be equal." << endl;
		return;
	}
	Matrix result(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result.matrix[i][j] = (matrix[i][j] + othMatrix.matrix[i][j]);
		}
	}
	result.display();
}








