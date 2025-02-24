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


/*
class Solution {
private:
    int cc(int i, int j, vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp){
        if(i == m - 1){
            return matrix[i][j];
        }

        if(dp[i][j] != 1e9) return dp[i][j];

        int path = matrix[i][j];
        int left = INT_MAX, down = INT_MAX, right = INT_MAX;

        if(i + 1 < m && j - 1 >= 0){
            left = cc(i + 1, j - 1, matrix, m, n, dp);
        }

        if(i + 1 < m){
            down = cc(i + 1, j, matrix, m, n, dp);
        }

        if(i + 1 < m && j + 1 < n){
            right = cc(i + 1, j + 1, matrix, m, n, dp);
        }

        dp[i][j] = path + min({left, down, right});
        return dp[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 1e9));
        int minSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, cc(0, j, matrix, m, n, dp)); // for every col
        }

        return minSum;


    }
};
*/