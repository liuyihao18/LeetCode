// 1594_矩阵的最大非负积.cpp
#include "stdafx.h"
ustd

class Solution {
public:
	int maxProductPath(const vector<vector<int>>& grid) {
		const size_t m = grid.size(), n = grid.front().size();
		constexpr int remainder = static_cast<int>(1e9 + 7);
		vector dp(m, vector<pair<int64_t, int64_t>>(n, { INT_MIN, INT_MIN }));
		if (grid[0][0] >= 0)
		{
			dp[0][0].first = grid[0][0];
			dp[0][0].second = -1;
		}
		else
		{
			dp[0][0].first = -1;
			dp[0][0].second = -grid[0][0];
		}
		auto updateFrom = [&dp, &grid](const size_t i, const size_t j, const size_t deltaI, const size_t deltaJ)
			{
				if (grid[i][j] >= 0)
				{
					dp[i][j].first = max(
						dp[i][j].first,
						dp[i - deltaI][j - deltaJ].first * grid[i][j]
					);
					dp[i][j].second = max(
						dp[i][j].second,
						dp[i - deltaI][j - deltaJ].second * grid[i][j]
					);
				}
				else
				{
					dp[i][j].first = max(
						dp[i][j].first,
						dp[i - deltaI][j - deltaJ].second * -grid[i][j]
					);
					dp[i][j].second = max(
						dp[i][j].second,
						dp[i - deltaI][j - deltaJ].first * -grid[i][j]
					);
				}
			};
		for (size_t i = 1; i < m; i++)
		{
			updateFrom(i, 0, 1, 0);
		}
		for (size_t j = 1; j < n; j++)
		{
			updateFrom(0, j, 0, 1);
		}
		for (size_t i = 1; i < m; i++)
		{
			for (size_t j = 1; j < n; j++)
			{
				updateFrom(i, j, 1, 0);
				updateFrom(i, j, 0, 1);
			}
		}
		return dp[m - 1][n - 1].first < 0 ? -1 : dp[m - 1][n - 1].first % remainder;
	}
};
