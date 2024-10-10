class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int> l;
        vector<int> r;

        int maxl = 0;
        for(int ele: nums){
            maxl = max(maxl ,  ele);
            l.push_back(maxl);
        }
        


        int maxr = 0;
        int n  = nums.size(); 
        for(int i = n - 1 ; i >= 0 ; i--){
            maxr = max(nums[i] , maxr);
            r.push_back(maxr);
        }
        reverse(r.begin(),r.end());

        int sum = 0,pot = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            pot = min(l[i], r[i]);
            ans = pot - nums[i];
            if(ans > 0)sum += ans;
        }


        return sum;
    }
    
};