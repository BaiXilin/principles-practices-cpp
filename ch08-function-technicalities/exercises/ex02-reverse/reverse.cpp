#include "../../../std_lib_facilities.h"
#include "rev.h"

int main() {
    vector<int> vec_int{1,2,3,4,5};
    vector<int> rev_vec_int = ret_reverse(vec_int);
    print("returned reversed integer vector", rev_vec_int);

    reverse(vec_int);
    print("reversed original interger vector", vec_int);

    vector<string> vec_str{"a", "b", "c", "d", "e"};
    vector<string> ret_vec_str = ret_reverse(vec_str);
    print("returned reversed string vector", ret_vec_str);

    reverse(vec_str);
    print("reversed original string vector", vec_str);

}

void print(string labeling, const vector<int> &v) {
    cout << labeling << ": ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void print(string labeling, const vector<string> &v) {
    cout << labeling << ": ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

// swapping two integers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// swapping two strings
void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// return a reversed order of the original vector
vector<int> ret_reverse(const vector<int> &origin) {
    vector<int> reverse(origin.size());
    for(int i = 0; i < origin.size(); i++) {
        reverse[origin.size() - i - 1] = origin[i];
    }
    return reverse;
}

// reverse the origin vector without using any other vectors
void reverse(vector<int> &vec) {
    for(int i = 0; i < vec.size()/2; i++) {
        swap(vec[i], vec[vec.size() - i - 1]);
    }
}

vector<string> ret_reverse(const vector<string> &origin) {
    vector<string> reverse(origin.size());
    for(int i = 0; i < origin.size(); i++) {
        reverse[origin.size() - i - 1] = origin[i];
    }
    return reverse;
}

void reverse(vector<string> &vec) {
    for(int i = 0; i < vec.size()/2; i++) {
        swap(vec[i], vec[vec.size() - i - 1]);
    }
}