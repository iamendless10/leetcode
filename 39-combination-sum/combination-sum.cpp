class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> result;

        cc(0, 0, target, candidates, ds, result, n);
        return result;
    }

private:

    void cc(int ind, int sum, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &result, int n){
        if(sum == target){
            result.push_back(ds);
            return;
        }

        if (ind >= candidates.size() || sum > target) {
            return;
        }

        
        ds.push_back(candidates[ind]);
        cc(ind, sum + candidates[ind], target, candidates, ds, result,n);

        ds.pop_back();
        cc(ind + 1, sum, target, candidates, ds, result,n);
    }
};