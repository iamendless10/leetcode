class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, k});

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjnode = it.first;
                int dis = it.second;

                if(weight + dis < dist[adjnode]){
                    dist[adjnode] = weight + dis;
                    pq.push({weight + dis, adjnode});
                }
            }
        }

        int maxi = 0;
        for(int i = 1 ; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};