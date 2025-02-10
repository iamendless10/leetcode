#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1; 

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 1;
        pq.push({1, {0, 0}});

        int drow[] = {-1, -1, -1,  0, 0, 1, 1,  1};
        int dcol[] = {-1,  0,  1, -1, 1, -1, 0,  1};

        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            int distance = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;

            if (row == n - 1 && col == m - 1) return distance;

            for (int i = 0; i < 8; i++) { 
                int newr = row + drow[i];
                int newc = col + dcol[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0) {
                    if (distance + 1 < dist[newr][newc]) {
                        dist[newr][newc] = distance + 1;
                        pq.push({dist[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
};
