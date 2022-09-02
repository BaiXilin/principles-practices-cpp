#include "Book.h"
#include <regex>

Book::Book(std::string isbn, std::string title, std::string author, int genre)
    : isbn{isbn}, title{title}, author{author} {
    if(!valid_isbn(isbn)) throw Invalid{};

    if(!valid_genre(genre)) 
        throw Invalid{};
    else 
        this->genre = Genre(genre);
}

bool valid_isbn(std::string isbn) {
    static std::regex isbn_regex{"[0-9]+-[0-9]+-[0-9]+-[a-zA-Z0-9]"};   // n-n-n-x, n is integer, x is integer/letter
    return std::regex_match(isbn, isbn_regex);

}

bool valid_genre(int g) {
    if(g < int(Genre::fiction) || g > int(Genre::children)) return false;
    return true;
}
// two books are equal when their isbn numbers are the same
bool operator==(const Book& a, const Book& b) {
    return a.get_isbn() == b.get_isbn();
}

bool operator!=(const Book& a, const Book& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
    return os << b.get_title() << "\n" << b.get_author() << "\n" << b.get_isbn();
}