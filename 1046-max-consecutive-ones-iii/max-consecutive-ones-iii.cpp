class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , r = 0;
        int n = nums.size();
        int max_zeros = 0;
        int maxi = 0;

        while(r<n){
            if (nums[r] == 0){
                max_zeros++;
            }
            while(max_zeros > k){
                if (nums[l] == 0){
                    max_zeros--;
                }
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
        
    }
};