class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> r(n);
        int maxr = 0;
        int maxl = 0;
        int total = 0;
        

        if (n <= 2) return 0;


        for(int i = n - 1; i >= 0 ; i--){
            maxr = max(maxr,arr[i]);
            r[i] = maxr;
        }

        for(int i = 0 ; i < n ; i++){
            maxl = max(maxl,arr[i]);
            total += min(maxl, r[i]) - arr[i];
        }
        return total;
    }
        
};