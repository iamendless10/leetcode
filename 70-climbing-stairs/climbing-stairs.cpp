class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }

    int helper(int n, vector<int> &dp) {
        if (n <= 2) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n];
    }
};
