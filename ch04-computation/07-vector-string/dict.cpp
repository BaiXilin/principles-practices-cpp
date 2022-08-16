// list of sorted words
#include "../../std_lib_facilities.h"

int main() {
    vector<string> words;
    for(string temp; cin >> temp;) {
        words.push_back(temp);
    }

    cout << "Number of words is " << words.size() << "\n";

    sort(words);

    for(int i = 0; i < words.size(); i++) {
        // is this a new word?
        if(i == 0 || words[i-1] != words[i]) {
            cout << words[i] << "\n";
        }
    }
}