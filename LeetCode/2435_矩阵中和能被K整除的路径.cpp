// 2435_矩阵中和能被K整除的路径.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        size_t m = grid.size(), n = grid.front().size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for (size_t i = 1; i < m; i++) {
            for (size_t r = 0; r < k; r++) {
                dp[i][0][r] = dp[i - 1][0][(r - grid[i][0] % k + k) % k];
            }
        }
        for (size_t j = 1; j < n; j++) {
            for (size_t r = 0; r < k; r++) {
                dp[0][j][r] = dp[0][j - 1][(r - grid[0][j] % k + k) % k];
            }
        }
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                for (size_t r = 0; r < k; r++) {
                    dp[i][j][r] = (dp[i - 1][j][(r - grid[i][j] % k + k) % k] + dp[i][j - 1][(r - grid[i][j] % k + k) % k]) % static_cast<int>(1e9 + 7);
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};
