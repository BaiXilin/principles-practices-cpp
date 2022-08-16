#include "../../std_lib_facilities.h"

int main() {
    vector<int> primes = {2,3,5,7,11,13,17,19};

    // a for range loop. Will iterate through all elements in the vector
    for(int prime : primes) {
        cout << prime << "\t";
    }
    cout << "\n";
}