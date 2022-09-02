#include "name_pairs.h"
#include <iostream>

int main() {
    NamePairs np;

    // read inputs from user
    np.read_names();
    np.read_ages();

    std::cout << "Before sort: " << std::endl;
    np.print();

    np.sort();
    std::cout << "After sort: " << std::endl;
    np.print();

    std::cout << "<< print gives:" << std::endl;
    std::cout << np << std::endl;
}