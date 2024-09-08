using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> left (n , -1);
        vector<int> right(n , n);
        stack<int> st;

        // for the NSE
        for(int i =0; i< n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if (!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();

        // for PSE
        for(int i = n - 1; i>=0 ; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }

        ll sum = 0;

        for(int i =0; i < n; i++){
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }
        return sum;
        
    }
};