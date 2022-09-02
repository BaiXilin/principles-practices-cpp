#include "Library.h"

int main() {
    Library dc;

    dc.add_book("1-1-1-1", "Martian", "Andy Weir", int(Genre::fiction));
    dc.add_book("1-1-1-2", "Project Hail Mary", "Andy Weir", int(Genre::fiction));
    dc.add_patron("James Bond", "12345-12345");
    // James Bond owns money
    dc.change_patron_balance(0, -10);

    try {
        dc.checkout_book("1-1-1-1", "12345-12345");
    } catch(Library::ERROR_NONEXIST_BOOK) {
        std::cout << "Cannot checkout: No such book" << std::endl;
    } catch(Library::ERROR_NONEXIST_PATRON) {
        std::cout << "Cannot checkout: No such patron" << std::endl;
    } catch(Library::ERROR_OWN_FEE) {
        std::cout << "Cannot checkout: Patron owning fee" << std::endl;
    } catch(...) {
        std::cout << "Unknown error" << std::endl;
    }
    
    std::vector<Patron> owning_fee = dc.patrons_own_fee();
    std::cout << owning_fee[0].get_name() << " owns $" << owning_fee[0].get_fee() << std::endl;
}