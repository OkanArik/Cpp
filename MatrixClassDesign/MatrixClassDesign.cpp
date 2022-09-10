#include "Matrix.h"

using namespace std;

int main()
{
    Matrix mainMatrix;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mainMatrix.setValue(i, j, i * j);
        }
    }
    mainMatrix.display();
    mainMatrix.randomSet(10);
    mainMatrix.display();

    Matrix mainMatrix1=mainMatrix;
    mainMatrix1.display();
    mainMatrix1.identityMatrixSet();
    mainMatrix1.display();

    Matrix mainMatrix2;
    mainMatrix2.randomSet();
    mainMatrix2.display();

    Matrix mainMatrix3;
    mainMatrix3.randomSet(20);
    mainMatrix3.display();

    mainMatrix2.addMatrix(mainMatrix3);

    return 0;
}
