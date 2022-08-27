#include "../../std_lib_facilities.h"

void swap_v(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_cr(const int &a, const int &b) {
    int temp = a;
    // error: const reference cannot be modified
    //a = b;
    //b = temp;
}

int main() {
    int x = 7;
    int y = 9;

    swap_v(x, y);
    cout << "swap_v: ";
    cout << "x = " << x << "\ty = " << y << "\n";   // original value unchanged as copies are passed

    swap_r(x, y);
    cout << "swap_r: ";
    cout << "x = " << x << "\ty = " << y << "\n";   // values changed as references are passed

    const int cx = 7;
    const int cy = 9;
    
    swap_v(cx, cy);
    cout << "swap_v const value: ";
    cout << "x = " << cx << "\ty = " << cy << "\n";

    // swap_r(cx, cy);  // error: cannot pass modifiable reference of const variable
}