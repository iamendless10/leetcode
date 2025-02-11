class Solution {
private:
    void cc(int ind, vector<vector<int>> &res, vector<int> &curr, vector<int> &nums) {
        res.push_back(curr); 

        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) continue;
            
            curr.push_back(nums[i]);
            cc(i + 1, res, curr, nums);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        cc(0, res, curr, nums);
        return res;
    }
};
