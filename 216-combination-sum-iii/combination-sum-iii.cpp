class Solution {
private:
    void cc(int ind, int sum, int k, int target, vector<int> &curr, vector<vector<int>> &res){
        if(curr.size() == k){
            if(sum == target){
                res.push_back(curr);
                return;
            }
            return;
        }

        if(ind > 9) return;

        curr.push_back(ind);
        cc(ind + 1, sum + ind, k, target, curr, res);

        curr.pop_back();
        cc(ind + 1, sum, k, target, curr, res);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> res;

        cc(1, 0, k, n, curr, res);
        return res;
    }
};