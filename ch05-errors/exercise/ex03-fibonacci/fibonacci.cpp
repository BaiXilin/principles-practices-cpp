#include "../../../std_lib_facilities.h"
#include <limits>

bool isAdditionOverflow(int, int);

const int INT_MAX = std::numeric_limits<int>::max();

int main() {
    cout << "The following program will output the largest integer in Fibonacci series\n";
    int a = 0, b = 1;
    int fib = 0;
    while(true) {
        if(isAdditionOverflow(a, b)) {
            break;
        }
        fib = a + b;
        a  = b;
        b = fib;
        cout << fib << "\n";
    }
    cout << "The largest element in Fibonacci series is " << fib << "\n";
    return 0;
}

bool isAdditionOverflow(int a, int b) {
    int sum = a + b;
    return (a < 0 && b < 0 && sum > 0) || (a > 0 && b > 0 && sum < 0);
}