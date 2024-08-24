class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int totxor = 0;
        for(int i=1;i<=encoded.size()+1;i++) totxor ^= i;
        int oddxor = 0;
        for(int i =1 ;i<encoded.size();i+=2) oddxor ^= encoded[i];
        int first = totxor ^ oddxor;
        vector<int> ans;
        ans.push_back(first);
        for(int i = 0 ; i<encoded.size();i++) ans.push_back(ans[i] ^ encoded[i]);
        return ans;
    }
};