class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> nge(n, -1); 


        for (int i = 0; i < 2 * n; i++) {  //circular 
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                nge[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) {
                st.push(i);  // index onto the stack
            }
        }

        return nge;
    }
};
