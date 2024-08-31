#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string current;
        backtrack(res, current, 0, 0, n);
        return res;
    }
    
private:
    void backtrack(std::vector<std::string>& res, std::string& current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            res.push_back(current);
            return;
        }
        if (open < n) {
            current.push_back('(');
            backtrack(res, current, open + 1, close, n);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(res, current, open, close + 1, n);
            current.pop_back();
        }
    }
};
