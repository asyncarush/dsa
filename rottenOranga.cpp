#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Queue to store positions of rotten oranges
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        // Step 1: Count fresh oranges and add all rotten oranges to queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});  // Add rotten orange position
                } else if (grid[i][j] == 1) {
                    freshCount++;    // Count fresh oranges
                }
            }
        }
        
        // If no fresh oranges, return 0 (already all rotten or empty)
        if (freshCount == 0) return 0;
        
        // Directions for 4-directional movement (up, down, left, right)
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = 0;
        
        // Step 2: BFS - Process level by level (minute by minute)
        while (!q.empty()) {
            int size = q.size();  // Current level size
            bool rottenThisMinute = false;
            
            // Process all oranges that rot in current minute
            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                
                // Check all 4 neighbors
                for (int d = 0; d < 4; d++) {
                    int newRow = row + directions[d][0];
                    int newCol = col + directions[d][1];
                    
                    // Check bounds and if neighbor is fresh
                    if (newRow >= 0 && newRow < m && 
                        newCol >= 0 && newCol < n && 
                        grid[newRow][newCol] == 1) {
                        
                        // Make fresh orange rotten
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        freshCount--;
                        rottenThisMinute = true;
                    }
                }
            }
            
            // Only increment time if we actually rotted oranges this minute
            if (rottenThisMinute) {
                minutes++;
            }
        }
        
        // Step 3: Check if all fresh oranges became rotten
        return freshCount == 0 ? minutes : -1;
    }
};

// Example usage and test cases
#include <iostream>
int main() {
    Solution solution;
    // Test case 1: [[2,1,1],[1,1,0],[0,1,1]]
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Test 1 Result: " << solution.orangesRotting(grid1) << endl; // Expected: 4
    // Test case 2: [[2,1,1],[0,1,1],[1,0,1]]
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << "Test 2 Result: " << solution.orangesRotting(grid2) << endl; // Expected: -1
    
    // Test case 3: [[0,2]]
    vector<vector<int>> grid3 = {{0,2}};
    cout << "Test 3 Result: " << solution.orangesRotting(grid3) << endl; // Expected: 0
    
    return 0;
}