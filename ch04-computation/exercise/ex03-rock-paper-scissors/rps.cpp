#include "../../../std_lib_facilities.h"

// function declaration
string rock_paper_scissors(int);
string player_win(int, int);

int main() {
    // 0 - rock, 1 - paper, 2 - scissors
    int seq_count = 0;
    vector<int> computer_sequence = {0, 1, 2};
    
    cout << "0 for rock, 1 for paper, 2 for scissors\n";
    cout << "Rock, Paper, Scissors!\n";

    for(int user_in; cin >> user_in;) {
        cout << "The computer plays " << rock_paper_scissors(computer_sequence[seq_count]) << "\n";
        cout << player_win(computer_sequence[seq_count], user_in) << "\n";

        // update sequence count, reset if index exceeds vector size
        seq_count++;
        if(seq_count >= computer_sequence.size()) {
            seq_count = 0;
        }

        cout << "\nRock, Paper, Scissors!\n";
    }
}

string rock_paper_scissors(int choice) {
    switch(choice) {
        case 0:
            return "rock";
        case 1:
            return "paper";
        case 2:
            return "scissors";
    }
    return "";
}

string player_win(int computer, int player) {
    if(player == computer) {
        return "Draw!";
    }

    switch(player) {
        case 0:
            switch(computer) {
                case 1:
                    return "You lose...";
                case 2:
                    return "You win!";
            }
        case 1:
            switch(computer) {
                case 0:
                    return "You win!";
                case 2:
                    return "You lose...";
            }
        case 2:
            switch(computer) {
                case 0:
                    return "You lose...";
                case 1:
                    return "You win!";
            }
    }
    return "";
}