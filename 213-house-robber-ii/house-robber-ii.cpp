class Solution {
public:
    int rob(vector<int>& val) {
        int n = val.size();
        if (n == 0) return 0;
        if (n == 1) return val[0];

        auto robLinear = [&](vector<int>& vals) {
            int prev = 0, prev2 = 0;
            for (int i = 0; i < vals.size(); i++) {
                int take = vals[i] + prev2;
                int nottake = 0 + prev;
                int curi = max(take, nottake);
                prev2 = prev;
                prev = curi;
            }
            return prev;
        };

        vector<int> case1(val.begin() + 1, val.end());
        vector<int> case2(val.begin(), val.end() - 1);

        return max(robLinear(case1), robLinear(case2));
    }
};
