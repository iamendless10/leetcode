class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while(low <= high) {
            mid = low + (high - low) / 2;
            
            if (nums[mid] == target) return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // If the target is in the sorted left half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Otherwise, the right half must be sorted
            else {
                // If the target is in the sorted right half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
