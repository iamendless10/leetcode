class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &path, vector<vector<int>> &result) {
        path.push_back(node);
        
        if (node == adj.size() - 1) {  
            result.push_back(path);
        } 
        else {
            for (auto neighbor : adj[node]) {
                dfs(neighbor, adj, path, result);
            }
        }
        
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                adj[i].push_back(neighbor);
            }
        }
        vector<vector<int>> result;
        vector<int> path;
        dfs(0, adj, path, result);
        return result;
    }
};
