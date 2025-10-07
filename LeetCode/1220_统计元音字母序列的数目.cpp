// 1220_ͳ��Ԫ����ĸ���е���Ŀ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countVowelPermutation(int n) {
        const int BIGINT = 1000000007;
        vector<int> _dp(5, 1);
        vector<int> dp(5, 1);
        for (int i = 1; i < n; i++) {
            dp[0] = ((_dp[1] + _dp[2]) % BIGINT + _dp[4]) % BIGINT;
            dp[1] = (_dp[0] + _dp[2]) % BIGINT;
            dp[2] = (_dp[1] + _dp[3]) % BIGINT;
            dp[3] = (_dp[2]) % BIGINT;
            dp[4] = (_dp[2] + _dp[3]) % BIGINT;
            _dp = dp;
        }
        int sum = 0;
        for (size_t i = 0; i < dp.size(); i++) {
            sum = (sum + dp[i]) % BIGINT;
        }
        return sum;
    }
};
