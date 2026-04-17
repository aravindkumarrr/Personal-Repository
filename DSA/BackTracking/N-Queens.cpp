#include <iostream>
#include <vector>
using namespace std; 

int n;
vector<vector<int>>sols;
// If the position is safe, place the queen.
// But if rest of the queens can't be placed anywhere, remove from original and place queen in next position.
bool safe(vector<int>&board, int row, int col){
    for(int i=0;i<row;i++){
        // We're looking at specific chair (col) in current row
        if(board[i]==col || abs(board[i]-col) == abs(i-row)){
            // board[i]==col: Before any queen is placed, scan if someone is already sitting in that column.
            // abs(board[i]-col) == abs(i-row): Look diagonally.
            return false;
        }
    }
    return true;
}

void solve(vector<int>& board, int row){
    if(row==n){
        sols.push_back(board);
        // We made it to row 8 and seated all the queens safely. We consider this as one solution and add it to list of solutions.
        return;
    }
    for(int col = 0; col<n; col++){ // For current queen, start at position 0 (col=0) and checking every row
        if(safe(board,row,col)){ // Checks column conditions, diagonal condition.
            board[row] = col; 
            solve(board,row+1); // Immediately move on to next queen's placement.
            board[row] = -1; // We get to this part only if none of the positions worked.
        }
    }
}
