#include <iostream>
using namespace std;

int main() {
    int statusReg  = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg    = 0b11001010;

    const int* regPtr1 = &statusReg;
    cout << "Status register: " << *regPtr1 << endl;

    // *regPtr1 = 0b11111111;
    // Error: Cannot write because regPtr1 points to const int.

    // regPtr1 = &dataReg;
    // No error: regPtr1 can be repointed because the pointer itself is not const.

    int* const regPtr2 = &controlReg;
    *regPtr2 = 0b11111111;
    cout << "Control register: " << *regPtr2 << endl;

    // regPtr2 = &dataReg;
    // Error: Cannot repoint because regPtr2 is a const pointer.

    const int* const regPtr3 = &statusReg;
    cout << "ROM config: " << *regPtr3 << endl;

    // *regPtr3 = 0b11111111;
    // Error: Cannot write because regPtr3 points to const int.

    // regPtr3 = &dataReg;
    // Error: Cannot repoint because regPtr3 is a const pointer.

    return 0;
}
