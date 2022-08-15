#include "../../std_lib_facilities.h"

int main() {
    string first_name;
    int age;
    
    cout << "Enter your first name and age\n";
    cin >> first_name;  // cin terminated by whitespace, cin is sensitive to type
    cin >> age;
    cout << "Hello, " << first_name << " (age " << age << ")\n";

    return 0;
}