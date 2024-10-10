class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int maxWidth = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);  
            }
        }

     
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                maxWidth = max(maxWidth, i - st.top());  // width calc
                st.pop();  //  index 
            }
        }

        return maxWidth;   
    }
};
