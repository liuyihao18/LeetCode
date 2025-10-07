// 63_²»Í¬Â·¾¶_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (size_t i = 1; i < m; i++) {
            if (obstacleGrid[i][0]) {
                dp[i][0] = 0;
            }
            else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (size_t j = 1; j < n; j++) {
            if (obstacleGrid[0][j]) {
                dp[0][j] = 0;
            }
            else {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (size_t i = 1; i < m; i++) {
            for (size_t j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
