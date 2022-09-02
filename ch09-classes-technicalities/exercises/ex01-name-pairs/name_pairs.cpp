#include "name_pairs.h"
#include <iostream>
#include <algorithm>

void NamePairs::read_names() {
    std::cout << "Enter names. Enter q to end input" << std::endl;
    
    for(std::string temp; std::cin >> temp;) {
        if(temp == "q") {
            break;
        }
        this->name.push_back(temp);
    }
}

void NamePairs::read_ages() {
    std::cout << "Enter ages. Enter -1 to end input" << std::endl;
    
    for(double temp; std::cin >> temp;) {
        if(temp == -1) {
            break;
        }
        this->age.push_back(temp);
    }
}

void NamePairs::sort() {
    if(name.size() != age.size()) throw Invalid{};

    std::vector<std::string> temp_names = name;
    std::vector<double> sorted_age;

    std::sort(name.begin(), name.end());

    for(int i = 0; i < name.size(); i++) {
        for(int j = 0; j < name.size(); j++) {
            if(temp_names[j] == name[i]) {
                sorted_age.push_back(age[j]);
                continue;
            }
        }
    }
    age = sorted_age;
}

void NamePairs::print() {
    if(name.size() != age.size()) throw Invalid{};

    for(int i = 0; i < name.size(); i++) {
        std::cout << name[i] << ": " << age[i] << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const NamePairs& np) {
    for(int i = 0; i < np.name.size(); i++) {
        os << np.name[i] << ": " << np.age[i] << std::endl;
    }

    return os;
}

bool operator==(const NamePairs& a, const NamePairs& b) {
    if(a.name.size() != b.name.size()) return false;
    if(a.age.size() != b.age.size()) return false;

    for(int i = 0; i < a.name.size(); i++) {
        if(a.name[i] != b.name[i] || a.age[i] != b.age[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const NamePairs& a, const NamePairs& b) {
    return !(a == b);
}