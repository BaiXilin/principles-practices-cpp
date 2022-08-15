// ordering three names: Steinbeck, Hemingway, Filzgerald in order from least to hightest

#include "../../../std_lib_facilities.h"

int main() {
    string name1 = "Steinbeck";
    string name2 = "Hemingway";
    string name3 = "Filzgerald";

    string name_order_1, name_order_2, name_order_3;

    if (name1 < name2 && name1 < name3) {
        name_order_1 = name1;
        if(name2 < name3) {
            name_order_2 = name2;
            name_order_3 = name3;
        } else {
            name_order_2 = name3;
            name_order_3 = name2;
        }
    } else if(name2 < name1 && name2 < name3) {
        name_order_1 = name2;
        if(name1 < name3) {
            name_order_2 = name1;
            name_order_3 = name3;
        } else {
            name_order_2 = name3;
            name_order_3 = name1;
        }
    } else {
        name_order_1 = name3;
        if(name1 < name2) {
            name_order_2 = name1;
            name_order_3 = name2;
        } else {
            name_order_2 = name2;
            name_order_3 = name1;
        }
    }

    cout << name_order_1 << "\t" << name_order_2 << "\t" << name_order_3 << "\n";
}