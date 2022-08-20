#include "../../std_lib_facilities.h"

void get_an_error();

int main() {
    try {
        get_an_error();
        return 0;
    } catch(exception &e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    } catch(...) {
        cerr << "Oops: unknown exception\n";
        return 2;
    }
}

void get_an_error() {
    throw runtime_error("run time error");
}