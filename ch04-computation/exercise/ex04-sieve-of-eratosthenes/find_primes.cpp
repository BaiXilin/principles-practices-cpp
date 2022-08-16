// use the method of Sieve of Eratosthenes to find prime
#include "../../../std_lib_facilities.h"

// find all prime numbers from 1 to upper limit. Upper limit specifies by the user
int main() {
    int upper;
    cout << "enter an integer larger than 2 to mark the upper limit: ";
    cin >> upper;

    // vector<int> primes;
    vector<int> candidates(upper+1, 0); // 0 to upper limit
    vector<int> is_prime(upper+1, 1);

    // populate the candidate vectors
    for(int i = 0; i < upper + 1; i++) {
        candidates[i] = i;
    }
    is_prime[0] = 0;
    is_prime[1] = 0;

    for(int i = 2; i < upper + 1; i++) {
        for(int j = i; j < candidates.size(); j++) {
            if(candidates[j] != i && candidates[j] % i == 0) {
                is_prime[j] = 0;
            }
        }
    }

    for(int i = 0; i < candidates.size(); i++) {
        if(is_prime[i]) {
            cout << candidates[i] << "\t";
        }
    }
    cout << "\n";
}