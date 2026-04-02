// 3418_机器人可以获得的最大金币数.cpp
#include "stdafx.h"
ustd

template <size_t K>
void initialize(vector<vector<array<int, K>>>& dp, const vector<vector<int>>& coins)
{
	const int coin = coins[0][0];
	if (coin >= 0)
	{
		ranges::for_each(dp[0][0], [coin](int& num) { num = coin; });
	}
	else
	{
		ranges::for_each(dp[0][0], [](int& num) { num = 0; });
		dp[0][0][0] = coin;
	}
}

template <size_t K>
void reset(vector<vector<array<int, K>>>& dp, size_t i, size_t j)
{
	ranges::for_each(dp[i][j], [](int& num) { num = INT_MIN; });
}

template <size_t K, bool CompareWithOriginal>
void update(vector<vector<array<int, K>>>& dp, const vector<vector<int>>& coins,
            const size_t i, const size_t j, const size_t di, const size_t dj)
{
	const int coin = coins[i][j];
	if (coin >= 0)
	{
		for (size_t k = 0; k < K; k++)
		{
			if constexpr (CompareWithOriginal)
			{
				dp[i][j][k] = max({
					dp[i][j][k],
					dp[i - di][j - dj][k] + coin
				});
			}
			else
			{
				dp[i][j][k] = dp[i - di][j - dj][k] + coin;
			}
		}
	}
	else
	{
		if constexpr (CompareWithOriginal)
		{
			dp[i][j][0] = max({
				dp[i][j][0],
				dp[i - di][j - dj][0] + coins[i][j]
			});
		}
		else
		{
			dp[i][j][0] = dp[i - di][j - dj][0] + coins[i][j];
		}
		for (size_t k = 1; k < K; k++)
		{
			if constexpr (CompareWithOriginal)
			{
				dp[i][j][k] = max({
					dp[i][j][k],
					dp[i - di][j - dj][k - 1], // 感化
					dp[i - di][j - dj][k] + coins[i][j]
				});
			}
			else
			{
				dp[i][j][k] = max({
					dp[i - di][j - dj][k - 1], // 感化
					dp[i - di][j - dj][k] + coins[i][j]
				});
			}
		}
	}
}

class Solution
{
public:
	int maximumAmount(const vector<vector<int>>& coins)
	{
		size_t m = coins.size(), n = coins.front().size();

		// dp[i][j][k]表示用了k次感化后在(i,j)可以获取的最大金币值
		constexpr size_t K = 3;
		vector dp(m, vector(n, array<int, K>()));

		initialize<K>(dp, coins);
		/*
		auto updateFromUp = []<typename... ArgTypes>(ArgTypes&&... args)
		{
			update<K, false>(std::forward<ArgTypes>(args)..., 1, 0);
		};
		auto updateFromLeft = []<typename... ArgTypes>(ArgTypes&&... args)
		{
			update<K, false>(std::forward<ArgTypes>(args)..., 0, 1);
		};
		*/
		for (size_t i = 1; i < m; i++)
		{
			reset<K>(dp, i, 0);
			update<K, false>(dp, coins, i, 0, 1, 0);
		}
		for (size_t j = 1; j < n; j++)
		{
			reset<K>(dp, 0, j);
			update<K, false>(dp, coins, 0, j, 0, 1);
		}
		for (size_t i = 1; i < m; i++)
		{
			for (size_t j = 1; j < n; j++)
			{
				reset<K>(dp, i, j);
				update<K, false>(dp, coins, i, j, 1, 0);
				update<K, true>(dp, coins, i, j, 0, 1);
			}
		}

		return *ranges::max_element(dp[m - 1][n - 1]);
	}
};
