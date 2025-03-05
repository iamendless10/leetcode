class Solution {
private:
    int cc(vector<int> &nums, int ind, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[ind] == target);

        if(dp[ind][target] != -1) return dp[ind][target];

        bool notpick = cc(nums, ind - 1, target, dp);
        bool pick = false;

        if(nums[ind] <= target){
            pick = cc(nums, ind - 1, target - nums[ind], dp);
        }

        return dp[ind][target] = pick || notpick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i = 0 ; i < nums.size(); i++){
            target += nums[i];
        }
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, -1));
        if (target % 2) return false;
        else return cc(nums, nums.size() - 1, target/2, dp);
        
    }
};