// 3567_子矩阵的最小绝对差.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> minAbsDiff(const vector<vector<int>>& grid, const int k) {
        const size_t m = grid.size();
        const size_t n = grid.front().size();
        vector result(m - k + 1, vector<int>(n - k + 1));
        for (size_t i = 0; i < m - k + 1; i++)
        {
			for (size_t j = 0; j < n - k + 1; j++)
			{
				set<int> s;
				for (int ii = 0; ii < k; ii++)
				{
					for (int jj = 0; jj < k; jj++)
					{
						s.insert(grid[i + ii][j + jj]);
					}
				}
				if (s.size() == 1)
				{
					result[i][j] = 0;
					continue;
				}
				int res = INT_MAX;
				auto iterator = s.begin();
				int first = *iterator;
				while (++iterator != s.end())
				{
					const int second = *iterator;
					res = min(res, abs(second - first));
					first = second;
				}
				result[i][j] = res;
			}   
        }
		return result;
    }
};
