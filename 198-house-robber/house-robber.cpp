class Solution {
public:
    int rob(vector<int>& nums) {
        return f(nums);
    }

    int f(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int prev = 0;
        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            int temp = curr;
            curr = max(prev + nums[i], curr);
            prev = temp;
        }

        return curr;
    }
};
