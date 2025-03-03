class Solution {
private:
    int cc(int i, int j, int m, int n, vector<vector<int>> &dungeon, vector<vector<int>> &dp){
        if(i == m - 1 && j == n - 1) return max(1, 1 - dungeon[i][j]);

        if(dp[i][j] != -1)return dp[i][j];

        int down = INT_MAX, right = INT_MAX , minhealth;

        if(i + 1 < m){
            down = cc(i + 1 , j , m , n, dungeon, dp);
        }

        if(j + 1 < n){
            right = cc(i, j + 1, m, n, dungeon, dp);
        }

        minhealth = min(down,right) - dungeon[i][j];
        dp[i][j] = max(1, minhealth);
        return dp[i][j];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int> (n , -1));
        return cc(0,0,m,n,dungeon,dp);

    }
};