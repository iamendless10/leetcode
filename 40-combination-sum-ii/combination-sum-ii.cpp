class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        cc(0, target, candidates, ds, result);
        return result;
    }

private:
    void cc(int ind, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(ds);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            ds.push_back(candidates[i]);
            cc(i + 1, target - candidates[i], candidates, ds, result);
            ds.pop_back();
        }
    }
};
