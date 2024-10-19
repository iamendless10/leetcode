class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        return helper(n+1, dp);
    }

    int helper(int n, vector<int> &dp) {
        if (n <= 2) {
            return n;
        }

        for(int i = 3 ; i < n ; i++){
            dp[i] = dp[i -1] + dp[i -2];
        }
        return dp[n -1];
    }
};
