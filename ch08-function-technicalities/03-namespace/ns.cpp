#include <iostream>
using namespace std;    // using directives

namespace X {
    int var = 0;
    void print();
}

namespace Y {
    int var = 0;
    void print();
}

namespace Z {
    int var = 0;
    void print();
}

int main() {
    X::var = 7;
    X::print(); // namespace X

    using namespace Y;
    var = 9;
    print();    // namespace Y

    {
        using Z::var;
        using Z::print;
        var = 11;
        print();    // namespace Z
    }
    print();    // using namespace Y still in effect, so namespace Y
    X::print(); // override, namespace X
}

void X::print() {
    cout << "X = " << var << "\n";
}

void Y::print() {
    cout << "Y = " << var << "\n";
}

void Z::print() {
    cout << "Z = " << var << "\n";
}
