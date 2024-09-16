#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;  // indices of (
        int maxLength = 0;
        vector<int> ans(s.size(), 0);  

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);  //index of (
            } else {
                if (!st.empty()) {
                    int openIndex = st.top();  // Get the index of matching '('
                    st.pop();
                    ans[i] = i - openIndex + 1;  // Calc length
                    if (openIndex > 0) {
                    ans[i] += ans[openIndex - 1];  // Add prev length
                    }
                    maxLength = max(maxLength, ans[i]);  // Upd max len
                }
            }
        }

        return maxLength;
    }
};
