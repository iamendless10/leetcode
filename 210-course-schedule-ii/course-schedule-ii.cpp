class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        
        queue<int> q;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        //
        for (auto& it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);  
            indegree[course]++;
        }

       
        /*for(int i = 0 ; i < numCourses ; i++){
            for(auto it: adj[it]){
                indegree[it]++;
            }
        }*/

        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        

        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();


            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return topo.size() == numCourses ? topo : vector<int>{};
    }
};