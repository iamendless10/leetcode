class Solution {
    int count(int m,int n , int val){
        int c=0;
        for(int i = 1;i<=m;i++){
            // Count elements in the i-th row that are <= val
            c += min(val / i, n);
        }
        return c;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1,high  = m*n,mid = 0;
        while(low< high){
            mid = (low + high)/2;
            int c = count(m,n,mid);
            if (c< k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};