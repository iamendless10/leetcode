#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;
        int temp1, temp2;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                temp1 = st.top(); 
                st.pop();
                temp2 = st.top();
                st.pop();
                
                if (tokens[i] == "+") st.push(temp2 + temp1);
                else if (tokens[i] == "-") st.push(temp2 - temp1);
                else if (tokens[i] == "*") st.push(temp2 * temp1);
                else if (tokens[i] == "/") st.push(temp2 / temp1);
            }   
            else st.push(std::stoi(tokens[i]));
        }
        return st.top(); 
    }
};
