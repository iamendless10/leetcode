class Solution {
private:
    int cc(int i, int j, vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp){
        if(i == m - 1 && j == n - 1){
            return 1;
        }

        if (i >= m || j >= n || grid[i][j] == 1) return 0;

        int path = 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(i + 1 <m && grid[i + 1][j] != 1){
            path += cc(i + 1, j, grid, m, n, dp);
        }

        if(j + 1 < n && grid[i][j + 1] != 1){
            path += cc(i , j + 1, grid, m, n,dp);
        }

        dp[i][j] = path;
        return dp[i][j];


    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return cc(0,0,grid,m,n,dp);
    }
};