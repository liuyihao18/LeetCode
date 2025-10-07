// 1278_分割回文串_III.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int palindromePartition(string s, int k) {
        size_t n = s.size();
        vector<vector<int>> minOps(n, vector<int>(n, 0)); // minOps[i][j]: [i..j]变成回文字符串所需的最小变换次数

        for (size_t i = n - 1; i != -1; i--) {
            for (size_t j = i + 1; j != n; j++) {
                minOps[i][j] = minOps[i + 1][j - 1] + (s[i] != s[j]);
            }
        }

        vector<vector<int>> dp(k, vector<int>(n, INT_MAX >> 6)); // dp[i][j]: 前j+1个字符(0..j)分解为i+1个不相交的非空的回文串的最少字符数
        for (size_t j = 0; j < n; j++) {
            dp[0][j] = minOps[0][j];
        }
        for (size_t i = 1; i < k; i++) {
            for (size_t j = i; j < n; j++) {
                for (size_t k = 0; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + minOps[k + 1][j]);
                }
            }
        }
        return dp[k - 1][n - 1];
    }
};
