class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(auto& c: operations){
            if(c == "C"){
                st.pop();
            }
            else if (c == "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                int res = top1 + top2;
                st.push(top1);
                st.push(res); 
            }
            else if(c == "D"){
                st.push(2 * st.top());
            }
            else{
                st.push(stoi(c));
            }
        }
        
        int ans = 0;
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }

        return ans;
    }
};