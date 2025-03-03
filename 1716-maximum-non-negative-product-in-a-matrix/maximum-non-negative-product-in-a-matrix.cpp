class Solution {
private:
    const int MOD = 1e9+7;

    pair<long long, long long> cc(int i, int j, vector<vector<int>>& grid, vector<vector<long long>>& dpMax, 
vector<vector<long long>>& dpMin, int m, int n) {
    
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }
        if (dpMax[i][j] != LLONG_MIN) {
            return {dpMax[i][j], dpMin[i][j]};
        }

        long long maxProd = LLONG_MIN, minProd = LLONG_MAX;
        long long curVal = grid[i][j];

        if (i + 1 < m) {
            auto [maxDown, minDown] = cc(i + 1, j, grid, dpMax, dpMin, m, n);
            maxProd = max(maxProd, max(maxDown * curVal, minDown * curVal));
            minProd = min(minProd, min(maxDown * curVal, minDown * curVal));
        }
        if (j + 1 < n) {
            auto [maxRight, minRight] = cc(i, j + 1, grid, dpMax, dpMin, m, n);
            maxProd = max(maxProd, max(maxRight * curVal, minRight * curVal));
            minProd = min(minProd, min(maxRight * curVal, minRight * curVal));
        }
        dpMax[i][j] = maxProd;
        dpMin[i][j] = minProd;

        return {maxProd, minProd};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dpMax(m, vector<long long>(n, LLONG_MIN));
        vector<vector<long long>> dpMin(m, vector<long long>(n, LLONG_MAX));

        long long result = cc(0, 0, grid, dpMax, dpMin, m, n).first;

        return (result < 0) ? -1 : result % MOD;
    }
};
