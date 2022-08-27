#include "../../../std_lib_facilities.h"

double calc_sum(const vector<double> &price, const vector<double> &weight) {
    if(price.size() != weight.size()) {
        return -1;
    }
    double sum = 0;
    for(int i = 0; i < price.size(); i++) {
        sum += price[i] * weight[i];
    }
    return sum;
}

int main() {
    vector<double> price{1.5, 3.5, 2.25, 7, 2};
    vector<double> weight{3.75, 5.5, 10, 2.25, 2};

    cout << "sum is $" << calc_sum(price, weight) << "\n";
}