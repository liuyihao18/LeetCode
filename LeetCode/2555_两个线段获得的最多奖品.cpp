// 2555_两个线段获得的最多奖品.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = static_cast<int>(prizePositions.size());
        vector<int> dp(n + 1);  // 右端点不超过 prizePositions[i]，一条长度为 k 的线段最多可以覆盖的奖品的最大数量
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = static_cast<int>(lower_bound(prizePositions.begin(), prizePositions.end(), prizePositions[i] - k) - prizePositions.begin());
            ans = max(ans, i - x + 1 + dp[x]);
            dp[i + 1] = max(dp[i], i - x + 1);
        }
        return ans;
    }
};

