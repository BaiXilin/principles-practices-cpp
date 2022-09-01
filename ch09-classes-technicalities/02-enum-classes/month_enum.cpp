#include "../../std_lib_facilities.h"

// in class scope, needs :: to access
enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// introduce enum vars into the global scope
enum Week {
    Mon, Tue, Wed, Thu, Fri, Sat, Sun   // no explicit start value. So 0 by default
};

int main() {
    Month m1 = Month::jan;
    // Month is a different than the underlying int, needs explicit conversion
    Month m9 = Month(9);

    cout << "jan: " << int(m1) << "\n";
    cout << "sep: " << int(Month::sep) << "\n";

    // enum are accessible without Week::
    cout << "Mon: " << int(Mon) << "\n";
}