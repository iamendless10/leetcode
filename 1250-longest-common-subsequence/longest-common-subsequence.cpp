class Solution {
private:
    int cc(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){

        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];


        if(text1[i - 1] == text2[j - 1]) 
            return dp[i][j] = 1 + cc(text1, text2, i - 1, j - 1, dp);

        return dp[i][j] = max(cc(text1, text2, i - 1, j, dp), cc(text1, text2, i, j - 1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return cc(text1,text2,n,m , dp);
        
    }
};