// inch to cm conversion with unit
#include "../../std_lib_facilities.h"

int main() {
    constexpr double cm_per_inch = 2.54;
    double length = 1;
    char unit = ' ';

    cout << "Enter a length followed by a unit (c or i)\n";
    cin >> length >> unit;

    if(unit == 'c') {
        cout << length << "cm == " << length / cm_per_inch << "in\n";
    } else if(unit == 'i') {
        cout << length << "in == " << cm_per_inch * length << "cm\n";
    } else {
        cout << "Invalid unit.\n";
    }
}