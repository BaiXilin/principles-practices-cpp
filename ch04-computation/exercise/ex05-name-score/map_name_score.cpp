#include "../../../std_lib_facilities.h"

int main() {
    // enter a set of name-value pairs
    string name = "";
    int score = 0;
    vector<string> names;
    vector<string> names_in_order;
    vector<int> scores;

    while(true) {
        cin >> name;
        cin >> score;
        if(name != "NoName" || score != 0) {
            names.push_back(name);
            names_in_order.push_back(name);
            scores.push_back(score);
        } else {
            break;
        }
    }

    sort(names_in_order);
    string prev = names_in_order[0];
    for(int i = 1; i < names_in_order.size(); i++) {
        if(names_in_order[i] == prev) {
            cout << names_in_order[i] << " duplicated" << "\n";
        } else {
            prev = names_in_order[i];
        }
    }

    for(int i = 0; i < names.size(); i++) {
        cout << names[i] << "\t" << scores[i] << "\n";
    }

    // check if each name is unique
}