// 730_统计不同回文子序列.cpp
#include "custom.h"
ustd

class Solution {
public:
    const int MOD = static_cast<int>(1e9 + 7);

    int countPalindromicSubsequences(string& s) {
        size_t n = s.size();
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int i = 0; i < n; i++) {
            dp[static_cast<size_t>(s[i]) - 'a'][i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = len - 1; j < n; i++, j++) {
                for (char c = 'a', k = 0; c <= 'd'; c++, k++) {
                    if (s[i] == c && s[j] == c) {
                        dp[k][i][j] = (2LL + dp[0][i + 1][j - 1] + dp[1][i + 1][j - 1] + dp[2][i + 1][j - 1] + dp[3][i + 1][j - 1]) % MOD;
                    }
                    else if (s[i] == c) {
                        dp[k][i][j] = dp[k][i][j - 1];
                    }
                    else if (s[j] == c) {
                        dp[k][i][j] = dp[k][i + 1][j];
                    }
                    else {
                        dp[k][i][j] = dp[k][i + 1][j - 1];
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < 4; i++) {
            res = (res + dp[i][0][n - 1]) % MOD;
        }
        return res;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/count-different-palindromic-subsequences/solution/tong-ji-bu-tong-hui-wen-zi-xu-lie-by-lee-7slg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
