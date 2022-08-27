#include "../../../std_lib_facilities.h"

void f(const int);

int main() {
    int num = 7;
    f(7);
}

void f(const int x) {
    cout << x << '\n';
}