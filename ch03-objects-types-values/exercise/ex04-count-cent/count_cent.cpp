// enter the number of different coins and output the total number of cents
#include "../../../std_lib_facilities.h"

int main() {
    int num_pennies, num_nickles, num_dimes, num_quarters, num_half_dollars, num_one_dollars;
    cout << "Enter the number of pennies: ";
    cin >> num_pennies;
    cout << "Enter the number of nickles: ";
    cin >> num_nickles;
    cout << "Enter the number of dimes: ";
    cin >> num_dimes;
    cout << "Enter the number of quarters: ";
    cin >> num_quarters;
    cout << "Enter the number of half dollars: ";
    cin >> num_half_dollars;
    cout << "Enter the number of one dollars: ";
    cin >> num_one_dollars;

    int total_cents;
    total_cents = num_pennies * 1 + num_nickles * 5 + num_dimes * 10 + num_quarters * 25 + num_half_dollars * 50 + num_one_dollars * 100;
    cout << "The value of all of your coins is " << total_cents << " cents.\n";

    return 0;
}