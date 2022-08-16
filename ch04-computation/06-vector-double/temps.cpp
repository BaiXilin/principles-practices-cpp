#include "../../std_lib_facilities.h"

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

    // find the median (not perfect, see exercise)
    sort(temps);
    cout << "median temperature is " << temps[temps.size()/2] << "\n";
}