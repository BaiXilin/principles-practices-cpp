#include "../../../std_lib_facilities.h"

void print(string labeling, const vector<int> &fib);
void fibonacci(int x, int y, vector<int> &v, int n);

int main() {
    vector<int> fib_nums(0);
    fibonacci(1,2, fib_nums, 10);
    print("Fibonacci Numbers", fib_nums);

    return 0;
}

void print(string labeling, const vector<int> &v) {
    cout << labeling << ": ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

// start the fibonacci series with x and y for n elements. Return by writing to v (which should be an empty vector reference)
// error condition: n is smaller than 2, v is not an empty vector
void fibonacci(int x, int y, vector<int> &v, int n) {
    if(n < 2) {
        error("n must be smaller than 2");
    }
    if(v.size() != 0) {
        error("vector not empty");
    }

    v.push_back(x);
    v.push_back(y);
    for(int i = 2; i < n; i++) {
        v.push_back(v[i - 1] + v[i - 2]);
    }
    return;
}