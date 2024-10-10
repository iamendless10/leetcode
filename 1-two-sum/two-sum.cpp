class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numIndex; 

      
        for (int i = 0; i < n; i++) {
            numIndex.push_back({nums[i], i});
        }

        sort(numIndex.begin(), numIndex.end());

       
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = numIndex[l].first + numIndex[r].first;

            if (sum == target) {

                return {numIndex[l].second, numIndex[r].second};
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;  
            }
        }

        return {};  
    }
};
