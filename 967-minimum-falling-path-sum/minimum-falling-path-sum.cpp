class Solution {
private:
    int cc(int i, int j, vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp){
        if (j < 0 || j >= n) return 1e9;

        if(i == m - 1){
            return matrix[i][j];
        }

        if(dp[i][j] != 1e9) return dp[i][j];

        return dp[i][j] = matrix[i][j] + min({cc(i + 1, j - 1, matrix, m, n, dp),cc(i + 1, j, matrix, m, n,dp),cc(i + 1, j + 1, matrix, m, n, dp)});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(m, vector<int> (n, 1e9));
        for(int j = 0; j < n ; j++){
            mini = min(mini, cc(0, j, matrix, m, n, dp));
        }

        return mini;
    }
};