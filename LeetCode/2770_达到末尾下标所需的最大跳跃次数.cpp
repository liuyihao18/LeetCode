// 2770_达到末尾下标所需的最大跳跃次数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	int maximumJumps(const vector<int>& nums, int target) {
		const int n = static_cast<int>(nums.size());
		vector<int> dp(n, INT_MIN); // dp[i] 表示从 0 跳跃到 i 的最大次数
		dp[0] = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (abs(nums[j] - nums[i]) <= target)
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[n - 1] < 0 ? -1 : dp[n - 1];
	}
};
