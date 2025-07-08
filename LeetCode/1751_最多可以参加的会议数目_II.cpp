// 1751_�����ԲμӵĻ�����Ŀ_II.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // dp[i] ��ʾǰi������ѡ��j������μ�ʱ�������ֵ��
        // dp[i][j] = dp[i - 1][j];  // ���μӵ�i������
        // dp[i][j] = dp[p][j - 1] + value[i];  // �μӵ�i�����飬��Ҫ��λ�μӵ�i������ǰ����ܲμӶ��ٸ�����
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
