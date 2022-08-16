#include "../../../std_lib_facilities.h"

int main() {
    vector<double> temps;
    for(double temp; cin >> temp;) {
        temps.push_back(temp);
    }

    // calculating the average
    double sum = 0;
    for(double temp : temps) {
        sum += temp;
    }
    cout << "average temperature is " << sum/temps.size() << "\n";

    // find the median
    // if the size is odd, the data in middle is median
    // if the size is even, the average of two data in middle is median
    sort(temps);
    double median;

    if(temps.size() % 2 == 1) {
        median = temps[temps.size()/2];
    } else {
        median = (temps[temps.size()/2 - 1] + temps[temps.size()/2]) / 2;
    }
    cout << "median temperature is " << median << "\n";
}