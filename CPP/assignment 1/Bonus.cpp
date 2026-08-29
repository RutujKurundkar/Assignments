#include <iostream>
using namespace std;

struct Layout1 {
    char c1;
    int i;
    char c2;
};

struct Layout2 {
    int i;
    char c1;
    char c2;
};

int main() {
    cout << "Size of Layout1: " << sizeof(Layout1) << endl;
    cout << "Size of Layout2: " << sizeof(Layout2) << endl;

    /*
   1. Layout1 and Layout2 have the same members but different sizes because
    the order of members affects how the compiler arranges them in memory.
   2. Padding is extra unused memory added by the compiler to properly align
    data members according to their alignment requirements.
   3. Member order matters in network packet headers and hardware register
    maps because the exact memory layout and offsets must match the required format.
    */

    return 0;
}
