class Solution {
private:
    int cc(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n) {
        if (i >= m || j >= n) return INT_MAX;
        if (i == m - 1 && j == n - 1) return grid[i][j]; 

        if (dp[i][j] != -1) return dp[i][j]; 
        return dp[i][j] = grid[i][j] + min(cc(i + 1, j, grid, dp, m, n), cc(i, j + 1, grid, dp, m, n));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return cc(0, 0, grid, dp, m, n);
    }
};