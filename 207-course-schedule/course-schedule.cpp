class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if(prerequisites.empty()) return true;
    
        int n = prerequisites.size();
        vector<int> ind(numCourses, 0);

        vector<vector<int>> adj(numCourses);

        for (auto& it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);  
            ind[course]++;
        }

        /*for(int i = 0 ; i < n ; i ++){
            for(auto it: prerequisites[i]){
                ind[it]++;
            }
        }*/

        int count = 0;
        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count ++;

            for(auto it: adj[node]){
                ind[it]--;

                if(ind[it] == 0){
                    q.push(it);
                }
            }
        }

        return count == numCourses;

    }
};