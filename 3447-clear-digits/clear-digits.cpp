#include <string>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string res = "";
    
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                if (!res.empty()) {
                    res.pop_back(); 
                }
            } else {
            
                res += s[i];
            }
        }
        return res;
    }
};
