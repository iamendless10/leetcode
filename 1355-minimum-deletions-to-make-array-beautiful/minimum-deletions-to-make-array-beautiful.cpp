class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> st;
        int moves = 0; 

        for (int i = 0; i < nums.size(); i++) {
     
            if (!st.empty() && (i - moves) % 2 == 1 && st.top() == nums[i]) {
                moves++;  
            } else {
             
                st.push(nums[i]);
            }
        }

        if ((nums.size() - moves) % 2 != 0) {
            moves++;
        }

        return moves;
    }
};
