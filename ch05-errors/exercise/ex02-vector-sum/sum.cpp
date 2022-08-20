#include "../../../std_lib_facilities.h"

int main() {
    int sum_size;
    cout << "enter the number of values you want to sum: ";
    cin >> sum_size;
    if(!cin) error("invalid input");

    vector<double> integers;

    cout << "enter some integers ('|' to stop): \n";
    for(int temp; cin >> temp;) {
        if(!cin) error("invalid input");
        if(temp == int('|')) break;
        integers.push_back(temp);
    }

    if(sum_size > integers.size()) {
        cout << "sum size is larger than the number of integers. Summing all integers entered instead\n";
        sum_size = integers.size();
    }

    int sum = 0;
    for(int i = 0; i < sum_size; i++) {
        sum += integers[i];
    }
    cout << "sum = " << sum << "\n";
}