#include "Chrono.h"

namespace Chrono {

std::vector<int> days_in_month{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {
    if(!is_date(yy, mm, dd)) throw Invalid{};
}

const Date& default_date() {
    static Date dd{2001, Month::jan, 1};
    return dd;
}

Date::Date(): y{default_date().year()}, m{default_date().month()}, d{default_date().day()} {
}

// take 1AD Jan 1st as base.
void Date::add_day(int n) {
    if(n < 0) throw Invalid{};

    int days_since_base = 0;

    for(int i = 1; i < y; i++) {
        if(leapyear(i))
            days_since_base += 366;
        else
            days_since_base += 365;
    }

    for(int i = int(Month::jan); i < int(m); i++) {
        if(i == int(Month::feb) && leapyear(y))
            days_since_base += 29;
        else if(i == int(Month::feb))
            days_since_base += 28;
        else
            days_since_base += days_in_month[i];
    }
    days_since_base += d;

    days_since_base += n;

    int new_year = 1, new_day, new_month = 1;

    while(true) {
        if(leapyear(new_year)) {
            if(days_since_base < 366) {
                break;
            } else {
                new_year++;
                days_since_base -= 366;
            }
        } else {
            if(days_since_base < 365) {
                break;
            } else {
                new_year++;
                days_since_base -= 365;
            }
        }
    }

    while(true) {
        if(leapyear(new_year) && new_month == int(Month::feb)) {
            if(days_since_base < 29) {
                break;
            } else {
                days_since_base -= 29;
                new_month++;
            }
        } else {
            if(days_since_base < days_in_month[new_month]) {
                break;
            } else {
                days_since_base -= days_in_month[new_month];
                new_month++;
            }
        }
    }

    new_day = days_since_base;

    y = new_year;
    m = Month(new_month);
    d = new_day;
}

void Date::add_month(int n) {
    if(n < 0) throw Invalid{};

    int incr_year = (int(m) + n) / 12;
    int new_m = (int(m) + n) % 12;

    add_year(incr_year);
    m = Month(new_m);
}

void Date::add_year(int n) {
    if(n < 0) throw Invalid{};

    if(m == Month::feb && d == 29 && !leapyear(y+n)) {  // mind leap year
        m = Month::mar;
        d = 1;
    }
    y += n;
}

bool is_date(int y, Month m, int d) {
    if(d <= 0) return false;
    if(m < Month::jan || m > Month::dec) return false;

    int days_in_month = 31;
    switch(m) {
        case Month::feb:
        days_in_month = (leapyear(y)) ? 29:28;
        break;
        case Month::apr: case Month::jun: case Month::sep: case Month::nov:
        days_in_month = 30;
        break;
    }
    if(days_in_month < d) return false;

    return true;
}

bool leapyear(int y) {
    if(y % 4 == 0 && y % 100 != 0) return true;
    if(y % 400 == 0) return true;
    return false;
}

bool operator==(const Date& a, const Date& b) {
    return a.year() == b.year()
        && a.month() == b.month()
        && a.day() == b.day();
}

bool operator!=(const Date& a, const Date& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    return os << '(' << d.year()
              << ',' << int(d.month())
              << ',' << d.day()
              << ')';
}

std::istream& operator>>(std::istream& is, Date& dd) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if(!is) return is;
    if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
        is.clear(std::ios_base::failbit);   // set fail bit
        return is;
    }

    dd = Date(y, Month(m), d);
    return is;
}

}