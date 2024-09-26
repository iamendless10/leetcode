class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum = 0 , rsum = 0;
        int maxsum  = 0;
        int n = nums.size();
        for(int i = 0 ; i<k ; i++){
            lsum += nums[i];
        }
        maxsum = lsum;
        int rindex = n - 1;
        for(int i = 0; i < k; i++){
            lsum-= nums[k - 1 - i];
            rsum += nums[n - 1 - i];
            maxsum = max(maxsum , lsum + rsum);
        }
        return maxsum;
    }
};