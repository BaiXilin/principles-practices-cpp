#include "../../../std_lib_facilities.h"

vector<int> init_answer(int);
bool all_different(int, int, int, int);
int find_bulls(vector<int>, int, int, int, int);
int find_cows(vector<int>, int, int, int, int);

int main() {
    //vector<int> answers = {1, 2, 3, 4};
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    vector<int> answers = init_answer(n);
    cout << "DEBUG: answer is " << answers[3] << answers[2] << answers[1] << answers[0] << "\n";

    for(int guess; cin >> guess;) {
        if(!cin || guess < 1000 || guess > 9999) {
            cerr << "Invalid input: Must be an integer from 1000 to 9999\n";
            continue;
        }
        
        int temp = guess;
        int digit_3 = temp / 1000;
        temp = temp % 1000;
        int digit_2 = temp / 100;
        temp = temp % 100;
        int digit_1 = temp / 10;
        temp = temp % 10;
        int digit_0 = temp;

        bool unique = all_different(digit_3, digit_2, digit_1, digit_0);
        if(!unique) {
            cerr << "Invalid input: 4 digits must be different\n";
            continue;
        }

        int bulls = find_bulls(answers, digit_0, digit_1, digit_2, digit_3);
        int cows = find_cows(answers, digit_0, digit_1, digit_2, digit_3);

        if(bulls == 4) {
            cout << "Correct Guess!\n";
            break;
        } else {
            cout << bulls << " bulls and " << cows << " cows\n";
        }
    }
    return 0;
}

vector<int> init_answer(int n) {
    srand(n);
    vector<int> init_ans(4, 0);

    while(!all_different(init_ans[0], init_ans[1], init_ans[2], init_ans[3])) {
        init_ans[0] = randint(10);
        init_ans[1] = randint(10);
        init_ans[2] = randint(10);
        init_ans[3] = randint(10);
    }
    // guarantee the initialized result has 4 digits all different
    return init_ans;
}

bool all_different(int a, int b, int c, int d) {
    if(a == b || a == c || a == d || b == c || b == d || c == d)
        return false;
    return true;
}

// A bull is a match with both correct value and correct location
int find_bulls(vector<int>answers, int guess_0, int guess_1, int guess_2, int guess_3) {
    int bulls = 0;
    if(answers[0] == guess_0) bulls++;
    if(answers[1] == guess_1) bulls++;
    if(answers[2] == guess_2) bulls++;
    if(answers[3] == guess_3) bulls++;
    return bulls;
}

// A cow is a match with correct value but different location
int find_cows(vector<int> answers, int guess_0, int guess_1, int guess_2, int guess_3) {
    int cows = 0;

    for(int i = 0; i < answers.size(); i++) {
        if(i == 0) continue;    // ignore bull
        if(answers[i] == guess_0) cows++;
    }

    for(int i = 0; i < answers.size(); i++) {
        if(i == 1) continue;
        if(answers[i] == guess_1) cows++;
    }

    for(int i = 0; i < answers.size(); i++) {
        if(i == 2) continue;
        if(answers[i] == guess_2) cows++;
    }

    for(int i = 0; i < answers.size(); i++) {
        if(i == 3) continue;
        if(answers[i] == guess_3) cows++;
    }
    return cows;
}