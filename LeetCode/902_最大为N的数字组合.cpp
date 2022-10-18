// 902_最大为N的数字组合.cpp
#include "custom.h"
ustd

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        size_t m = digits.size(), k = s.size();
        vector<vector<int>> dp(k + 1, vector<int>(2));
        dp[0][1] = 1;
        for (size_t i = 1; i <= k; i++) {
            for (size_t j = 0; j < m; j++) {
                if (digits[j][0] == s[i - 1]) {
                    dp[i][1] = dp[i - 1][1];
                }
                else if (digits[j][0] < s[i - 1]) {
                    dp[i][0] += dp[i - 1][1];
                }
                else {
                    break;
                }
            }
            if (i > 1) {
                dp[i][0] += (int)m + dp[i - 1][0] * (int)m;
            }
        }
        return dp[k][0] + dp[k][1];
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/numbers-at-most-n-given-digit-set/solution/zui-da-wei-n-de-shu-zi-zu-he-by-leetcode-f3yi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
