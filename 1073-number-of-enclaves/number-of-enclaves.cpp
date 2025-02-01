class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int drow[], int dcol[], int n, int m){
        vis[row][col] = 1;

        for(int i = 0 ; i < 4 ; i++){
            int newr = row + drow[i];
            int newc = col + dcol[i];

            if(newr >= 0 && newc >= 0 && newr < n && newc < m && !vis[newr][newc] && grid[newr][newc] == 1){
                dfs(newr, newc ,grid, vis, drow, dcol, n, m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m , 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis, drow, dcol, n, m);
            }
            if (!vis[n - 1][j] && grid[n - 1][j] == 1) {
                dfs(n - 1, j, grid, vis, drow, dcol, n, m);
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, grid, vis, drow, dcol, n, m);
            }

            if(!vis[i][m - 1] && grid[i][m - 1] == 1){
                dfs(i, m-1, grid, vis, drow, dcol, n, m);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;

    }
};