class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        char curr;


        for(int i = 0; i < s.size(); i++){
            curr = s[i];
            if(st.empty() || st.top().first != curr) st.push({curr , 1});

            else{
                if(!st.empty() && st.top().first == curr){
                    st.top().second++;
                    if(st.top().second == k){
                        st.pop();
                    }
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};