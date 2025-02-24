#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    int cc(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp) {
        if (i == m - 1) return grid[i][j]; 

        if (dp[i][j] != 1e9) return dp[i][j];


        int minPath = INT_MAX;
        for (int col = 0; col < n; col++) {
            if (col != j) { 
                minPath = min(minPath, cc(i + 1, col, grid, m, n, dp));
            }
        }

        return dp[i][j] = grid[i][j] + minPath;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9)); 

        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, cc(0, j, grid, m, n, dp));
        }

        return mini;
    }
};
