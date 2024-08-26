class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0,res = 0;
        for(int i =0 ; i< nums.size();i++){
            if (count == 0) res = nums[i];
            if (nums[i]==res) count += 1;
            else count += -1;
        }
        return res;
        
    }
};