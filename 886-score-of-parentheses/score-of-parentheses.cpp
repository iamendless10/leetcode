class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;

        for (char ch : s) {
            if (ch == '(') {
                st.push(score); // Push the current score onto the stack
                score = 0; 
            } else {
                // Encountered a closing parenthesis )
                score = st.top() + max(2 * score, 1); 
                st.pop(); //last (
            }
        }

        return score;
    }
};
