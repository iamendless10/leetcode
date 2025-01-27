class Solution {
private: 
    void cc(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                cc(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);     
        
   
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                cc(i, adj, vis);
            }
        }
        return count;
    }
};
