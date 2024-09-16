class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ans(n,0);
        int curr = ans[0];
        

        for(int i = n - 1; i >= 0; i--){
            int visible = 0;
            curr = heights[i];


            while(!st.empty() && curr > st.top()){
                visible++;
                st.pop(); //Monotonic increasing stack make it increasing...
            }

            if(!st.empty()){
                visible++;
            }
            ans[i] = visible;
            st.push(curr);
        }
        return ans;
    }
};