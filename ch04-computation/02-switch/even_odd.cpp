// even odd under 10 with switch statment
#include "../../std_lib_facilities.h"

int main() {
    int in;
    cout << "Enter a digit under 10: ";
    cin >> in;

    switch(in) {
        case 0: case 2: case 4: case 6: case 8:
            cout << "even\n";
            break;
        case 1: case 3: case 5: case 7: case 9:
            cout << "odd\n";
            break;
        default:
            cout << "please enter a digit from 0 to 10\n";
    }
    return 0;
}