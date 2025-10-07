// 583_两个字符串的删除操作.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    size_t findLCS(string word1, string word2) {
        size_t m = word1.size();
        size_t n = word2.size();
        vector<vector<size_t>> dp(m + 1, vector<size_t>(n + 1));
        for (size_t i = 0; i < m; i++) {
            dp[i][0] = 0;
        }
        for (size_t j = 0; j < n; j++) {
            dp[0][j] = 0;
        }
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        return static_cast<int>(word1.size() + word2.size() - 2 * findLCS(word1, word2));
    }
};