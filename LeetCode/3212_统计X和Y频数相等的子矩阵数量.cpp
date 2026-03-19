// 3212_统计X和Y频数相等的子矩阵数量.cpp
#include "stdafx.h"
ustd

#define NUM_TYPE int64_t

#define GET_XY(xName, yName, matrixName, i, j) \
    NUM_TYPE (xName){ (matrixName)[(i)][(j)] >> 32 }; \
    NUM_TYPE (yName){ (matrixName)[(i)][(j)] & 0xfffff };

#define UPDATE_XY(xName, yName, gridName, i, j) \
	(xName) += (gridName)[(i)][(j)] == 'X' ? 1 : 0; \
	(yName) += (gridName)[(i)][(j)] == 'Y' ? 1 : 0;

#define SET_XY(xName, yName, matrixName, i, j) \
    (matrixName)[i][j] = (xName) << 32 | (yName);

#define UPDATE_RESULT(xName, yName, resultName) \
	(resultName) += (xName) > 0 && (xName) == (yName) ? 1 : 0;

class Solution
{
public:
	int numberOfSubmatrices(const vector<vector<char>>& grid)
	{
		const size_t m{grid.size()}, n{grid.front().size()};
		vector counts(m, vector<int64_t>(n, 0));
		int result{0};
		{
			GET_XY(xCount, yCount, counts, 0, 0)
			UPDATE_XY(xCount, yCount, grid, 0, 0)
			SET_XY(xCount, yCount, counts, 0, 0)
			UPDATE_RESULT(xCount, yCount, result)
		}
		for (size_t i{1}; i < m; i++)
		{
			GET_XY(xCount, yCount, counts, i - 1, 0)
			UPDATE_XY(xCount, yCount, grid, i, 0)
			SET_XY(xCount, yCount, counts, i, 0)
			UPDATE_RESULT(xCount, yCount, result)
		}
		for (size_t j{1}; j < n; j++)
		{
			GET_XY(xCount, yCount, counts, 0, j - 1)
			UPDATE_XY(xCount, yCount, grid, 0, j)
			SET_XY(xCount, yCount, counts, 0, j)
			UPDATE_RESULT(xCount, yCount, result)
		}
		for (size_t i{1}; i < m; i++)
		{
			for (size_t j{1}; j < n; j++)
			{
				GET_XY(xCount0, yCount0, counts, i - 1, j - 1)
				GET_XY(xCount1, yCount1, counts, i - 1, j)
				GET_XY(xCount2, yCount2, counts, i, j - 1)
				NUM_TYPE xCount = xCount1 + xCount2 - xCount0;
				NUM_TYPE yCount = yCount1 + yCount2 - yCount0;
				UPDATE_XY(xCount, yCount, grid, i, j)
				SET_XY(xCount, yCount, counts, i, j)
				UPDATE_RESULT(xCount, yCount, result)
			}
		}
		return result;
	}
};
