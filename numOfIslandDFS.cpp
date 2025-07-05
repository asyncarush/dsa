#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited){
    visited[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    // let do the traversal
    for(int delrow = -1; delrow <= 1; delrow++) {
        for(int delcol = -1; delcol <= 1; delcol++) {
            int nrow = row + delrow;
            int ncol = col + delcol;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, grid, visited);
            }
        }
    }
}

int numberOfIsland(vector<vector<char>> & grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && grid[i][j] == '1') {
                count++;
                dfs(i, j, grid, visited);
            }
        }
    }
    return count;
}

int main() {

    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    }; // Expected output: 1


    cout << numberOfIsland(grid1);

    return 0;
}