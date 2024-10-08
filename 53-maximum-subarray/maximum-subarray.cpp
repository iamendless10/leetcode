class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 1){
            return nums[0];
        }


        int maxsum = 0;
        int sumi = 0;


        for(int ele: nums){
            sumi += ele;

            if(sumi < 0) sumi = 0;

            maxsum = max(maxsum, sumi);
        }
        if (maxsum == 0) {  // All element are negative
            return *max_element(nums.begin(), nums.end());
        } else {
            return maxsum;
        }
    }
};