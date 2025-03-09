class Solution {
private:
    int cc(int ind, vector<int> &coins, int target, vector<vector<int>> &dp){
        if(target == 0) return 1; 
        if(ind == 0) return (target % coins[0] == 0); 
        
        if(dp[ind][target] != -1) return dp[ind][target];

        int notpick = cc(ind - 1, coins, target, dp);
        int pick = 0;

        if(coins[ind] <= target){
            pick = cc(ind, coins, target - coins[ind], dp); 
        }

        return dp[ind][target] = pick + notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return cc(n - 1, coins, amount, dp);
    }
};
