class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int> , int>> q;
        int vis[n][m];
        int countfresh = 0;


        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j< m;j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i , j}, 0});
                }
                else{
                    vis[i][j] = 0; 
                }
                if(grid[i][j] == 1) countfresh++;
            }
        }

        int time = 0;
        int count = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }
        }

        if(count!=countfresh)
            return -1;
        else
            return time;






    }
};