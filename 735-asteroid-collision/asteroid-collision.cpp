class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        bool destroyed = false;
        for(int i = 0; i<n ; i++){
            bool destroyed = false;
            while(!st.empty() && nums[i]<0 && st.top()>0){
                if(!st.empty() &&  abs(nums[i]) > st.top()){
                    // -ve is larger
                    st.pop();
                }
                else if(abs(nums[i]) < st.top()){
                    // +ve is larger
                    destroyed = true;
                    break;
                }
                else{
                    // both equal
                    st.pop();
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                st.push(nums[i]);
            }
        }
        vector<int> res(st.size());
        for(int i =st.size() - 1 ; i>= 0;i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
        
    }
};