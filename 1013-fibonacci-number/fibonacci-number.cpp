class Solution {
public:
    vector<int> dp;
    
    int fib(int n) {
        if (dp.empty()) dp.resize(n + 1, -1);

        if (n <= 1) return n;

        if (dp[n] != -1) return dp[n];

        dp[n] = fib(n - 1) + fib(n - 2);

        return dp[n];
    }
};
