class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return function(nums, k) - function(nums, k - 1);
    }

private:
    int function(const vector<int>& nums, int k) {
        int l = 0, r = 0, max_odd = 0, n = nums.size();
        int ans = 0;

        while (r < n) {
            if (isodd(nums[r])) {
                max_odd++;
            }

            while (max_odd > k) {
                if (isodd(nums[l])) {
                    max_odd--;
                }
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }

    bool isodd(int n) {
        if (n & 1)
            return true;
        else
            return false;
    }
};
