// 72_编辑距离.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size();
        size_t n = word2.size();
        // dp[i][j]代表word1前i个字符和word2前j个字符的编辑距离
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (size_t i = 0; i <= m; i++) {
            dp[i][0] = static_cast<int>(i);
        }
        for (size_t j = 0; j <= n; j++) {
            dp[0][j] = static_cast<int>(j);
        }
        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};

/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size();
        size_t n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<vector<size_t>> path(m + 1, vector<size_t>(n + 1, 0));
        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    path[i][j] = (i - 1) << 16 | (j - 1);
                }
                if (dp[i - 1][j] >= dp[i][j]) {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = (i - 1) << 16 | j;
                }
                if (dp[i][j - 1] >= dp[i][j]) {
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = i << 16 | (j - 1);
                }
            }
        }
        string target;
        size_t i = m, j = n;
        while (i > 0 && j > 0) {
            size_t prev_i = path[i][j] >> 16;
            size_t prev_j = path[i][j] & 0xffff;
            if (prev_i < i && prev_j < j) {
                target += word1[prev_i];
            }
            i = prev_i;
            j = prev_j;
        }
        reverse(target.begin(), target.end());
        cout << target << endl;
        return 0;
    }
};
*/
