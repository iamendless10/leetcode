class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return cc(nums,nums.size()- 1, dp);
    }

private: 
    int cc(vector<int> &val, int ind, vector<int> &dp){
        if(ind == 0 ) return val[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int take = val[ind] + cc(val, ind - 2, dp);
        int nottake = 0 + cc(val, ind - 1, dp);

        return dp[ind] = max(take,nottake);
    }
};