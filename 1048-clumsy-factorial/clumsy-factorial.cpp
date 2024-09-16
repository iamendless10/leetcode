class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        int index = 0;

        st.push(n--);

        for(int i = n ; i>0 ; i--){
            if (index % 4 == 0) st.top() *= i;
            else if (index % 4 == 1) st.top() /= i;
            else if (index % 4 == 2) st.push(i);
            else st.push(-i);
            
            index++;
        }

        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};