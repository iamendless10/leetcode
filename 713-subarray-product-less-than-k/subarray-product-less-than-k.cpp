class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k==0) return 0;

        int l = 0 , r = 0 , sum = 1 , ans = 0;

        while( r < nums.size()){
            sum *= (nums[r]);

            while(sum >= k){
                sum /= nums[l];
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return (sum > 0) ? ans : 0;
    }
};