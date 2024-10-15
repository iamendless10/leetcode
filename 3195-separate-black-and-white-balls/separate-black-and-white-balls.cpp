class Solution {
    #define ll long long 
public:
    long long minimumSteps(string s) {
        int n = s.size(); 
        ll count = 0; 
        int l = 0;

        while(l < n && s[l] != '1')
            l++;

        for(int r = l + 1; r < n; r++){
            if(s[r] == '0'){ 
                count += r - l;
                l++;
            }
        }

        return count;
    }
};