// 375_猜数字大小_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int getMoneyAmount(int n) {
        // dp[i][j]记录在可选数字i到j的情况下所需花费的最小数目
        vector<vector<int>> dp(static_cast<size_t>(n), vector<int>(static_cast<size_t>(n), 0));
        _getMoneyAmount(static_cast<size_t>(n), dp, 0, static_cast<size_t>(n) - 1);
        return dp[0][static_cast<size_t>(n) - 1];
    }
    int _getMoneyAmount(size_t n, vector<vector<int>>& dp, size_t i, size_t j) {
        if (i >= j || i >= n || j >= n) {
            return 0;
        }
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        int temp = INT_MAX;
        // 遍历[i, j]中的数作为分割点
        for (size_t k = i; k <= j; k++) {
            temp = min(temp, max(_getMoneyAmount(n, dp, i, k - 1), _getMoneyAmount(n, dp, k + 1, j)) + static_cast<int>(k) + 1);
        }
        dp[i][j] = temp;
        return dp[i][j];
    }
};
