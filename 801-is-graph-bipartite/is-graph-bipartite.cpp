#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        
        for (int i = 0; i < n; i++) { 
            if (vis[i] == -1) { 
                queue<int> q;
                q.push(i);
                vis[i] = 0;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto adjnode : graph[node]) {
                        if (vis[adjnode] == -1) { 
                            vis[adjnode] = 1 - vis[node];
                            q.push(adjnode);
                        } 
                        else if (vis[adjnode] == vis[node]) {
                            return false; 
                        }
                    }
                }
            }
        }
        return true;
    }
};
