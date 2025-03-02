// 132_分割回文串_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minCut(string s) {
        size_t n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));

        for (size_t i = n - 1; i != -1; i--) {
            for (size_t j = i + 1; j != n; j++) {
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && (s[i] == s[j]);
            }
        }

        vector<int> dp(n + 1, INT_MAX); // 长度为i的字符串分割成字符串的最小分割次数
        dp[0] = -1;
        for (size_t i = 1; i <= n; i++) {
            for (size_t j = 0; j < i; j++) {
                if (isPalindrome[j][i - 1]) { // 如果下标[j, i - 1]的子串是回文串
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};
