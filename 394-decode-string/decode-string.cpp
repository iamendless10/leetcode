class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string out = "";
        for(int i=0 ; i< s.size(); i++){
            string ans = "";
            if (s[i] != ']'){
                st.push(s[i]);
            }
            else{
                while(st.top() != '['){
                    ans = st.top() + ans;
                    st.pop();
                }
                st.pop();




                ///Extractingg the number if its a 2 digit number like 12[a]
                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                int repeatTimes = stoi(numStr);


                string repeated = "";
                for (int j = 0; j < repeatTimes; j++) {
                    repeated += ans;
                }

                // Push the repeated string back to the stack
                for (char c : repeated) {
                    st.push(c);
                }
            }
        }
        while (!st.empty()) {
            out = st.top() + out;
            st.pop();
        }
        return out;

    }
};