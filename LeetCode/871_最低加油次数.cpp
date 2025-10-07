// 871_最低加油次数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        size_t n = stations.size();
        vector<long> dp(n + 1);
        dp[0] = startFuel;
        for (size_t i = 0; i < n; i++) {
            for (int j = static_cast<int>(i); j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[static_cast<size_t>(j) + 1] = 
                        max(dp[static_cast<size_t>(j) + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for (size_t i = 0; i <= n; i++) {
            if (dp[i] >= target) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/minimum-number-of-refueling-stops/solution/zui-di-jia-you-ci-shu-by-leetcode-soluti-nmga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
