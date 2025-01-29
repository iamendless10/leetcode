class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0,0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n - 1 && col == m- 1) return diff;

            pq.pop();

            for(int i = 0 ; i<4 ; i++){
                int newr = row + drow[i];
                int newc = col + dcol[i];

                if(newr < n && newc < m && newr >= 0 && newc >= 0){
                    int effort = max(diff, abs(heights[newr][newc] - heights[row][col]));

                    if(effort < dist[newr][newc]){
                        dist[newr][newc] = effort;
                        pq.push({effort, {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
};