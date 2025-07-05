#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int rowIndex, int colIndex, vector<string> ds, string row){
    return true;
}


void solve(int rowIndex, int colIndex, vector<string> &ds, string row) {
    row[colIndex] = 'Q';
    ds.push_back(row);
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> ds;
    string row(n, '.');

    for(int i=0; i<n; i++) {
        solve(i, 0, ds, row);
    }
}

int main() {

    int n = 4;

    auto result = solveNQueens(n);
    return 0;
}