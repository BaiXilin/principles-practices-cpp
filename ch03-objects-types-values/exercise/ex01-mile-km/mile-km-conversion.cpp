#include "../../../std_lib_facilities.h"

int main() {
    double mile, km;
    cout << "Enter mile: ";
    cin >> mile;

    km = mile * 1.609;
    cout << mile << " miles is " << km << "km.\n";
}