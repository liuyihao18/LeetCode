// 1289_下降路径最小和_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        size_t n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (size_t i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }
        for (size_t i = 1; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                for (size_t k = 0; k < n; k++) {
                    if (k != j) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + grid[i][j]);
                    }
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
