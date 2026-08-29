#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2) {
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorPairV2(int& reading1, int& reading2) {
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorPairV3(int* reading1, int* reading2) {
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;
}

int main() {

    int A = 55;
    int B = 12;

    cout << "--- V1: Call by Value ---" << endl;
    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV1(A, B);
    /*
     V1 uses Call by Value, so the function receives copies of A and B.
     Any changes made inside the function affect only those local copies.
     Therefore, the original A and B in main() remain unchanged.
     V2 and V3 use references/pointers, so they can modify the original variables.
    */

    cout << "After  : A=" << A << "  B=" << B << " <- values unchanged" << endl;

    cout << "--- V2: Call by Reference ---" << endl;
    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV2(A, B);

    cout << "After  : A=" << A << "  B=" << B << " <- values swapped" << endl;

    cout << "--- V3: Call by Pointer ---" << endl;
    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV3(&A, &B);

    cout << "After  : A=" << A << "  B=" << B << " <- values swapped back" << endl;

    return 0;
}
