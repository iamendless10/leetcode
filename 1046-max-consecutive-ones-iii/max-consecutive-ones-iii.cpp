class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_zeros = 0, maxi = 0;
        int l = 0 , r = 0, n = nums.size();

        while(r < n){
            if(nums[r] == 0){
                max_zeros++;
            }
         
            while(max_zeros > k){
                if (nums[l] == 0){
                    max_zeros--;
                }
                l++;
            }
            maxi = max(maxi , r - l + 1);
            r++;
        }
        return maxi;
    }
};