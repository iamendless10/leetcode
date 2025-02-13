#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    void backtrack(int index, string &digits, map<int, string> &mpp, string &curr, vector<string> &ans) {
        if (index == digits.size()) {  
            ans.push_back(curr);
            return;
        }
        
        int digit = digits[index] - '0'; 
        string letters = mpp[digit]; 
        
        for (char letter : letters) {  
            curr.push_back(letter);
            backtrack(index + 1, digits, mpp, curr, ans); 
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        map<int, string> mpp = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };

        vector<string> ans;
        string curr;
        backtrack(0, digits, mpp, curr, ans);
        return ans;
    }
};