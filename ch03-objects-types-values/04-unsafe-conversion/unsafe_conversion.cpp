#include "../../std_lib_facilities.h"

int main() {
    double d = 0;
    
    while(cin >> d) {
        int i = d;              // squeeze a double into an integer
        char c = i;             // squeeze an integer into a char
        int i2 = c;             // get the integer value of char

        cout << "d == " << d
        << " i == " << i
        << " i2 == " << i2
        << " char(" << c << ")\n";
    }
    return 0;
}