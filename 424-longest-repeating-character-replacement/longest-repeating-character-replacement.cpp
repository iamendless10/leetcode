class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 , r = 0;
        int maxi = 0;
        int max_b = 0, n = s.size();
        vector<int> count(26, 0);
        int maxFreq = 0;

        while(r < n){
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);
           
            while((r - l + 1) - maxFreq > k){
                count[s[l] - 'A']--;
                l++;
            }
            maxi = max(maxi , r - l + 1);
            r++;
        }
        return maxi;
    }
};