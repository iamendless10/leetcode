class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int ele: nums){
            mpp[ele]++;
        }
        vector<int> ans;
        for(auto ele: mpp){
            if (ele.second > n/3){
                ans.push_back(ele.first);
            }
        }
        return ans;
        
    }
};