#include "Patron.h"

Patron::Patron(std::string name, std::string card_num): name{name}, card_num{card_num} {}

void Patron::set_fee(double new_amount) {
    fee = new_amount;
}

bool own_fee(const Patron& p) {
    if(p.get_fee() < 0)
        return true;
    return false;
}