#include "Chrono.h"

int main() {
    Chrono::Date d1{2022, Chrono::Month(8), 31};
    d1.add_day(366);
    std::cout << d1 << std::endl;
}