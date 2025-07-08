// 1751_最多可以参加的会议数目_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // dp[i] 表示前i个会议选择j个会议参加时候的最大价值和
        // dp[i][j] = dp[i - 1][j];  // 不参加第i个会议
        // dp[i][j] = dp[p][j - 1] + value[i];  // 参加第i个会议，需要定位参加第i个会议前最多能参加多少个会议
        sort(events.begin(), events.end(),
            [](const vector<int>& event1, const vector<int>& event2) {
                return event1[1] < event2[1];
            }
        );
        size_t n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (size_t i = 1; i <= n; i++) {
            int p = lower_bound(events.begin(), events.end(), events[i - 1],
                [](const vector<int>& event, const vector<int>& target) {
                    return event[1] < target[0];
                }
            ) - events.begin();
            for (size_t j = 1; j <= k; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[p][j - 1] + events[i - 1][2]);
            }
        }
        return dp[n][k];
    }
};
