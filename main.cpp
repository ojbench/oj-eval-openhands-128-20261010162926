#include <bits/stdc++.h>
// Solution for tic-tac-toe validation
using namespace std; // standard namespace

bool checkWin(const vector<string>& b, char c) {
    // rows
    for (int i = 0; i < 3; ++i) {
        if (b[i][0] == c && b[i][1] == c && b[i][2] == c) return true;
    }
    // cols
    for (int j = 0; j < 3; ++j) {
        if (b[0][j] == c && b[1][j] == c && b[2][j] == c) return true;
    }
    // diagonals
    if (b[0][0] == c && b[1][1] == c && b[2][2] == c) return true;
    if (b[0][2] == c && b[1][1] == c && b[2][0] == c) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(3);
    for (int i = 0; i < 3; ++i) {
        if (!(cin >> board[i])) return 0;
        if (board[i].size() != 3) return 0;
    }
    int cntX = 0, cntO = 0;
    for (auto &row : board) {
        for (char ch : row) {
            if (ch == 'x') ++cntX;
            else if (ch == 'o') ++cntO;
        }
    }
    bool winX = checkWin(board, 'x');
    bool winO = checkWin(board, 'o');
    bool valid = true;
    if (!(cntX == cntO || cntX == cntO + 1)) valid = false;
    if (winX && winO) valid = false;
    if (winX && cntX != cntO + 1) valid = false;
    if (winO && cntX != cntO) valid = false;
    if (!valid) {
        cout << "invalid\n";
        return 0;
    }
    if (winX) cout << "win\n";
    else if (winO) cout << "lose\n";
    else if (cntX + cntO == 9) cout << "tie\n";
    else cout << "ongoing\n";
    return 0;
// End of solution
}
