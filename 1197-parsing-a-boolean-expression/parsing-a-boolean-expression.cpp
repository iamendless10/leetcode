class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        
        for (char ch : expression) {
            if (ch == ',' || ch == '(') {
                continue;
            } 


            else if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|') {
                s.push(ch);
            } 


            else if (ch == ')') {
                bool hasTrue = false, hasFalse = false;
                while (s.top() != '!' && s.top() != '&' && s.top() != '|') {
                    char top = s.top();
                    s.pop();
                    if (top == 't') hasTrue = true;
                    if (top == 'f') hasFalse = true;
                }
                
                char op = s.top(); 
                s.pop();           
                

                if (op == '!') s.push(hasTrue ? 'f' : 't');
                
                else if (op == '&') s.push(hasFalse ? 'f' : 't');
                
                else if (op == '|') s.push(hasTrue ? 't' : 'f');
                
            }
        }
        return s.top() == 't';
    }
};