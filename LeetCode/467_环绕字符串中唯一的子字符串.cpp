// 467_环绕字符串中唯一的子字符串.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int k = 0;
        for (size_t i = 0; i < p.length(); ++i) {
            if (i && (p[i] - p[i - 1] + 26) % 26 == 1) { // 字符之差为 1 或 -25
                ++k;
            }
            else {
                k = 1;
            }
            // 状态为以字母x结尾的字符串的最大个数
            dp[static_cast<size_t>(p[i]) - 'a'] = max(dp[static_cast<size_t>(p[i]) - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/unique-substrings-in-wraparound-string/solution/huan-rao-zi-fu-chuan-zhong-wei-yi-de-zi-ndvea/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
