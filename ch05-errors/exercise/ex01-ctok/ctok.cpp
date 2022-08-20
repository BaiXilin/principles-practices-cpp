#include "../../../std_lib_facilities.h"

double ctok(double);
double ktoc(double);

constexpr double abs_zero_c = -273.15;
constexpr double abs_zero_k = 0;

int main() {
    char unit;
    double in_temp;

    cout << "Enter temperature followed by unit (c or k): ";
    cin >> in_temp;
    if(!cin) {
        cout << "Invalid input\n";
    }
    cin >> unit;
    if(!cin) {
        cout << "Invalid input\n";
    }

    double out_temp;
    try {
        if(unit == 'c') {
            out_temp = ctok(in_temp);
            cout << in_temp << "c = " << out_temp << "k\n";
        } else if(unit == 'k') {
            out_temp = ktoc(in_temp);
            cout << in_temp << "k = " << out_temp << "c\n";
        } else {
            cout << "Invalid unit\n";
        }
    } catch(out_of_range &e) {
        cout << "error: " << e.what() << "\n"; 
    } catch(...) {
        cout << "unknown error\n";
    }

    return 0;
}

double ctok(double c) {
    if(c < abs_zero_c) throw out_of_range("Celcius temperature lower than absolute zero");
    return c + abs_zero_c;
}

double ktoc(double k) {
    if(k < abs_zero_k) throw out_of_range("Kalvin temperature lower than absolute zero");
    return k - abs_zero_c;
}