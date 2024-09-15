class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int k = 0;


        for(int i = 0 ; i<popped.size(); i++){
            st.push(pushed[i]);
 
            while(!st.empty() && popped[k] == st.top()){
                st.pop();
                k++;
            }
        }
        return(st.empty());
    }
};