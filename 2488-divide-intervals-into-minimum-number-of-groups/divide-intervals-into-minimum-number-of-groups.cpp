class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        int ans = 0;
        map<int,int> m;
        for(auto &x : in){
            m[x[0]]++;
            m[x[1]+1]--;
        }
        int t = 0;
        for(auto &x : m){
            t+=x.second;
            x.second=t;
            // t+=
        }
        for(auto &x : m) ans = max(ans,x.second);
        return ans;
    }
};