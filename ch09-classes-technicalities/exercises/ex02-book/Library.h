#include <vector>
#include "Book.h"
#include "Patron.h"
#include "Chrono.h"

struct Transaction {
    Book book;
    Patron patron;
    Chrono::Date date;

    Transaction(Book b, Patron p, Chrono::Date d);

};

class Library {
    public:
        class ERROR_NONEXIST_PATRON{};
        class ERROR_NONEXIST_BOOK{};
        class ERROR_OWN_FEE{};

        void add_book(std::string isbn, std::string title, std::string author, int genre);
        void add_patron(std::string name, std::string card_num);
        void checkout_book(std::string isbn, std::string patron_name);

        void change_patron_balance(int i, double new_balance);

        std::vector<Patron> patrons_own_fee() const;
    private:
        std::vector<Patron> patrons;
        std::vector<Book> books;
        std::vector<Transaction> transactions;

        // helpers
        int find_book(std::string isbn) const;
        int find_patron(std::string card_num) const;
};