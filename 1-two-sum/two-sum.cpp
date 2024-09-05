
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndexMap;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (numToIndexMap.find(diff) != numToIndexMap.end()) {
                return {i, numToIndexMap[diff]};
            }
            numToIndexMap[nums[i]] = i;
        }
        return {};
    }
};