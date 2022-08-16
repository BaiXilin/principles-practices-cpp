#include "../../../std_lib_facilities.h"

int main() {
    int in;
    cout << "enter an integer between 1 and 100, and I will guess it out!" << "\n";
    cin >> in;

    int guess = 50;
    double step = guess / 2.0;
    char confirm;

    while(in != guess) {
        cout << "Is the number you are thinking less than " << guess << "? (y or n)\n";
        cin >> confirm;
        if(confirm == 'y') {
            guess -= step;
            step = ceil(step / 2);
        } else if(confirm == 'n') {
            guess += step;
            step = ceil(step / 2);
        } else {
            cout << "unknown input, please enter y or n\n";
        }
    }
    cout << "the number you are thinking is " << guess << "\n";
}