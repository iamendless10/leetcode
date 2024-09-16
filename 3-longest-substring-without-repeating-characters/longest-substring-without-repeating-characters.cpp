class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0;
        vector<int> mpp(256, -1);
        int n = s.size();
        int len = 0;


        while(r < n){
            if(mpp[s[r]] != -1){ // its already been marked
                l = max(mpp[s[r]] + 1, l);
            } 
            mpp[s[r]] = r;
            len = max(len , r - l + 1);
            r++;
        }
        return len;

    }
};