class Solution {
private:
    int cc(int i, int j, int m, int n, int &count, vector<vector<int>> &dp){
        if(i == m - 1 && j == n - 1){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int path = 0;

        if (i + 1 < m){
            path += cc(i + 1, j , m , n, count, dp);
        }

        if(j + 1 < n){
            path += cc(i, j + 1, m, n, count, dp);
        }

        dp[i][j] = path;
        return dp[i][j];


    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n , -1));
        int count = 0;
        return cc(0,0,m,n,count, dp);
        
    }
};