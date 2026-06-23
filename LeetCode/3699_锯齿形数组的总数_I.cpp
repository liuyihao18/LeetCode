// 3699_锯齿形数组的总数_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        r = r - l;
        l = 0;
        vector dp(n, vector<array<int, 2>>(r + 1));
        // dp[n][i][0] 以 i 结尾且上升的锯齿形数组的总数
        // dp[n][i][1] 以 i 结尾且下降的锯齿形数组的总数
        // dp[n][i][0] = sum_{j<i}(dp[n-1][j][1]);
        // dp[n][i][1] = sum_{j>i}(dp[n-1][j][0]);
        for (int j = 0; j <= r; j++)
        {
            dp[0][j][0] = 1;
            dp[0][j][1] = 1;
        }
        // TODO: 加上前缀和优化 & 滚动数组优化
        constexpr int remainder = static_cast<int>(1e9 + 7);
        for (int i = 1; i < n; i++)
        {
	        for (int j = 0; j <= r; j++)
	        {
		        for (int k = 0; k < j; k++)
		        {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][1]) % remainder;
		        }
                for (int k = j +1 ; k <= r; k++)
                {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][0]) % remainder;
                }
	        }
        }
        int result = 0;
		for (int j = 0; j<=r;j++)
		{
            result = (result + dp[n - 1][j][0]) % remainder;
            result = (result + dp[n - 1][j][1]) % remainder;
		}
        return result;
    }
};
