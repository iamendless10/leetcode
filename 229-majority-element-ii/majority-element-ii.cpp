class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>dp;
        int n=nums.size();

        for(auto i=0;i<n;i++)dp[nums[i]]++;
        
        vector<int>ans;

        for(auto i:dp){
            if(i.second>n/3)ans.push_back(i.first);
        }
        return ans;
    }
};