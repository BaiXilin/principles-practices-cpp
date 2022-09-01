#include "../../std_lib_facilities.h"

enum class Month {
    jan = 0, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// overloading operator ++ on Month class
Month operator++(Month &m) {
    m = (int(m) == int(Month::dec)) ? Month::jan : Month(int(m) + 1);
    return m;
}

// overloading the output operator
ostream& operator<<(ostream& os, Month m) {
    return os << month_tbl[int(m)];
}

int main() {
    Month m = Month::sep;

    ++m;    // oct
    cout << m << "\n";

    ++m;    // nov
    cout << m << "\n";

    ++m;    // dec
    cout << m << "\n";

    ++m;    // jan
    cout << m << "\n";
}