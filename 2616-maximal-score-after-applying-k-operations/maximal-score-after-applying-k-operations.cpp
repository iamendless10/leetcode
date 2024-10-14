#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        
        long long sum = 0;
        
        for(int i = 0; i < k; i++) {
            sum += nums.front();
            
            pop_heap(nums.begin(), nums.end());

            int maxElement = nums.back();
       
            nums.back() = ceil(maxElement / 3.0);
 
            push_heap(nums.begin(), nums.end());
        }

        return sum;
    }
};
