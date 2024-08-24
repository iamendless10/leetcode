class Solution {
    int binsearch(vector<int> &nums,int target,bool leftbiased){
            int low = 0,high = nums.size()-1;
            int mid = 0;
            int i = -1;
            while(low<=high){
                mid =  (low + high)/2;
                if (nums[mid] > target) high = mid - 1;
                else if (nums[mid] < target) low = mid +1 ;
                else{
                    i = mid;
                    if (leftbiased) high = mid - 1;
                    else low = mid + 1;
                }
            }
            return i;
        }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = binsearch(nums,target,true);
        int right = binsearch(nums,target,false);
        return {left,right};
        
    }
};