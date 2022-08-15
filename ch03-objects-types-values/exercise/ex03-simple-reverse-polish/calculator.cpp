// a simple reverse polish calculator
// stores operation and integers in a string
// sample input: + 100 3.14

#include "../../../std_lib_facilities.h"

int main() {
    char operation;
    double operand1, operand2, result;
    
    cout << "Enter operation: ";
    cin >> operation;
    cin >> operand1;
    cin >> operand2;

    if(operation == '+') {
        result = operand1 + operand2;
    } else if(operation == '-') {
        result = operand1 - operand2;
    } else if(operation == '*') {
        result = operand1 * operand2;
    } else if(operation == '/') {
        result = operand1 / operand2;
    } else {
        cout << "Unsupported operation\n";
        return 1;
    }

    cout << operand1 << operation << operand2 << " = " << result << "\n";
    return 0;
}