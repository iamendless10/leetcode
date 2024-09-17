class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return function(nums , goal) - function(nums , goal - 1);
        
    }

    int function(vector<int> &nums, int goal){

        if (goal < 0) return 0;
        else{
            int l = 0 , r= 0 , sumi = 0 , ans = 0;
            int n = nums.size();

            while(r < n){
                sumi += nums[r];
                
                while(sumi > goal){
                    sumi -= nums[l];
                    l++;
                }
                ans += (r - l + 1);
                r++;
            }

            return ans;
            }
    }
};