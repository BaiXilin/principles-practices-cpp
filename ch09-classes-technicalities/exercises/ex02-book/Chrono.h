#include <iostream>
#include <vector>

#ifndef CHRONO_H
#define CHRONO_H

namespace Chrono {
    enum class Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    class Date {
    public:
        class Invalid{};    // throw as exception

        Date();             // default constructor
        Date(int y, Month m, int d);

        // non-modifying operations
        int day() const { return d; } // in-line definition
        Month month() const { return m; }
        int year() const { return y; }

        // modifying operations
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

    private:
        int y;
        Month m;
        int d;
    };

    // helper functions
    bool is_date(int y, Month m, int d);
    bool leapyear(int y);

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    std::ostream& operator<<(std::ostream& os, const Date& d);
    std::istream& operator>>(std::istream& is, Date& dd);
}

#endif