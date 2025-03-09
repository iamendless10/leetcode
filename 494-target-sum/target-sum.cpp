class Solution {
private:
    int cc(int ind, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if (ind == 0) { 
            return (target == nums[0]) + (target == -nums[0]); 
        }

        if (target < -1000 || target > 1000) return 0;

        if (dp[ind][target + 1000] != -1) return dp[ind][target + 1000]; // Shift index to avoid negative

        int add = cc(ind - 1, target - nums[ind], nums, dp);
        int subtract = cc(ind - 1, target + nums[ind], nums, dp);

        return dp[ind][target + 1000] = add + subtract;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1)); 
        return cc(n - 1, target, nums, dp);
    }
};
