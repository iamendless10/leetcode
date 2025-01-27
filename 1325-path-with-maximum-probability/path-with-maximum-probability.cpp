class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double, int>> pq;
        int v = edges.size();

        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adj[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            int node = pq.top().second;
            double dis = pq.top().first;
            pq.pop();

            if(node == end_node) return dis;


            for(auto it: adj[node]){
                int adjnode = it.first;
                double weight = it.second;

                if(weight * dis > dist[adjnode]){
                    dist[adjnode] = weight * dis;
                    pq.push({dist[adjnode], adjnode});
                }
                
            }
        }
        return 0.0;
    }
};