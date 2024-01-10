Problem link: https://open.kattis.com/problems/basketballoneonone

Solution:

#include <iostream>
#include <string>

using namespace std;

char determineWinner(const string& record) {
    int score_A = 0;
    int score_B = 0;
    bool lead_by_2 = false;

    for (int i = 0; i < record.length(); i += 2) {
        char player = record[i];
        int points = record[i + 1] - '0';

        if (player == 'A') {
            score_A += points;
        } else if (player == 'B') {
            score_B += points;
        }

        if (score_A >= 11 || score_B >= 11) {
            if (abs(score_A - score_B) >= 2) {
                lead_by_2 = true;
                break;
            }
        }
    }

    if (score_A > score_B) {
        return 'A';
    } else if (score_B > score_A) {
        return 'B';
    }

    if (lead_by_2) {
        return (score_A > score_B) ? 'A' : 'B';
    } else {
        return determineWinner(record.substr(0, record.length() - 2));
    }
}

int main() {
    
    string s; cin>>s;
    cout << determineWinner(s) << endl;

    return 0;
}
