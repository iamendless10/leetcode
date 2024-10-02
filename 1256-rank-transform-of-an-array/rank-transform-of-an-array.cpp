class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return{};

        set<int> unique_ele(arr.begin(), arr.end());

        unordered_map<int,int> mpp;
        int i = 1;
        for(int ele: unique_ele){
            mpp[ele] = i++;
        }
        vector<int> ans;
        for(int ele: arr){
            ans.push_back(mpp[ele]);
        }

        return ans;
    }
};