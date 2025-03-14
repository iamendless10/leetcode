class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        int n = s.size();
        int m = t.size();
        reverse(t.begin(),t.end());

        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for(int i = 1; i <= n ; i++){
            for(int j = 1 ; j<= m ; j++){
                if(s[i - 1]==t[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } 
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return s.size() - dp[n][m];
    }
};