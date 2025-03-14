class Solution {
private:
    int cc(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = 1 + cc(i - 1, j - 1, s, t, dp);

        return dp[i][j] = max(cc(i - 1, j, s, t, dp), cc(i, j - 1, s, t, dp)); 
    }
public:
    int minInsertions(string s) {
        string t = s;
        int n = s.size();
        int m = t.size();
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n, vector<int>(m, -1));
        cc(n - 1, m - 1, s, t, dp);
        return n - dp[n - 1][m - 1];
    }
};