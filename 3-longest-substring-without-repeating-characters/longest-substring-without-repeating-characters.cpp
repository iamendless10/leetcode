class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp (256, -1);
        int l = 0 , r = 0;
        int maxi = 0, n = s.size();

        while(r < n){
            if(mpp[s[r]] != -1){
                l = max(mpp[s[r]] + 1, l);
            }
            mpp[s[r]] = r;
            maxi = max(maxi , r - l + 1);
            r++;
        }
        return maxi;
    }
};