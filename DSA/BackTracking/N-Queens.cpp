#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int n;
vector<vector<int>> sols;

bool safe(vector<int>& board, int row, int col) {
    for(int i = 0; i < row; i++) {
        if(board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(vector<int>& board, int row) {
    if(row == n) {
        sols.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if(safe(board, row, col)) {
            board[row] = col;
            solve(board, row + 1);
            board[row] = -1;
        }
    }
}

int main() {
    n = 8;
    vector<int> board(n, -1);
    solve(board, 0);
    cout << sols.size() << "\n";
    return 0;
}
