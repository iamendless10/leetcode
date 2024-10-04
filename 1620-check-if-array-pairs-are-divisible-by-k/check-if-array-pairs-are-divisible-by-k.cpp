class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        int n = arr.size();
        int rem = 0;
        for(int i = 0 ; i<n;i++){
            rem = arr[i] % k;
            if (rem < 0){
                rem += k;
            }
            mpp[rem]++;
        }

        for(auto& [rem , count]: mpp){
            if (rem == 0) {
                if (count % 2 != 0) return false;
            }
            else {
                int complement = k - rem;
                if (mpp[rem] != mpp[complement]) return false;
            }
        }
        return true;
    }
};