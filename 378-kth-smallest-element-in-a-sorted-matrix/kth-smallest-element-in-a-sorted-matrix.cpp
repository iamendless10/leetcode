class Solution {
    int count(vector<vector<int>> &matrix, int val){
        int c = 0,lb=0;
        int row = matrix.size();
        for(int i =0 ; i< row;i++){
            lb = upper_bound(matrix[i].begin(),matrix[i].end(),val)-matrix[i].begin();
            c += lb;
        }
        return c;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0] , r = matrix[n-1][n-1],mid = 0;
        while(l < r){
            mid = l+(r-l)/2;
            int c = count(matrix, mid);
            if (c < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};