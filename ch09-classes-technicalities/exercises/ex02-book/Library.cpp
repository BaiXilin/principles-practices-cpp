#include "Library.h"

void Library::add_book(std::string isbn, std::string title, std::string author, int genre) {
    books.push_back(Book{isbn, title, author, genre});
}

void Library::add_patron(std::string name, std::string card_num) {
    patrons.push_back(Patron{name, card_num});
}

void Library::change_patron_balance(int i, double new_balance) {
    if(i < 0 || i >= patrons.size())
        throw std::out_of_range("No such patron");
    patrons[i].set_fee(new_balance);
}

// if a book is checked out, create a transaction
// we locate books by isbn series number and locate patron by their library card number to avoid duplication
void Library::checkout_book(std::string book_isbn, std::string patron_card_num) {
    // if the patron does not exist, throw exception
    int book_location = find_book(book_isbn);
    if(book_location == -1) throw ERROR_NONEXIST_BOOK{};
    
    // if the book does not exist, throw exception
    int patron_location = find_patron(patron_card_num);
    if(patron_location == -1) throw ERROR_NONEXIST_PATRON{};

    // if the user is owning fee, throw exception
    if(own_fee(patrons[patron_location])) throw ERROR_OWN_FEE{};

    // the book can be checked out to the patron
    Chrono::Date today{2022, Chrono::Month::sep, 1};
    transactions.push_back(Transaction{books[book_location], patrons[patron_location], today});
}

// return the index of located book in the vector, -1 if not found
int Library::find_book(std::string isbn) const {
    for(int i = 0; i < books.size(); i++) {
        if(books[i].get_isbn() == isbn) return i;
    }
    return -1;
}

// return the index of located patron in the vector, -1 if not found
int Library::find_patron(std::string card_num) const {
    for(int i = 0; i < patrons.size(); i++) {
        if(patrons[i].get_card_num() == card_num) return i;
    }
    return -1;
}

// find out all patrons in the library who own fee
std::vector<Patron> Library::patrons_own_fee() const {
    std::vector<Patron> patrons_own_fee;
    for(int i = 0; i < patrons.size(); i++) {
        if(own_fee(patrons[i]))
            patrons_own_fee.push_back(patrons[i]);
    }
    return patrons_own_fee;
}

Transaction::Transaction(Book b, Patron p, Chrono::Date d): book{b}, patron{p}, date{d} {}