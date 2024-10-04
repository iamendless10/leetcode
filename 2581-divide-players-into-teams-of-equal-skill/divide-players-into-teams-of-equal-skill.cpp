class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
      
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        int l = 0 , r = n-1;
        long long ans = 0;
        long long target = skill[l] + skill[r];
        while(l < n){
            if(skill[l] + skill[r] == target){
                ans += skill[l] * skill[r];
                l++;
                r--;
            }
            else{
                return -1;
            }
        }
        return (long long)ans/2;
    }
};
