class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n, 1e9);

        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        q.push({0, {src, 0}});

        while(!q.empty()){
            int stops= q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();
            if (stops > k) continue;
            for(auto it: adj[node]){
                int adjnode = it.first;
                int weight = it.second;

                if(cost + weight < dist[adjnode] && stops <= k){
                    dist[adjnode] = cost + weight;
                    q.push({stops + 1, {adjnode,cost + weight}});
                }
            }

            
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
        
    }
};