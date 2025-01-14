class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int> arr;
        cc(nums, 0, result, arr);  
        return result;  
    }

private:
    void cc(vector<int>& nums, int i, vector<vector<int>>& result, vector<int>& arr) {
        if (i == nums.size()) {
            result.push_back(arr);  
            return;
        }

        arr.push_back(nums[i]);
        cc(nums, i + 1, result, arr);

        arr.pop_back();
        cc(nums, i + 1, result, arr);
    }
};
