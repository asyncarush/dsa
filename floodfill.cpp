#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, char newColor) {
    int n = image.size();
    int m = image[0].size();
    int ocolor = image[sr][sc];

    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    q.push({sr, sc});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        visited[row][col] = 1;
        image[row][col] = newColor;
        
        //check vertically
        //check up
        if ( row - 1 >= 0 && row - 1 < n && col >= 0 && col < m && !visited[row-1][col] && image[row-1][col] == ocolor) {
            q.push({row-1, col});
        }

        // check down
        if ( row + 1 >= 0 && row + 1 < n && col >= 0 && col < m && !visited[row+1][col] && image[row+1][col] == ocolor) {
            q.push({row+1, col});
        }

        // check horizontally
        // check left
        if ( row >= 0 && row < n && col - 1 >= 0 && col - 1 < m && !visited[row][col-1] && image[row][col-1] == ocolor) {
            q.push({row, col-1});
        }

        // check right
        if ( row >= 0 && row < n && col + 1 >= 0 && col + 1 < m && !visited[row][col+1] && image[row][col+1] == ocolor) {
            q.push({row, col+1});
        }
    }
    return image;
}


int main() {

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, color);

    for(auto it : result) {
        cout << "[";
        for(auto num : it) {
            cout << num << ", ";
        }
        cout << "],";
    }
    return 0;
}