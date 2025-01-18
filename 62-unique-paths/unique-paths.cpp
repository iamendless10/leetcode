class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return cc(m, n, 0, 0, dp);
    }

private:
    int cc(int m, int n, int i, int j, vector<vector<int>> &dp) {
      
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int paths = 0;

       
        if (i + 1 < m) {
            paths += cc(m, n, i + 1, j, dp);
        }

        if (j + 1 < n) {
            paths += cc(m, n, i, j + 1, dp);
        }


        dp[i][j] = paths;
        return dp[i][j];
    }
};
