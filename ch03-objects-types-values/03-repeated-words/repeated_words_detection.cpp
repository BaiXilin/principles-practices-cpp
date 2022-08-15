#include "../../std_lib_facilities.h"

int main() {
    int num_of_words = 0;
    string previous = "";
    string current;

    while(cin >> current) {
        num_of_words++;
        if(current == previous) {
            cout << "word number: " << num_of_words << "\n";
            cout << "repeated word: " << current << "\n";
        }
        previous = current;
    }
    // on Linux system, Ctrl+D is end of file. EOL will terminate this program
    // on Windows, EOL is Ctrl+Z
}