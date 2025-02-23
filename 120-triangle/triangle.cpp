class Solution {
private:
    int cc(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == triangle.size() - 1){
            return triangle[i][j];
        }

        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(cc(i + 1, j , triangle, dp), cc(i + 1, j + 1, triangle, dp));

       
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, -1)); 
        return cc(0, 0, triangle, dp);
    }
};