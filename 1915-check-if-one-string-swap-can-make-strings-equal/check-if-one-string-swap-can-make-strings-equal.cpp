class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        int n = s1.size();
        unordered_map<char,int> mp1,mp2;
        for(int i =0 ; i<n ;i++){
            diff += (s1[i]!=s2[i]);
            mp1[s1[i]]++; mp2[s2[i]]++;
        }
        return diff <= 2 && mp1 == mp2;
    }
};