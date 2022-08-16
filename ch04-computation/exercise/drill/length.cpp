#include "../../../std_lib_facilities.h"

constexpr double cm_per_m = 100;
constexpr double cm_per_in = 2.54;
constexpr double in_per_ft = 12;

int main() {
    vector<double> lengths;
    double largest = 0, smallest = 0;
    double meter_sum;
    char unit;

    for(double temp; cin >> temp;) {
        cin >> unit;
        
        // unify the unit to meter
        if(unit == 'm') {
        } else if(unit == 'c') {
            temp = temp / cm_per_m;
        } else if(unit == 'f') {
            temp = temp * in_per_ft * cm_per_in / cm_per_m;
        } else if(unit == 'i') {
            temp= temp * cm_per_in / cm_per_m;
        } else {
            cout << "invalid unit" << "\n";
            continue;
        }
        meter_sum += temp;

        lengths.push_back(temp);
        if(lengths.size() == 1) {
            largest = temp;
            smallest = temp;
        } else {
            if(largest < temp) {
                largest = temp;
            }
            if(smallest > temp) {
                smallest = temp;
            }
        }
    }

    sort(lengths);

    for(int i = 0; i < lengths.size(); i++) {
        cout << lengths[i] << " ";
    }
    cout << "\n";

    cout << "Largest length = " << largest << "m\n";
    cout << "Smallest length = " << smallest << "m\n";
    cout << "Average = " << meter_sum / lengths.size() << "m\n";
}