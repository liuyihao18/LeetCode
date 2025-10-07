// 2338_统计理想数组的数目.cpp
#include "stdafx.h"
ustd

// TLE，题解是组合数学
class Solution {
	int MOD = 1000000007;
public:
    int idealArrays(int n, int maxValue) {
        // dp[i][j]表示长度为i的满足条件的以j为结尾的整数数组数量
        // dp[i + 1][j] = sum(dp[i][k] + 1), for j % k == 0
        // dp[0][0..maxValue] = 0
        // dp[1][0] = 0
        // dp[1][1..maxValue] = 1
		vector<vector<int>> dp(n + 1, vector<int>(maxValue + 1, 0));
        for (int j = 0; j <= maxValue; j++) {
            dp[0][j] = 0;
        }
        dp[1][0] = 0;
		for (int j = 1; j <= maxValue; j++) {
			dp[1][j] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= maxValue; j++) {
				for (int k = j; k <= maxValue; k += j) {
					dp[i][j] = (dp[i][j] + dp[i - 1ULL][k]) % MOD;
				}
			}
		}
		int ans = 0;
		for (int j = 1; j <= maxValue; j++) {
			ans = (ans + dp[n][j]) % MOD;
		}
		return ans;
    }
};
