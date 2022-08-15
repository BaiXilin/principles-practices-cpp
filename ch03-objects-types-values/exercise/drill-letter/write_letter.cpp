#include "../../../std_lib_facilities.h"

int main() {
    string sender_name, receiver_name, friend_name;
    int friend_age;
    char friend_sex;

    cout << "Enter sender's name\n";
    cin >> sender_name;
    cout << "Hello " << sender_name << "\n";

    cout << "Enter receiver's name\n";
    cin >> receiver_name;

    cout << "Enter friend's name\n";
    cin >> friend_name;

    cout << "Enter friend's sex\n";
    cin >> friend_sex;
    if(friend_sex != 'm' && friend_sex != 'f') {
        simple_error("You're kidding");
    }

    cout << "Enter friend's age\n";
    cin >> friend_age;
    if(friend_age <= 0 || friend_age >= 110) {
        simple_error("You're kidding");
    }

    cout << "Dear " << receiver_name << ",\n";
    cout << "\tHow are you doing?\n";
    cout << "\tHave you seen " << friend_name << "? ";
    if(friend_sex == 'm') {
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    } else {
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    }

    if(friend_age == 17) {
        cout << "\tNext year you will be able to vote.\n";
    } else if(friend_age < 12) {
        cout << "\tNext year you will be " << friend_age + 1 << ".\n";
    } else if(friend_age >= 70) {
        cout << "\tI hope you are enjoying retirement.\n";
    }

    cout << "Sincerely,\n";
    cout << sender_name << "\n";
}