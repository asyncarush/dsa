#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> &board, int rowIndex, int colIndex, int n){
    for(int i=0; i<n; i++) if(board[rowIndex][i] == 'Q') return false;
    for(int i=0; i<n; i++) if(board[i][colIndex] == 'Q') return false;
    for(int i =rowIndex, j=colIndex; i>=0 && j>=0; i--, j--) if(board[i][j] == 'Q') return false;
    for(int i =rowIndex, j=colIndex; i>=0 && j<n; i--, j++) if(board[i][j] == 'Q') return false;
    return true;
}

void solve(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
    if(row == n) {
        ans.push_back(board);
        return;
    }

    for(int i=0; i<n; i++) {
        if(isSafe(board, row, i, n)) {
            board[row][i] = 'Q';
            solve(board, row+1, n, ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n, ans);
    return ans;
}

int main() {
    int n = 4;
    auto result = solveNQueens(n);
    for(auto n: result) {
        cout << "[";
        for( auto s : n) cout << s << ", ";
        cout << "]";
    }
    return 0;
}