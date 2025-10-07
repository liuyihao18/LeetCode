// 926_将字符串翻转到单调递增.cpp
#include "stdafx.h"
ustd

// TODO: 经典DP
class Solution {
public:
    int minFlipsMonoIncr(string& s) {
        // dp[i][j]表示长度为i的字符串最后一个字符翻转成j且满足题设的最小次数
        int dp0 = 0, dp1 = 0;
        for (char c : s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') {
                dp0New++;
            }
            else {
                dp1New++;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/flip-string-to-monotone-increasing/solution/jiang-zi-fu-chuan-fan-zhuan-dao-dan-diao-stjd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
