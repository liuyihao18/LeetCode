// 2327_֪�����ܵ�����.cpp
#include "custom.h"
ustd

class Solution {
    int MOD = static_cast<int>(1e9 + 7);
public:
    int peopleAwareOfSecret(size_t n, size_t delay, size_t forget) {
        // dp[i][j] ��ʾ�� i ���� dp[i][j] ���˷������ܹ��� j ��
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (size_t i = 2; i <= n; i++) {
            for (size_t j = n; j > 0; j--) {
                dp[j] = dp[j - 1];
            }
            dp[0] = 0;
            for (size_t k = delay; k < forget; k++) {
                dp[0] = (dp[0] + dp[k]) % MOD;
            }
        }
        int result = 0;
        for (size_t j = 0; j < forget; j++) {
            result = (result + dp[j]) % MOD;
        }
        return result;
    }
};
