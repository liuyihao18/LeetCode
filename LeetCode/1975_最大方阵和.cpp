// 1975_最大方阵和.cpp
#include "stdafx.h"
ustd

class Solution
{
public:
	long long maxMatrixSum(vector<vector<int>>& matrix)
	{
		const size_t m{matrix.size()}, n{matrix.front().size()};
		int negativeCnt{};
		long long sum{};
		int minimum{ INT_MAX };
		for (size_t i{}; i < m; i++)
		{
			for (size_t j{}; j < n; j++)
			{
				int& num = matrix[i][j];
				if (num < 0)
				{
					negativeCnt++;
					num = -num;
				}
				sum += num;
				minimum = min(minimum, num);
			}
		}
		if (negativeCnt & 1)
		{
			sum -= 2LL * minimum;
		}
		return sum;
	}
};
