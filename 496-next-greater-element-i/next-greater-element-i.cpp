#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> res;  
        vector<int> ans;
        
 
        for(int num : nums2) {
            while(!st.empty() && st.top() < num) {
                res[st.top()] = num;  
                st.pop();
            }
            st.push(num);  
        }
        
  
        while(!st.empty()) {
            res[st.top()] = -1;
            st.pop();
        }
        
  
        for(int num : nums1) {
            ans.push_back(res[num]);
        }
        
        return ans;
    }
};
