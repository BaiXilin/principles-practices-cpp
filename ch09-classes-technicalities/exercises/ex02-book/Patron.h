#include <string>

#ifndef PATRON_H
#define PATRON_H

class Patron {
    public:
        Patron(std::string name, std::string card_num);

        std::string get_name() const { return name; }
        std::string get_card_num() const { return card_num; }
        double get_fee() const { return fee; }

        void set_fee(double new_amount);
    private:
        std::string name;
        std::string card_num;
        double fee{0};
};

bool own_fee(const Patron& p);

#endif