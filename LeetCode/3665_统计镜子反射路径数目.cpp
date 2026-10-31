// 3665_统计镜子反射路径数目.cpp
#include "stdafx.h"
ustd

class Solution {
    constexpr static int remainder = static_cast<int>(1e9 + 7);

    enum class Direction
    {
	    Up,
        Left
    };

    template<Direction D>
    int backtrace(const vector<vector<int>>& grid, const vector<vector<int>>& dp,
    	const size_t i, const size_t j)
    {
        if constexpr(D == Direction::Up)
        {
	        if (i == 0)
	        {
                return 0;
	        }
            if (grid[i - 1][j] == 1)
            {
                return backtrace<Direction::Left>(grid, dp, i - 1, j);
            }
            return dp[i - 1][j];
        }
        else if constexpr (D == Direction::Left)
        {
            if (j == 0)
            {
                return 0;
            }
            if (grid[i][j - 1] == 1)
            {
                return backtrace<Direction::Up>(grid, dp, i, j - 1);
            }
            return dp[i][j - 1];
        }
        else
        {
            static_assert(false);
            return 0;
        }
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        const size_t m = grid.size();
        if (m == 0)
        {
            return 0;
        }
        const size_t n = grid.front().size();
        if (n == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (size_t i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
            {
                break;
            }
            dp[i][0] = 1;
        }
    	for (size_t j = 0; j < n; j++)
        {
			if (grid[0][j] == 1)
			{
				break;
			}
            dp[0][j] = 1;
        }
    
        for (size_t i = 1; i < m; i++)
        {
	        for (size_t j = 1; j < n; j++)
	        {
                dp[i][j] = (dp[i][j] + backtrace<Direction::Up>(grid, dp, i, j)) % remainder;
                dp[i][j] = (dp[i][j] + backtrace<Direction::Left>(grid, dp, i, j)) % remainder;
	        }
        }
        return dp[m - 1][n - 1];
    }
};
