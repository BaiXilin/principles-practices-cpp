#include <vector>
#include <string>
#include <iostream>

class NamePairs {
    public:
    class Invalid{};
    void read_names();
    void read_ages();
    void sort();
    void print();
    
    std::vector<std::string> name;
    std::vector<double> age;
};

std::ostream& operator<<(std::ostream& os, const NamePairs& np);
bool operator==(const NamePairs& a, const NamePairs& b);
bool operator!=(const NamePairs& a, const NamePairs& b);
 