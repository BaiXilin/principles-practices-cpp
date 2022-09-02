#include <string>
#include <iostream>

#ifndef BOOK_H
#define BOOK_H

enum class Genre {
    fiction, nonfiction, periodical, biography, children
};

class Book {
    public:
        class Invalid{};    // throw invalid as exception

        Book(std::string isbn, std::string title, std::string author, int genre);

        std::string get_isbn() const { return isbn; }
        std::string get_title() const { return title; }
        std::string get_author() const { return author; }
        bool get_check_status() const { return checked_out; };

        void check_in_out() { checked_out = !checked_out; }
    private:
        std::string isbn;
        std::string title;
        std::string author;
        Genre genre{Genre::fiction};
        bool checked_out{false};
};

bool valid_isbn(std::string isbn);
bool valid_genre(int g);

// operator overloading
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
std::ostream& operator<<(std::ostream& os, const Book& b);

#endif