#include "../../../std_lib_facilities.h"

int main() {
    vector<string> names(5);
    vector<int> ages(5);
    for(int i = 0; i < names.size(); i++) {
        string temp_name;
        int temp_age;

        cout << "Enter a name: ";
        cin >> temp_name;
        cout << "Enter a age: ";
        cin >> temp_age;

        names[i] = temp_name;
        ages[i] = temp_age;
    }

    vector<string> names_copy = names;
    sort(names.begin(), names.end());

    for(int i = 0; i < names.size(); i++) {
        int age;
        for(int j = 0; j < names.size(); j++) {
            if(names_copy[j] == names[i]) {
                age = ages[j];
                break;
            }
        }
        cout << "name = " << names[i] << "\tage = " << age << "\n";
    }
}