class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        deque<pair<long long, int>> dq;
        long long shortest = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            
            if (sum >= k) {
                shortest = min(shortest, static_cast<long long>(i + 1));
            }

            // Monotonic deque 
            while (!dq.empty() && sum <= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({sum, i});



            //removing elements from the front satisfies the condition
            pair<long long, int> curr = {LLONG_MIN, -1};
            while (!dq.empty() && sum - dq.front().first >= k) {
                curr = dq.front();
                dq.pop_front();
            }

           
            if (curr.second != -1) {
                shortest = min(shortest, static_cast<long long>(i - curr.second));
            }
        }

        return shortest != INT_MAX ? static_cast<int>(shortest) : -1;
    }
};
