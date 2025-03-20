class Solution {
private:
    int cc(int ind, int prev, vector<int> &nums, int n, vector<vector<int>> &dp){
        if(ind == n) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int len = 0 + cc(ind + 1, prev, nums, n, dp);

        if(prev == -1 || nums[ind] > nums[prev]){
            len = max(1 + cc(ind + 1, ind, nums, n, dp), len);
        }

        return dp[ind][prev + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return cc(0, -1, nums, n, dp);
    }
};